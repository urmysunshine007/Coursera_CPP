#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Cstring{
private:
  string str;
public:
  Cstring(const string s);
  Cstring(const Cstring&);
  int Ccompare(string str2);
  Cstring operator+(Cstring&str2);
  Cstring operator-(Cstring&str2);
  Cstring operator*(Cstring&str2);
  Cstring operator/(Cstring&str2);
  void print(){
    cout << str << endl;
  }
};

Cstring::Cstring(const string s){
  str = s;
}
Cstring::Cstring(const Cstring&c){
  str = c.str;
}
int Cstring::Ccompare(string str2){
  if (str.size()>str2.size()){
    return 1;
  }
  else if (str.size()<str2.size()){
    return -1;
  }
  else{
    return str.compare(str2);
  }
}

Cstring Cstring::operator+(Cstring & str2){
  string string1, string2;
  string1 = str;
  string2 = str2.str;
  string::size_type lenth1, lenth2;
  lenth1 = string1.size();
  lenth2 = string2.size();

  if (lenth1<lenth2){
    for (int i = lenth2 - lenth1; i > 0; i--){
      string1 = '0' + string1;
    }
  }
  else if (lenth1>lenth2){
    for (int i = lenth1 - lenth2; i > 0; i--){
      string2 = '0' + string2;
    }
  }///pad with '0's

  string output;
  int int1, int2 = 0;
  for (int i = string1.size() - 1; i >= 0; i--){
    int1 = (int(string1[i]) - 48 + int(string2[i]) - 48 + int2) % 10;
    int2 = (int(string1[i]) - 48 + int(string2[i]) - 48 + int2) / 10;
    output = char(int1 + 48) + output;
  }
  if (int2 != 0){
    output = char(int2 + 48) + output;
  }
  return Cstring(output);
}

Cstring Cstring::operator-(Cstring &str2){
  string string1, string2;
  int sign = 1;
  string1 = str;
  string2 = str2.str;
  if (Ccompare(str2.str)<0){
    string2 = str;
    string1 = str2.str;
    sign = -1;
  }
  else if (Ccompare(str2.str) == 0){
    return Cstring("0");
  }
  string::size_type lenth1, lenth2;
  lenth1 = string1.size();
  lenth2 = string2.size();
  if (lenth2<lenth1){
    for (int i = lenth1 - lenth2; i > 0; i--){
      string2 = '0' + string2;
    }
  }//pad string2

  string output;
  int int1 = 0, int2 = 0;
  for (int i = lenth1 - 1; i >= 0; i--){
    if (string1[i] - string2[i] - int2 < 0){
      int1 = 10 + (string1[i] - string2[i]) - int2;
      int2 = 1;
    }
    else{
      int1 = (string1[i] - string2[i]) - int2;
      int2 = 0;
    }
    output = char(int1 + 48) + output;
  }
  output = output.erase(0, output.find_first_not_of('0'));
  if (sign == -1){
    output = '-' + output;
  }
  return Cstring(output);
}

Cstring Cstring::operator*(Cstring &str2){
  string::size_type lenth1, lenth2;
  lenth1 = str.size();
  lenth2 = str2.str.size();
  Cstring output("");
  for (int i = lenth2 - 1; i >= 0; i--){
    int mr = int(str2.str[i]) - 48;
    string tempstr;
    int int1 = 0, int2 = 0;
    for (int j = lenth1 - 1; j >= 0; j--){
      int1 = ((int(str[j]) - 48)*mr + int2) % 10;
      int2 = ((int(str[j]) - 48)*mr + int2) / 10;
      tempstr = char(int1 + 48) + tempstr;
    }
    if (int2 != 0){
      tempstr = char(int2 + 48) + tempstr;
    }
    for (int k = lenth2 - 1 - i; k > 0; k--){
      tempstr += '0';
    }
    tempstr.erase(0, tempstr.find_first_not_of("0"));
    output = output + Cstring(tempstr);
  }
  if (output.str.empty()){
    return Cstring("0");
  }
  return output;
}

Cstring Cstring::operator/(Cstring &str2){
  string::size_type lenth1, lenth2;
  lenth1 = str.size();
  lenth2 = str2.str.size();
  string output;
  string tempstr;
  tempstr.append(str, 0, lenth2);

  for (int i = lenth2 - 1; i < lenth1; i++){
    Cstring as("0");
    for (int j = 0; j < 10; j++){
      as = as + Cstring("1");
      Cstring product = str2 * Cstring(as);
      int t = product.Ccompare(tempstr);
      if (t > 0){
        if (as.str != "0"){
          as = as - Cstring("1");
        }
        output = output + as.str;
        output.erase(0, output.find_first_not_of('0'));
        Cstring product = Cstring(str2) * Cstring(output);
        tempstr = (Cstring(str.substr(0, i+1)) - product).str;
        tempstr.append(str, i+1, 1);
        tempstr.erase(0, tempstr.find_first_not_of("0"));
        break;
      }
    }
  }
  return Cstring(output);
}
int main(){
  string str1, str2;
  char ch;
  cin >> str1 >> ch >> str2;

  Cstring string1(str1);
  Cstring string2(str2);
  switch (ch){
    case '+': {
      Cstring output = string1 + string2;
      output.print();
      return 0;
    }
    case '-':{
      Cstring output = string1 - string2;
      output.print();
      return 0;
    }

    case '/':{
      Cstring output = string1 / string2;
      output.print();
      return 0;
    }
    case '*':{
      Cstring output = string1 * string2;
      output.print();
      return 0;
    }
    default: break;
  }
}


