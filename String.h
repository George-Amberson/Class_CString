#pragma once
#include<iostream>

using namespace std;

class CString{
public:
  CString();

  CString(char b, int leng);

  CString(const char* cstr);

  CString(CString& a);

  ~CString();

  char* get_s()
  { 
    return init;
  }
  int get_l()
  { 
    return length;
  }
  void set_s(const char*s);

  friend CString operator +(CString& a, CString &b);

  CString& operator =(const CString&a);

  void complete(CString& a, CString &b)
  {
  
    init = new char[a.get_l() + 1+b.get_l()];
    length = a.get_l()  + b.get_l();
    size = a.get_l() + 1 + b.get_l();
    for ( int i = 0; i < a.get_l(); i++) init[i] = a.get_s()[i];
    for ( int i = 0; i < b.get_l(); i++) init[i+a.get_l()] = b.get_s()[i];
    init[a.get_l() + b.get_l()] = 0;
  }

  friend bool operator == (CString &a, CString &b);

  friend bool operator <(CString &a,CString&b);

  friend bool operator >(CString &a, CString&b);

  char& operator [](const int index);

 friend ostream& operator <<(ostream& out, CString &a);

 friend istream& operator >>(istream& in, CString&b);

 char* find(const char*e);

 char* find_c(char *c);

 void Cstrtok(char *c);

private:
  char* init;
  int length;
  int size;
};