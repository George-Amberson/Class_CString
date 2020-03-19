#include "String.h"

CString::CString():init(0),size(0),length(0)
{

}

CString::CString(char b, int leng){
  size = leng+1;
  init = new char[size];
  length = leng;
  for (int i = 0; i < length; i++) init[i] = b;
  init[length] = 0;
}

CString::CString(const char* cstr){
  if (strlen(cstr) > 0){

    size = strlen(cstr) + 1;
    length = strlen(cstr);
    init = new char[strlen(cstr) + 1];
    for (size_t i = 0; i < strlen(cstr); i++)init[i] = cstr[i];
    init[strlen(cstr)] = 0;
  }

}

CString::CString(CString &a){
  size = a.get_l() + 1;
  length = a.get_l();
  init = new char[size];
  for (int i = 0; i < length; i++)init[i] = a.get_s()[i];
  init[length] = 0;
}

CString::~CString(){
  delete[] init;
}

void CString::set_s(const char*s){
  if (strlen(s) > 0){
    size = strlen(s) + 1;
    length = strlen(s);
    init = new char[strlen(s) + 1];
    for (size_t i = 0; i < strlen(s); i++)init[i] = s[i];
    init[strlen(s)] = 0;
  }
}

CString operator +(CString& a, CString &b){
  CString c(a);
  c.complete(a, b);
  return c;
}

CString &CString::operator =(const CString& a){
  length = a.length;
  size = length + 1;
  init = new char[size];
  for (int i = 0; i < length; i++)init[i] = a.init[i];
  init[length] = 0;
  return *this;
}

bool operator == (CString &a, CString &b){
  return(0 == strcmp(a.get_s(), b.get_s()));
}

bool operator <(CString &a, CString&b){
  return(strcmp(a.get_s(), b.get_s()) < 0);
}

bool operator >(CString &a, CString&b){
return(strcmp(a.get_s(), b.get_s()) > 0);
}

char& CString::operator [](const int index){
  return init[index];
}

ostream& operator <<(ostream& out, CString &a){
  for (int i = 0; i < a.get_l(); i++){
    out << a.get_s()[i];
  }

  return out;
}

istream& operator >>(istream& in, CString& b){
  char t [256];
  in.getline(t,256);
  CString e(t);
  b = e;
  return in;
}

char* CString::find(const char*e){
  char* t = strstr(init, e);
  return t;
}

char*CString::find_c(char *c){
  char* t = strstr(init, c);
  return t;
}

void CString::Cstrtok(char *c){
  char *istr = strtok(init, c);

  
  while (istr != NULL)
  {
  
    cout << istr << endl;

    istr = strtok(NULL, c);
  }
}