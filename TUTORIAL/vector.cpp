#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> something = {
    "\u3053\u3061\u3053\u3061\u3001\u831c\u3055\u3093",
    "Rahul Gandhi",
    "Rajas Kijar",
    "Siraj Jaji",
    "Ame"
  };
  int lastSize = something.size();

  cout << "Daftar nama saat ini:" << endl;
  for(int i=0; i<something.size(); i++) {
    cout << something[i] << endl;
  }

  cout << endl;

  for(int i=0; i<4; i++){
    string nama;
    cout << "Masukkan nama (" << i+1 << "): ";
    getline(cin, nama);
    
    for(int j=0; j<something.size(); j++){
      if(nama == something[j]){
        something.erase( something.begin() + j );
      }
    }
  }

  cout << endl << "Daftar nama yang belum diinput: " << endl;
  for(int i=0; i<something.size(); i++){
    cout << something[i] << endl;
  }

  // something.erase( something.begin() );

  return 0;
}
