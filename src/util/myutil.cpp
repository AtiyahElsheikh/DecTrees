/*    
 Copyright (C) Atiyah Elsheikh (Atiyah.Elsheikh@ait.ac.at,a.m.g.Elsheikh@gmail.com) 2010-2013, AIT Austrian Institute of Technology GmbH

    This file is part of the software DecTrees and InteractiveMneus

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
*/

/**
 * \file myutil.cpp 
 * \copydoc myutil.h  
 * 
 * @autodate
 */



#ifndef MYUTIL_CPP
#define MYUTIL_CPP

#include "myutil.h"



bool Myutil::second_ = false;

double Myutil::x1_ = 0; 
double Myutil::x2_ = 0;

/**
 *
 */
int Myutil::file_exists(const char *filename)
{
    FILE* file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
}



#ifndef NOREGEX_H
/**
 * Tokenize a string 
 * @param string 
 * @param resulting tokens as regular expressions
 * @param delimiters 
 */ 
void Myutil::Tokenize(const string& str,
		      vector<regex_t>& tokens,
		      const string& delimiters) { 
 
  vector<string> strtoks; 
  Tokenize(str,tokens,strtoks,delimiters);

}
#endif


/**
 *
 */
void Myutil::Tokenize(const string& str,
		      vector<string>& tokens,
		      const string& delimiters)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}


/**
 *
 */
void Myutil::Tokenize(const string& str,
		      set<string>& tokens,
		      const string& delimiters)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.insert(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}



/**
 * generate a rondom number between 0 .. hi
 */    
int Myutil::randomnumber(int hi)  //the correct random number generator for [0,hi]
{
  // scale in range [0,1)
  const float scale = rand()/float(RAND_MAX);
  
  // return range [0,hi]
  return int(scale*hi + 0.5); // implicit cast and truncation in return
}


/**
 * Generate a rondom vector which lies between pmin & pmax 
 */
vector<double> Myutil::randomvector(const vector<double>& pmin,
			    const vector<double>& pmax) { 
  vector<double> ret; 
  ret.resize(pmin.size());
  for(int i=0;i<pmin.size();i++) { 
    ret[i] = pmin[i] + (pmax[i]-pmin[i])*randomnumber(1e5)/1.0e5;
  }
  return ret; 
}




/** 
 * generate random number in the N(0,1)
 * @remark from Michael Weitzel
 */
double Myutil::randn01() 
{ 
  
  double r, s, v1, v2;
  if (second_)
    {
      second_ = false;
      return x2_;
    }
  else
    {
      do
	{
	  v1 = 2. * randomnumber(1e6)/(1.0e6)  - 1.;
	  v2 = 2. * randomnumber(1e6)/(1.0e6)  - 1.;
	  s = v1*v1+v2*v2;
	}
      while (s >= 1. || s == 0.);
      r   = sqrt(-2.*log(s)/s);
      x2_ = v2 * r;
      second_ = true;
      return v1 * r;
    }
}


/**
 * export a vector in csv-data
 * @param file name 
 * @param names 
 * @param corresponding values 
 */ 
void Myutil::exportCSV(const string& fname,
		       const vector<string>& names,
		       const vector<double>& arr) { 

  assert(names.size()== arr.size());
 
  ofstream csvfile;
  csvfile.open(fname.c_str());
  
  for(int i=0;i<names.size()-1;i++) { 
    csvfile << names[i] << ",";
  }
  csvfile <<  names[names.size()-1] << "\n";
 
  for(int i=0;i<arr.size()-1;i++) { 
    csvfile << arr[i] << ","; 
  }
  csvfile <<  arr[arr.size()-1] << "\n";

  csvfile.close();

}


/**
 * export a vector in csv-data
 * @param file name 
 * @param names 
 * @param corresponding values 
 */ 
