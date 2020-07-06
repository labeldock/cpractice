#include <iostream>
#include "windows.h"

using namespace std;

int main(void){
  auto consolecp = GetConsoleOutputCP();
  SetConsoleOutputCP(consolecp);
  cout << "Windows console codepage => " << consolecp << endl;
  cout << "Hello" << "안녕하세요" << endl;
  return 0;
}
