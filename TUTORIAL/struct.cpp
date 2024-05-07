#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct siswa{
  string nama;
  string alamat;
  long nim;

  void show(){
    cout << "Nama: " << nama << endl;
    cout << "Alamat: " << alamat << endl;
    cout << "NIM: " << nim << endl;
  }
};

int main(){
  vector<siswa> mahasiswa;

  siswa human_0;
  human_0.nama = "John Agus Slamet";
  human_0.alamat = "Mt. Moon, Ohio, US";
  human_0.nim = 30000;
  mahasiswa.push_back(human_0);

  siswa human_1;
  human_1.nama = "\u831c\u3055\u3093";
  human_1.alamat = "Shinjuku, Tokyo, JP";
  human_1.nim = 40001;
  mahasiswa.push_back(human_1);

  for(int i=0; i<mahasiswa.size(); i++) {
    mahasiswa[i].show();
    cout << endl;
  }
  return 0;
}
