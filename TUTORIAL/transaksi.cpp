#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct transaksi{
  string deskripsi;
  float nominal;
  int tipe;

  void show(){
    if(tipe == 1) cout << "Transaksi Masuk" << endl;
    if(tipe == 2) cout << "Transaksi Keluar" << endl;
    cout << "Nominal: $" << nominal << endl;
    cout << "Deskripsi: " << deskripsi << endl;
  }
};

int main(){
  bool run = true;
  vector<transaksi> data;

  while(run) {
    cout << "========== Aplikasi Transaksi ==========\n1. Tambah transaksi\n2. Lihat riwayat transaksi\n3. KELUAR\n" << endl;
    int pilihan;
    cin >> pilihan;
    cin.get();
    if(!cin){ cin.clear(); cin.ignore(); }

    switch (pilihan){
      case 1: {
        cout << endl << "========== Tambah Transaksi ==========" << endl;
        float a = 0;
        string b = "";
        int c = 0;

        cout << "Jenis transaksi (isi 1 untuk pemasukan, 2 untuk pengeluaran): ";
        cin >> c;
        cin.get();
        if(!cin){ cin.clear(); cin.ignore(); }

        cout << "Sebanyak: $";
        cin >> a;
        cin.get();
        if(!cin){ cin.clear(); cin.ignore(); }

        cout << "Deskripsi: ";
        getline(cin, b);
        //cout << endline;

        transaksi cache;
        cache.nominal = a;
        cache.deskripsi = b;
        cache.tipe = c;
        data.push_back(cache);
        break;
      }
      case 2: {
        cout << endl << "========== Riwayat Transaksi ==========" << endl;
        for(int i=0; i<data.size(); i++) {
          data[i].show();
          cout << endl;
        }
        cout << endl;
        break;
      }
      case 3: {
        run = false;
        break;
      }
    }
  }
  
  return 0;
}
