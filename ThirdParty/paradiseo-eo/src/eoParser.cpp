// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

//-----------------------------------------------------------------------------
// eoParser.cpp
// (c) Marc Schoenauer, Maarten Keijzer and GeNeura Team, 2000
/*
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact: todos@geneura.ugr.es, http://geneura.ugr.es
             Marc.Schoenauer@inria.fr
             mkeijzer@dhi.dk
 */
//-----------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif

#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <iomanip>

#include <utils/compatibility.h>

#include <utils/eoParser.h>

using namespace std;

void eoWarning(std::string str)
{
    cout << str << '\n';
}

std::ostream& printSectionHeader(std::ostream& os, std::string section)
{
    if (section == "")
        section = "General";

    os << '\n' << setw(10) << "######    " << setw(20) << section << setw(10) << "    ######\n";
    return os;
}

eoParameterLoader::~eoParameterLoader()
{
    for (unsigned i = 0; i < ownedParams.size(); ++i)
    {
        delete ownedParams[i];
    }
}


eoParser::eoParser ( unsigned _argc, char **_argv , string _programDescription,
                     string _lFileParamName, char _shortHand) :
    programName(_argv[0]),
    programDescription( _programDescription),
    needHelp(false, "help", "Prints this message", 'h'),
    stopOnUnknownParam(true, "stopOnUnknownParam", "Stop if unkown param entered", '\0')
{
    // need to process the param file first
    // if we want command-line to have highest priority
    unsigned i;
    for (i = 1; i < _argc; ++i)
    {
	if(_argv[i][0] == '@')
        { // read response file
	    char *pts = _argv[i]+1; // yes a char*, sorry :-)
	    ifstream ifs (pts);
	    ifs.peek(); // check if it exists
	    if (!ifs)
            {
		string msg = string("Could not open response file: ") + pts;
		throw runtime_error(msg);
            }
	    // read  - will be overwritten by command-line
	    readFrom(ifs);
	    break; // stop reading command line args for '@'
        }
    }
    // now read arguments on command-line
    stringstream stream;
    for (i = 1; i < _argc; ++i)
    {
        stream << _argv[i] << '\n';
    }
    readFrom(stream);
    processParam(needHelp);
    processParam(stopOnUnknownParam);
}



eoParam * eoParser::getParamWithLongName(const std::string& _name) const
{
    typedef std::multimap<std::string, eoParam*> MultiMapType;
    typedef MultiMapType::const_iterator iter;
    std::string search(prefix+_name);
    for(iter p = params.begin(); p != params.end(); ++p)
        if(p->second->longName() == search)
            return p->second;
    return 0;
}



void eoParser::processParam(eoParam& param, std::string section)
{
    // this param enters the parser: add the prefix to the long name
    if (prefix != "")
    {
	param.setLongName(prefix+param.longName());
	section = prefix + section;  // and to section
    }
    doRegisterParam(param); // plainly register it
    params.insert(make_pair(section, &param));
}

void eoParser::doRegisterParam(eoParam& param) const
{
    if (param.required() && !isItThere(param))
    {
        string msg = "Required parameter: " + param.longName() + " missing";
        messages.push_back(msg);
    }
    pair<bool, string> value = getValue(param);
    if (value.first)
    {
        param.setValue(value.second);
    }
}

pair<bool, string> eoParser::getValue(eoParam& _param) const
{
    pair<bool, string> result(false, "");

    if (_param.shortName() != 0)
    {
        map<char, string>::const_iterator it = shortNameMap.find(_param.shortName());
        if (it != shortNameMap.end())
        {
            result.second = it->second;
            result.first = true;
            return result;
        }
    }
    map<string, string>::const_iterator it = longNameMap.find(_param.longName());
    if (it != longNameMap.end())
    {
        result.second = it->second;
        result.first = true;
        return result;
    }
    // else (TODO: check environment, just long names)
    return result;
}

void eoParser::updateParameters() const
{
 typedef MultiMapType::const_iterator It;

  for (It p = params.begin(); p != params.end(); ++p)
  {
        doRegisterParam(*p->second);
  }
}

