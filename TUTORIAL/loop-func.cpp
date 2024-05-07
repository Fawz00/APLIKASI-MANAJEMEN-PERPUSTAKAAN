#include <iostream>
using namespace std;

void aaa(int a){
  if(a<=50){
    cout << a << " ";
    aaa(a++);
  }
}

int main(){
  aaa(1);
  return 0;
}