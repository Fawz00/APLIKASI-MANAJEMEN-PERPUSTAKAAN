#include <iostream>
using namespace std;

int multiply(int a, int b) {
  if(b>1)
    return a += multiply(a,b-1);
  else
    return a;
}

int power(int a, int b) {
  if(b>1)
    return a *= power(a,b-1);
  else if(b==0)
    return 1;
  else if(b<0) {
    cout << "Can not power by negative." << endl;
    exit(EXIT_FAILURE);
  } else
    return a;
}

int factorial(int a) {
  if(a<0) {
    cout << "Invalid input." << endl;
    exit(EXIT_FAILURE);
  } else if(a==1 || a==0)
    return a;
  else
    return a * factorial(a-1);
}

int fibonacci(int a) {
  if(a<=1)
    return a;
  else
    return fibonacci(a-2) + fibonacci(a-1);
}

int main() {
  cout << multiply(2, 10) << endl;
  cout << power(2, 10) << endl;
  cout << factorial(10) << endl;
  cout << fibonacci(10) << endl;

  return 0;
}