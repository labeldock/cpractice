#include <iostream>

using namespace std;

int main(void){

  #if (_WIN32)
  cout << "win32 and win64 build" << endl;
  #endif
  #if (_WIN64)
  cout << "win64 build" << endl;
  #endif
  #if (TARGET_IA32)
  // /DTARGET_IA32
  cout << "target ia32" << endl;
  #endif
  #if (TARGET_AMD64)
  cout << "target amd64" << endl;
  #endif
  
  return 0;
}