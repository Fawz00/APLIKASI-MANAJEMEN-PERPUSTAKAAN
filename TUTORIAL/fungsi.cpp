#include <iostream>
using namespace std;

void string_repeater(int, string);

int main(){
  string_repeater(1024, "wk");
  return 0;
}

void string_repeater(int n, string a){
  for(int i=0; i<n; i++) cout << a;
}
