/*    
 Copyright (C) Atiyah Elsheikh, Michael Weitzel (Atiyah.Elsheikh@ait.ac.at,a.m.g.Elsheikh@gmail.com) 2010-2013, AIT Austrian Institute of Technology GmbH 

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
 * \file myutil.h
 * \class Myutil provides several utilities 
 * Several utility routines  
 * 
 * @author      Atiyah Elsheikh 
 */


#ifndef MYUTIL_H
#define MYUTIL_H

using namespace std;

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<cassert>
#include<iostream>
#ifndef NOREGEX_H
#include<regex.h>
#endif
#include<cstdlib>
#include<cmath>



class Myutil { 


 private:

  /// help variables for the routine rand01()
  static bool second_;
  static double x1_; 
  static double x2_;


 public:
  /**
   * whether file exists 
   * @param the name of file
   */ 
  static int file_exists(const char *filename);

  /**
   * Whether files exists 
   */ 
  static inline int file_exists(string filename) { 
    return file_exists(filename.c_str());
  }

#ifndef NOREGEX_H
  /**
   * Tokenize a string 
   * @param string 
   * @param resulting tokens as regular expressions
   * @param delimiters
   * @param resulting tokens as strings  
   */ 
  template<typename T>
    static void Tokenize(const string& str,
			 vector<regex_t>& tokens,
			 T& strtoks,
			 const string& delimiters = " ");

  /**
   * Tokenize a string 
   * @param string 
   * @param resulting tokens as regular expressions
   * @param delimiters
   * @param resulting tokens as strings  
   */ 
  static void Tokenize(const string& str,
		       vector<regex_t>& tokens,
		       const string& delimiters = " ");
#endif


  /**
   * Tokenize a string 
   * @param string 
   * @param resulting tokens 
   * @param delimiters 
   */ 
  static void Tokenize(const string& str,
		       vector<string>& tokens,
		       const string& delimiters = " ");

  /**
   * Tokenize a string 
   * @param string 
   * @param resulting tokens 
   * @param delimiters 
   */ 
  static void Tokenize(const string& str,
		       set<string>& tokens,
		       const string& delimiters = " ");

#ifndef NOREGEX_H  
  /**
   * match a collection of identities to given collection of regular expressions 
   * @param vector of regular expressions
   * @param vector of identities 
   * @param a set of matched identities
   * @param a map of the matched ids to the index of the first matching reg. exp.  
   */ 
  template<typename T>
    static void match(const vector<regex_t>& regexp,
		      const vector<string>& names,
		      T& res,
		      map<string,int>& resmap);


  
  /**
   * match a collection of identities to given collection of regular expressions 
   * @param a regular expression
   * @param vector of identities 
   * @param a set of matched identities
   * @param a map of the matched ids to the index of the first matching reg. exp.  
   */ 
  template<typename T>
    static void match(const regex_t& regexp,
		      const vector<string>& names,
		      T& res);
#endif
  

  /**
   * generate a random integer between 0 and n
   * @param  upper bound 
   * @return random integer 
   */ 
  static int randomnumber(int hi);

  /**
   * generate a random vector accoarding to a uniform dist. 
   * @param  lower bound 
   * @param  upper bound 
   * @return vector values 
   */ 
  static vector<double> randomvector(const vector<double>& pmin,
			    const vector<double>& pmax);


  /** 
   * generate random number in the N(0,1)
   * @return x in N(0,1)
   */
  static double randn01(); 


  /**
   * random number in N(mu,sig)
   * @return x in N(mu,sig)
   */
  static inline double randn(double mu,double sig) { 
    return randn01()*sig+mu;
  } 


  /**
   * advanced version of assert
   * @param boolean expresion
   * @param error message 
   */ 
  static inline void myassert(bool expr,const char* errmsg) { 
    if(!expr) { 
      cerr << "ERROR: " << errmsg << "\n";
      assert(expr);
    }
  }

  /**
   * advanced version of assert
   * @param boolean expresion
   * @param error message 
   */ 
  static inline void myassert(bool expr,const string& errmsg) { 
    myassert(expr,errmsg.c_str());
  }

