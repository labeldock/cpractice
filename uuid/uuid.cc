#include <iostream>
#include <string>
#include <random>
#include <regex>
#include <algorithm>

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
  return dis(gen); // 여기는 왜 return dis(gen);을 하면 엉뚱한 값이 나오고. 변수 할당을 해줘야 제대로된 값이 나올까요?
}

//RFC4122 compliant
/*
## uuid 생성 함수
- RFC4122 스팩 유사 준수
- 커스텀한 난수 id 생성 가능 (x,y로)
```
generate_uuid() // 'fba7391f-ad53-4bd0-bfb4-7db2937911be'
generate_uuid('no-xxyx') // 'no-de80'
generate_uuid('nothing') // 'nothing'
```
*/
string generate_uuid(string format = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx"){
  string output = "0123456789abcdef";
  string result = "";
  for_each(format.begin(), format.end(), [&](char character){
    if(character == 'x'){
      string picked_string(1, output.at(rand_int(16)));
      result += picked_string;
    } else if(character == 'y'){
      string picked_string(1, output.at(rand_int(16) & 3 | 8));
      result += picked_string;
    } else {
      string picked_string(1, character);
      result += picked_string;
    }
  });
  return result;
}

int main(void){
  string uuid = generate_uuid();
  cout << "UUID : " << uuid << endl;

  string custom_uuid = generate_uuid("no-xxyx");
  cout << "Custom UUID : " << custom_uuid << endl;

  return 0;
}