void Myutil::exportCSV(const string& fname,
		       const vector<string>& names,
		       const vector<double>& arr1,
		       const vector<double>& arr2) { 

  assert(names.size()== arr1.size());
  assert(arr1.size()== arr2.size());
 
  ofstream csvfile;
  csvfile.open(fname.c_str());
  
  for(int i=0;i<names.size()-1;i++) { 
    csvfile << names[i] << ",";
  }
  csvfile <<  names[names.size()-1] << "\n";
 
  for(int i=0;i<arr1.size()-1;i++) { 
    csvfile << arr1[i] << ","; 
  }
  csvfile <<  arr1[arr1.size()-1] << "\n";

  for(int i=0;i<arr2.size()-1;i++) { 
    csvfile << arr2[i] << ","; 
  }
  csvfile <<  arr2[arr2.size()-1] << "\n";

  csvfile.close();

}

/**
 * export a vector in csv-data
 * @param file name 
 * @param names 
 * @param corresponding values 
 */ 
void Myutil::exportCSV(const string& fname,
		       const vector<string>& names,
		       const vector< vector<double> >& arr2d)  {  

  int n = arr2d.size();
  assert(n >  0);
  assert(names.size()== arr2d[0].size());
  
 
  ofstream csvfile;
  csvfile.open(fname.c_str());
  
  for(int i=0;i<names.size()-1;i++) { 
    csvfile << names[i] << ",";
  }
  csvfile <<  names[names.size()-1] << "\n";

  for(int i=0;i<n;i++) { 
    for(int j=0;j<arr2d[i].size()-1;j++) { 
      csvfile << arr2d[i][j] << ","; 
    }
    csvfile <<  arr2d[i][arr2d[i].size()-1] << "\n";
  }
  
}


/**
 * export a vector in csv-data
 * @param file name 
 * @param first array values  
 * @param second array value 
 */ 
void Myutil::exportCSV(const string& fname,
		       const vector<double>& arr1,
		       const vector<double>& arr2) { 

  cout << fname << " generated \n"; 
  assert(arr1.size()== arr2.size());
 
  ofstream csvfile;
  csvfile.open(fname.c_str());

  for(int i=0;i<arr1.size()-1;i++) { 
    csvfile << arr1[i] << ","; 
  }
  csvfile <<  arr1[arr1.size()-1] << "\n";

  for(int i=0;i<arr2.size()-1;i++) { 
    csvfile << arr2[i] << ","; 
  }
  csvfile <<  arr2[arr2.size()-1] << "\n";

  csvfile.close();
}



/**
 * export a matrix in csv-data
 * @param file name 
 * @param number of rows
 * @param number of cols 
 * @param a 1-D Array matrix  
 */ 
void Myutil::exportCSV(const string& fname,
		       int nrows,
		       int ncols,
		       const double* arr2d) { 

  ofstream csvfile;
  csvfile.open(fname.c_str());
  
 
  for(int i=0;i<nrows;i++) {
    for(int j=0;j<ncols-1;j++) { 
      csvfile << arr2d[i*ncols+j] << ","; 
    }
    csvfile << arr2d[i*ncols+ncols-1] << "\n";
  }

  csvfile.close();
}



/**
 * export a referenced matrix in csv format
 */
void Myutil::exportTCSV(const string& fname,
			int nrows,
			int ncols,
			vector<string> refs,
			double** arr2d) { 

  assert(refs.size() == nrows); 
  
  ofstream csvfile;
  csvfile.open(fname.c_str());
  
  for(int i=0;i<nrows;i++) 
    csvfile << refs[i]  << ",";
  csvfile << "\n"; 


  for(int j=0;j<ncols;j++) { 
    for(int i=0;i<nrows-1;i++) {
      csvfile << arr2d[i][j] << ","; 
    }
    csvfile << arr2d[nrows-1][j] << "\n";
  }

  csvfile.close();
}


/**
 *
 */
void Myutil::find_and_replace(string &source, 
		      const string& find, 
		      const string& replace ) {
  size_t j;
  for ( ; (j = source.find( find )) != string::npos ; ) {
    source.replace( j, find.length(), replace );
  }   
}


/**
 *
 */
double Myutil::norm2(const vector<double>& vec1,
		     const vector<double>& vec2) { 
  assert(vec1.size() == vec2.size());
  double t,sum = 0;
  for(int i=0;i<vec1.size();i++)
    sum += (t = vec1[i] - vec2[i])*t; 
  return sum; 
}

#endif
