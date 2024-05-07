#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cout << "Input first number: ";
  cin >> a;
  cout << "Input second number: ";
  cin >> b;
  cout << "Input third number: ";
  cin >> c;
  if(a+b==c){
    cout << a<<" + "<<b<<" = "<<c;
  }else if(a+c==b){
    cout << a<<" + "<<c<<" = "<<b;
  }else if(b+c==a){
    cout << b<<" + "<<c<<" = "<<a;
  }else{
    cout << "NO";
  }
  return 0;
}
