#include <iostream>
using namespace std;

#define CHECK_INPUT_ERROR if(!cin){cin.clear();cin.ignore();}

int main(){
  int length;
  float bs=0.0, b=0.0, k=0.0, pbs=0.0, pb=0.0, pk=0.0, t=0.0;

  cout << "Masukkan banyak siswa: ";
  cin >> length;
  CHECK_INPUT_ERROR

  for(int i=1; i<=length; i++){
    float c;

    cout << "Masukkan siswa " << i <<": ";
    cin >> c;
    CHECK_INPUT_ERROR
  
    if(c>=8.0 && c<=10.0){
      bs++;
    }else if(c>=6.5 && c<8.0){
      b++;
    }else if(c<6.5){
      k++;
    }else{
      cout << "ERROR. Input tidak valid!";
      return -1;
    }
    t += c;
  }

  cout  << "\nBaik Sekali: " << (bs/length)*100.0 << "%" << endl
        << "Baik: " << (b/length)*100.0 << "%" << endl
        << "Kurang: " << (k/length)*100.0 << "%" << endl
        << "Rata-rata Nilai: " << (t/length) << endl;

  return 0;
}