  /**
   * Whether a == b
   * @param number 
   * @param number 
   * @return a == b? 
   */
  static inline bool equal(double a,double b) { 
    //return ((a < b+1e-10) && (b < a+1e-10)); 
    return (abs(a-b)<1e-10);
  }


  /**
   * export a vector in csv-data
   * @param file name 
   * @param names 
   * @param corresponding values 
   */ 
  static void exportCSV(const string& fname,
			const vector<string>& names,
			const vector<double>& arr);

  /**
   * export a vector in csv-data
   * @param file name 
   * @param names 
   * @param corresponding values 
   */ 
  static void exportCSV(const string& fname,
			const vector<string>& names,
			const vector< vector<double> >& arr2d); 


  /**
   * export a vector in csv-data
   * @param file name 
   * @param names 
   * @param corresponding 1st row
   * @param corresponding 2nd row
   */ 
  static void exportCSV(const string& fname,
			const vector<string>& names,
			const vector<double>& arr1,
			const vector<double>& arr2); 


  /**
   * export a vector in csv-data
   * @param file name 
   * @param first array values  
   * @param second array value 
   */ 
  static void exportCSV(const string& fname,
			const vector<double>& arr1,
			const vector<double>& arr2);


  /**
   * export a matrix in csv-data
   * @param file name 
   * @param number of rows
   * @param number of cols 
   * @param a 1-D Array matrix  
   */ 
  static void exportCSV(const string& fname,
			int nrows,
			int ncols,
			const double* arr2d); 

  /**
   * export a referenced matrix in csv format
   * @param file name 
   * @param number of rows
   * @param number of cols 
   * @param refs first row 
   * @param a 1-D Array matrix  
   */ 
  static void exportTCSV(const string& fname,
		  int nrows,
		  int ncols,
		  vector<string> refs,
		  double** arr2d); 


  /**
   * find a substring in a string and replace it with another substring
   * @param I/O source
   * @param the substring to get replaced
   * @param the substring to get replaced with
   */
  static void find_and_replace(string &source, 
			       const string& find, 
			       const string& replace);

  /**
   * the norm-square of 2 vectors of identical length 
   * @param first  vector
   * @param second vector 
   */ 
  static double norm2(const vector<double>& vec1,
		      const vector<double>& vec2);

}; 


#ifndef NOREGEX_H
/**
 *
 */
template<typename T>
void Myutil::match(const vector<regex_t>& regexp,
		   const vector<string>& names,
		   T& res,
		   map<string,int>& resmap) { 
   
  res.clear(); 
  resmap.clear(); 

  vector<bool> used(regexp.size(),false);
  bool diff; 
  for(int i=0;i<names.size();i++) { 
    diff = true; 
    for(int j=0;j<regexp.size() && diff;j++) { 
      diff = regexec(&regexp[j],names[i].c_str(),0,NULL,0) != 0;
      used[j] = diff? used[j]:true; 
      if(!diff) { 
	res.insert(names[i]);
	resmap.insert(make_pair(names[i],j));
	continue; 
      } 
    }     
  }

}



/**
 *
 */
template<typename T>
void Myutil::match(const regex_t& regexp,
		   const vector<string>& names,
		   T& res) { 
   
  res.clear(); 
  bool diff; 
  for(int i=0;i<names.size();i++) { 
    diff = regexec(&regexp,names[i].c_str(),0,NULL,0) != 0;
    if(!diff) res.push_back(names[i]);
  }     
  
}



/**
 * Tokenize a string 
 * @param string 
 * @param resulting tokens as regular expressions
 * @param delimiters 
 * @param resulting tokens as strings
 */ 
template<typename T>
void Myutil::Tokenize(const string& str,
		      vector<regex_t>& tokens,
		      T& strtoks,
		      const string& delimiters) { 
 
  Tokenize(str,strtoks,delimiters);
  tokens.resize(strtoks.size()); 
  for(int i=0;i<strtoks.size();i++) { 
    int ret = regcomp(&tokens[i],strtoks[i].c_str(),REG_EXTENDED);
    assert(!ret); 
  }

}
#endif


#endif 
