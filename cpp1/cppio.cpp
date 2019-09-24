#include<iostream>
#include<string>

using namespace std;

int main() {
  int count;
  string str;

  cout << "Enter a number: ";
  cin >> count;

  cout << "Enter a word: ";
  cin >> str;   // Note - this only get characters until the next whitespace

  for(int ii=0; ii<count; ii++) {
    cout << ii+1 << " : " << str << endl;
  }

  // Clear stdin to read until the next newline 
  getline(cin, str);

  cout << endl;
  cout << "Enter a string: ";
  getline(cin, str);

  for(int ii=0; ii<count; ii++) {
    cout << ii+1 << " : " << str << endl;
  }

  return 0;
}
