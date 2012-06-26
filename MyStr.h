#ifndef MYSTR_H
#define MYSTR_H
#include <string>
#include <iostream>
#include <sstream>

class myStr {
public:
  template<class T>
  myStr(T w) {
    std::stringstream ss;
    ss << w;
    word = ss.str();
  }

  myStr(S a, S b) {
    S temp = a + b;
    word = temp.str();
  }

  S operator + (S param) {
    string str = word + param.get();
    return S(str);
  }

  string str() {
    return word;
  }
private:
  std::string word;
};

//string make(myStr word) {
//  return word.str();
//}

//class myStr {
//public:
//  myStr();
//};

#endif // MYSTR_H
