#include <iostream>
using namespace std;

int main(){
  bool isRunning = true;
  float data[5];
  string list[5] = {
    "1. Nilai tertinggi",
    "2. Nilai terendah",
    "3. Nilai rata-rata",
    "4. Ganti data",
    "5. Exit"
  };
  int n = sizeof(data)/sizeof(int);
  int nL = sizeof(list)/sizeof(string);

  for(int a=0; a<n; a++){
    cout << "Masukkan data ke-" << a+1 << ": \n";
    cin >> data[a];
    cin.get();
  }

  while(isRunning){
    cout << "Pilih yang akan ditampilkan:" << "\n";
    for(int i=0; i<nL; i++){
      cout << list[i] << "\n";
    }
    int pilihan;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    if(!cin){cin.clear();cin.ignore();}
    cout << "\n";

    if(pilihan == 1){

      float nilaiTinggi = -1000000.0;
      for(int j=0; j<n; j++){
        if(nilaiTinggi < data[j]) nilaiTinggi = data[j];
      }
      cout << "Nilai tertinggi: " << nilaiTinggi << "\n";

    } else if(pilihan == 2){

      float nilaiRendah = 1000000.0;
      for(int j=0; j<n; j++){
        if(nilaiRendah > data[j]) nilaiRendah = data[j];
      }
      cout << "Nilai terendah: " << nilaiRendah << "\n";

    } else if(pilihan == 3){

      float mean = 0;
      for(int j=0; j<n; j++){
        mean += data[j];
      }
      mean /= n;
      cout << "Nilai rata-rata: " << mean << "\n";

    } else if(pilihan == 4){

      for(int a=0; a<n; a++){
        cout << "Masukkan data ke-" << a+1 << ": \n";
        cin >> data[a];
        cin.get();
      }

    } else if(pilihan == 5){
      cout << "\u3042\u308A\u3050\u3068\u3046!";
      isRunning = false;
    } else {
      cout << "Input tidak valid!";
    }
    cout << "\n";
  }

  return 0;
}