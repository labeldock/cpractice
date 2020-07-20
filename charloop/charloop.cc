#include <iostream>

using namespace std;

int word_check_zero(char *chars)
{
  int i = 0;
  while (chars[i] != '\0')
  {
    char t = chars[i];
    if (i == 0 && t != '1')
    {
      return 0;
    }
    if (i != 0 && t != '0')
    {
      return 0;
    }
    i++;
  }
  return i < 2 ? 0 : 1;
}

int main(void)
{

  char cstr_ok_1[] = "10";
  char cstr_ok_2[] = "10000";
  char cstr_false_1[] = "";
  char cstr_false_2[] = "1";
  char cstr_false_3[] = "10001";
  char cstr_false_4[] = "010001101";

  // 1 1 0 0이 나와야 합니다.
  cout << "cstr_ok_1 " << word_check_zero(cstr_ok_1) << endl;
  cout << "cstr_ok_2 " << word_check_zero(cstr_ok_2) << endl;
  cout << "cstr_false_1 " << word_check_zero(cstr_false_1) << endl;
  cout << "cstr_false_2 " << word_check_zero(cstr_false_2) << endl;
  cout << "cstr_false_3 " << word_check_zero(cstr_false_3) << endl;
  cout << "cstr_false_4 " << word_check_zero(cstr_false_4) << endl;

  return 0;
}
