#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  string buffer;
  string finalString = "";
  rawWords = convToLower(rawWords);
  //cout << rawWords << endl;
  stringstream ss(rawWords);
  // create a set
  std::set <string> finalSet;

  while(ss>>buffer){
    int count = 0;
    for(int i=0; i<buffer.size(); i++){
      // count each letter
      if(!ispunct(buffer[i])){
        finalString+=buffer[i];        
      }
      else{
        break;
      }        
    }
    if(finalString.length()>=2){
      finalSet.insert(finalString);
      count ++;
    }
    finalString = "";
      //check length of substring before returning 
  }    
  

/*if (!finalString.empty() && finalString.length() >= 2) {
  finalSet.insert(finalString);
}*/

  
  return finalSet;  
    
  }










/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

