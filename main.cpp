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



int main(){

  while (true) {
    init();
    loginScreen();
    system("run.cmd");
  }

  return 0;
}
