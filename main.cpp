#include <iostream>
#include "String.h"
#include <array>
#include <string.h>

using namespace std;


int main(){
  CString a;
  CString b("unzial_const");
  CString c(b);
 cout<< b.get_s()<<" dostup k polu"<<endl;
 cout << c.get_s() << " dostup k polu"<<endl;
 c.set_s("dostup k polu");
 cout << c << endl;
 CString d;
 d = b + c;
 cout << d<<" operator +"<<endl;
 CString e("sdsdsds");
 CString f("sdsdsds");
 cout << (f == e)<<" operator =="<<endl;
 cout << (b == c) << " operator ==" << endl;
 e.set_s("sdsd");
 f.set_s("s");
 cout << (e < f) << " operator <"<<endl;
 cout << (f > e) <<" operator >"<< endl;
 cout << f[0]<<" operator []"<<endl;

 cin >> a;
 cout << b.find("_c") << endl;
 cout << b.find_c("z")<<endl;
 b.Cstrtok("_");
  return 0;
}