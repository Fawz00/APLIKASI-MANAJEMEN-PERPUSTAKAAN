#include <iostream>
#include <vector>
using namespace std;

//===================================//
// Nama : Fawwaz Haryolukito Pambudi //
// NIM  : 2304130169                 //
//===================================//

// TYPEDEF STRUCT
typedef struct customer{
  int id;
  string name;
  string telp;
  vector<int> items;

  void show(){
    cout << "ID: " << id << "\n";
    cout << "Nama: " << name << "\n";
    cout << "Telp.: " << telp << "\n";

    for(int i=0; i<items.size(); i++) {
      cout << "ID item ke-" << i+1 << ": " << items[i] << "\n";
    }

    cout << "\n";
  }
} CTM;

int main(){
  CTM data0 = {1004, "Andi", "+62 85817897840", {0, 1, 4}};
  customer data1 = {1005, "Budi", "+62 81217789654", {1, 4, 2}};

  data0.show();
  data1.show();

  return 0;
}
