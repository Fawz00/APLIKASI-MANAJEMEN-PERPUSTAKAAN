#include <iostream>
using namespace std;

int main(){
  bool isRunning = true;
  string menu[4] = {
    "1. Print \"Hello World!\"",
    "2. Greeting",
    "3. Change name",
    "4. Exit"
  };
  int n = sizeof(menu)/sizeof(string);

  string nama;
  cout << "Masukkan nama: ";
  getline(cin, nama);
  cout << "\n";

  while(isRunning){
    cout << "Pilih menu:" << "\n";
    for(int i=0; i<n; i++){
      cout << menu[i] << "\n";
    }
    int pilihan;
    cout << "Masukkan pilihan menu: ";
    cin >> pilihan;
    cin.get();
    if(!cin){cin.clear();cin.ignore();}
    cout << "\n";

    if(pilihan == 1){
      cout << "Hello World!" << "\n";
    } else if(pilihan == 2){
      cout << "Alo, " << nama << "!\n";
    } else if(pilihan == 3){
      cout << "masukkan nama baru: ";
      getline(cin, nama);
    } else if(pilihan == 4){
      isRunning = false;
    } else {
      cout << "Input tidak valid!";
    }
    cout << "\n";
  }

  return 0;
}