void eoParser::readFrom(istream& is)
{
    string str;
    // we must avoid processing \section{xxx} if xxx is NOT "Parser"
    bool processing = true;
    while (is >> str)
    {
        if (str.find(string("\\section{"))==0) // found section begin
            processing = (str.find(string("Parser"))<str.size());

        if (processing)		// right \section (or no \section at all)
	{
            if (str[0] == '#')
	    { // skip the rest of the line
                string tempStr;
                getline(is, tempStr);
	    }
            if (str[0] == '-')
	    {
                if (str.size() < 2)
		{
                    eoWarning("Missing parameter");
                    needHelp.value() = true;
                    return;
		}

                if (str[1] == '-') // two consecutive dashes
		{
                    string::iterator equalLocation = find(str.begin() + 2, str.end(), '=');
                    string value;

                    if (equalLocation == str.end())
		    { // TODO: it should be the next string
                        value = "";
		    }
                    else
		    {
                        value = string(equalLocation + 1, str.end());
		    }

                    string name(str.begin() + 2, equalLocation);
                    longNameMap[name] = value;
		}
                else // it should be a char
		{
                    string value = "1"; // flags do not need a special

                    if (str.size() >= 2)
		    {
                        if (str[2] == '=')
			{
                            if (str.size() >= 3)
                                value = string(str.begin() + 3, str.end());
			}
                        else
			{
                            value = string(str.begin() + 2, str.end());
			}
		    }

                    shortNameMap[str[1]] = value;
		}
	    }
	}
    }

    updateParameters();
}

void eoParser::printOn(ostream& os) const
{
    typedef MultiMapType::const_iterator It;

    It p = params.begin();

    std::string section = p->first;

    printSectionHeader(os, section);
    //print every param with its value
    for (; p != params.end(); ++p)
      {
        std::string newSection = p->first;

        if (newSection != section)
        {
            section = newSection;
            printSectionHeader(os, section);
        }

        eoParam* param = p->second;

	if (!isItThere(*param))  // comment out the ones not set by the user
	  os << "# ";

        string str = "--" + param->longName() + "=" + param->getValue();

        os.setf(ios_base::left, ios_base::adjustfield);
        os << setw(40) << str;

        os << setw(0) << " # ";
        if (param->shortName())
            os << '-' << param->shortName() << " : ";
        os << param->description();

        if (param->required())
        {
            os << " REQUIRED ";
        }

        os  << '\n';
    }
}

void eoParser::printHelp(ostream& os)
{
    if (needHelp.value() == false && !messages.empty())
    {
        std::copy(messages.begin(), messages.end(), ostream_iterator<string>(os, "\n"));
        messages.clear();
        return;
    }

    // print program name and description
    os << this->programName <<": "<< programDescription << "\n\n";

    // print the usage when calling the program from the command line
    os << "Usage: "<< programName<<" [Options]\n";
    // only short usage!
    os << "Options of the form \"-f[=Value]\" or \"--Name[=value]\"" << endl;

    os << "Where:"<<endl;

    typedef MultiMapType::const_iterator It;

    It p = params.begin();

    std::string section = p->first;

    printSectionHeader(os, section);

    //print every param with its value
    for (; p != params.end(); ++p)
    {
        std::string newSection = p->first;

        if (newSection != section)
        {
            section = newSection;
            printSectionHeader(os, section);
        }

        if (p->second->shortName())
	        os << "-" << p->second->shortName() << ", ";

        os << "--" <<p->second->longName() <<":\t"
	     << p->second->description() ;

	  os << "\n" << setw(20) << ( (p->second->required())?"Required":"Optional" );
      os <<". By default: "<<p->second->defValue() << '\n';
    } // for p

    os << "\n@param_file \t defines a file where the parameters are stored\n";
    os << '\n';

}

bool eoParser::userNeedsHelp(void)
{
  /*
     check whether there are long or short names entered
     without a corresponding parameter
  */
  // first, check if we want to check that !
  if (stopOnUnknownParam.value())
    {
      for (LongNameMapType::const_iterator lIt = longNameMap.begin(); lIt != longNameMap.end(); ++lIt)
	{
	  string entry = lIt->first;

	  MultiMapType::const_iterator it;

	  for (it = params.begin(); it != params.end(); ++it)
	    {
	      if (entry == it->second->longName())
		{
		  break;
		}
	    }

	  if (it == params.end())
	    {
	      string msg = "Unknown parameter: --" + entry + " entered, type -h or --help to see available parameters";
	      messages.push_back(msg);
	    }
	}

      for (ShortNameMapType::const_iterator sIt = shortNameMap.begin(); sIt != shortNameMap.end(); ++sIt)
	{
	  char entry = sIt->first;

	  MultiMapType::const_iterator it;

	  for (it = params.begin(); it != params.end(); ++it)
	    {
	      if (entry == it->second->shortName())
		{
		  break;
		}
	    }

	  if (it == params.end())
	    {
	      string entryString(1, entry);
	      string msg = "Unknown parameter: -" + entryString + " entered, type -h or --help to see available parameters";
	      messages.push_back(msg);
	    }
	}
    }
  return needHelp.value() || !messages.empty();
}

///////////////// I put these here at the moment
ostream & operator<<(ostream & _os, const eoParamParamType & _rate)
{
  _rate.printOn(_os);
  return _os;
}

istream & operator>>(istream & _is,  eoParamParamType & _rate)
{
  _rate.readFrom(_is);
  return _is;
}

