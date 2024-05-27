#include <iostream>
#include <string>
using namespace std;

#include "list.h"
#include "data.h"
#include "display.h"

void init() {
  // Inisialisasi buku dan akun
  setDefaultBookData();
  setDefaultAccountData();
  setDefaultBorrow();
}

// Abaikan yang di bawah ^_^
void prt(int a) { cout << a << endl; }
int add(int x, int y) { return x + y; }
void invoke(int x, int y, int (*fulus)(int,int), void (*func)(int)) {
    func(fulus(x,y));
}
// Abaikan yang di atas ^_^



int main(){

  //invoke(1,2, &add, &prt);
  while (true) {
    init();
    loginScreen();
    system("run.cmd");
  }

  return 0;
}
