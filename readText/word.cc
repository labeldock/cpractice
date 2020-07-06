#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;


// regexp로 string을 쪼개 vector에 담습니다.
vector<string> regexpSplit(const string & s, string rgx_str = "\\s+") {
  vector<string> elems;
  regex rgx (rgx_str);
  sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
  sregex_token_iterator end;
  while (iter != end)  {
      elems.push_back(*iter);
      ++iter;
  }
  return elems;
}

// path에 있는 파일의 각 단어별로 로그에 찍습니다.
void ReadWords(string filePath){

  ifstream readFile(filePath);

  if(readFile.is_open() == 0){
    cout << filePath << " 파일이 열리지 않습니다!" << endl;
    return;
  }
  
  for(string line;getline(readFile, line);){
    vector<string> words = regexpSplit(line);
    for (const auto & word: words) {
       cout << word << endl;
    }
  }

  readFile.close();
}

int main(void){
  string filePath = "data.txt";
  ReadWords(filePath);
  return 0;
}