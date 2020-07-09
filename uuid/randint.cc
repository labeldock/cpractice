#include <iostream>
#include <string>
#include <random>
#include <regex>

using namespace std;

/*
## 랜덤 int 생성 함수
- rand_int() 0~9 중 int 하나가 나와야 합니다.
- rand_int(3) 0~2 중 int 하나가 나와야 합니다.
- rand_int(3, 10) 10~12 중 int 하나가 나와야 합니다.
*/
int rand_int(int length = 10, int start = 0){
  int min = start;
  int max = length < 1 ? start : (start + length - 1);
  random_device seed;
  mt19937 gen(seed());
  uniform_int_distribution<int> dis(min, max);
  return dis(gen);
}

int main(void){

  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  cout << "case 1 : " << rand_int(16) << endl;
  
  return 0;
}

/*

- 메모리 누수의 요인이 있는지 궁금합니다.
- rand_int 함수의 return 에서 int value = dis(gen); 이후 return value;을 하면 설계한 값대로(2,0,1,0,3 등등) 나오는데 return dis(gen); 을 직접 하면 엉뚱한값 (1142, 382, 220, 221 등등)이 나옵니다. 

*/