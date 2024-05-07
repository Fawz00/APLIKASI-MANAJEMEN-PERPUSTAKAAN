#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define LIHAT_HASIL a<<", dan b = "<<b<<"."<<endl

int main(){
  int a, b, c, d, e, f;

  //=================//
  //   Tukar Nilai   //
  //=================//
  cout << "Masukkan nilai a: ";
  cin >> a;

  cout << "Masukkan nilai b: ";
  cin >> b;

  cout << "Nilai a dan b saat ini adalah: a = " << LIHAT_HASIL;
  a = a+b;
  b = a-b;
  a = a-b;

  cout << "Nilai a dan b setelah ditukar adalah: a = " << LIHAT_HASIL << endl;

  return 0;
}
