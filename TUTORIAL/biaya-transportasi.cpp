#include <iostream>
#include <string>

using namespace std;

#define OUT_0 "Input jarak yang akan di tempuh (dalam KM): "
#define OUT_1 "Waktu:\n1. Siang\n2. Malam\nPilih waktu (1 atau 2): "
#define OUT_2 "Input waktu tidak valid!"

int main(){
  float distance, cost=0;
  int time;

  cout << OUT_0;
  cin >> distance;
  if(!cin){
    cin.clear();
    cin.ignore();
  }
  cout << endl;

  cout << OUT_1;
  cin >> time;
  if(!cin){
    cin.clear();
    cin.ignore();
  }
  cout << endl;

  // KODE

  float biaya_taksi;
  switch(time){
    case 1:
      biaya_taksi = 0.79;
      break;
    case 2:
      biaya_taksi = 0.9;
      break;
    default:
      cout << OUT_2;
      break;
  }

  if(distance >= 100.0){
    cost += 0.06 * distance;
    cout << "Biaya naik kereta: " << cost << " USD";
  }else if(distance >= 20){
    cost += 0.09 * distance;
    cout << "Biaya naik bis: " << cost << " USD";
  }else{
    cost += 0.7;
    cost += biaya_taksi * distance;
    cout << "Biaya naik taksi: " << cost << " USD";
  }

  cout << endl;

  return 0;
}
