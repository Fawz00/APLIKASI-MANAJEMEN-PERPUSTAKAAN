#include <iostream>
using namespace std;

// Fungsi addSpaceTab(a,c,b) untuk memberikan spasi secara rapi
string addSpaceTab(string a, string c, int b){
  string d = "";
  int e = b - a.size();
  if(e < 0) e = 0;

  for(int i=0; i<e; i++){
    d = d+c;
  }
  return a+d;
}



int main(){
  //===============================================//
  //          I N I T I A L I Z A T I O N          //
  //===============================================//
  string buku[256];
  menuMakanan[0] = "Soto";
  menuMakanan[1] = "Gado-Gado";
  menuMakanan[2] = "Nasi Goreng";
  menuMakanan[3] = "Croissant";
  menuMakanan[4] = "Bebek Bakar";

  float hargaMakanan[50];
  hargaMakanan[0] = 0.77;
  hargaMakanan[1] = 0.19;
  hargaMakanan[2] = 0.16;
  hargaMakanan[3] = 1.92;
  hargaMakanan[4] = 1.7;
  int jumlahMakanan[50];
  jumlahMakanan[0] = 0;
  jumlahMakanan[1] = 0;
  jumlahMakanan[2] = 0;
  jumlahMakanan[3] = 0;
  jumlahMakanan[4] = 0;
  int NmenuMakanan = sizeof(menuMakanan)/sizeof(string);

  string menuMinuman[50];
    menuMinuman[0] = "Air";
    menuMinuman[1] = "Es teh";
    menuMinuman[2] = "CocaCola";
    menuMinuman[3] = "Es jeruk";
    menuMinuman[4] = "Soda Gembira";

  float hargaMinuman[50];
    hargaMinuman[0] = 0.16;
    hargaMinuman[1] = 0.16;
    hargaMinuman[2] = 0.32;
    hargaMinuman[3] = 0.42;
    hargaMinuman[4] = 1.02;
  int jumlahMinuman[50];
  jumlahMinuman[0] = 0;
  jumlahMinuman[1] = 0;
  jumlahMinuman[2] = 0;
  jumlahMinuman[3] = 0;
  jumlahMinuman[4] = 0;
  int NmenuMinuman = sizeof(menuMinuman)/sizeof(string);

  string display[4] = {
    "Tambah / hapus makanan",
    "Tambah / hapus minuman",
    "Tampilkan total harga dan rincian",
    "Keluar"
  };
  int Ndisplay = sizeof(display)/sizeof(string);

  // A D M I N
  string displayAdmin[9] = {
    "Lihat menu makanan saat ini",
    "Lihat menu minuman saat ini",
    "Ubah menu makanan",
    "Ubah menu minuman",
    "Tambah menu makanan",
    "Tambah menu minuman",
    "Hapus menu makanan",
    "Hapus menu minuman",
    "Keluar"
  };
  int NdisplayAdmin = sizeof(displayAdmin)/sizeof(string);



  //===================================//
  //          T H E   L O O P          //
  //===================================//
  bool mainLoop = true;
  while(mainLoop) {
    bool isRunningAdminMode;
    bool isRunning;
    int loginAs;
    cout << endl << "+============================+" << endl;
    cout         << "|          KAFE CPP          |" << endl;
    cout         << "+============================+" << endl;
    cout << "Login sebagai:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Pelanggan" << endl << endl;
    cout << "Lainnya:" << endl;
    cout << "3. Informasi" << endl;
    cout << "4. Keluar aplikasi" << endl << endl;
    cout << "Pilih pilihan: ";

    cin >> loginAs;
    cin.get();
    if(!cin){cin.clear();cin.ignore();}

    switch (loginAs){
      case 1: {
        // Masuk sebagai admin
        isRunningAdminMode = true;
        isRunning = false;
        break;
      }

      case 2: {
        // Masuk sebagai pelanggan
        isRunningAdminMode = false;
        isRunning = true;

        // Reset seluruh pemesanan ke 0 untuk mencegah bug.
        int foodCounter = 0;
        while(menuMakanan[foodCounter] != ""){
          jumlahMakanan[foodCounter] = 0;
          foodCounter++;
        }
        int drinkCounter = 0;
        while(menuMakanan[drinkCounter] != ""){
          jumlahMinuman[drinkCounter] = 0;
          drinkCounter++;
        }
        break;
      }

      case 3: {
        // Tampilkan informasi
        cout << endl << "Kelompok 6" << endl;
        cout << addSpaceTab("Nama", " ", 50) << "NIM" << endl;
        cout << addSpaceTab("", "-", 60) << endl;
        cout << addSpaceTab("FAWWAZ HARYOLUKITO PAMBUDI", " ", 50) << "2304130169" << endl;
        cout << addSpaceTab("MUHAMMAD ZUNIAR HILMI", " ", 50) << "2304130178" << endl;
        cout << addSpaceTab("I GEDE ARDHY NIRATHA", " ", 50) << "2304130168" << endl;
        cout << addSpaceTab("DAFFA PRAMATA ARYAPUTRA", " ", 50) << "2304130160" << endl;
        cout << addSpaceTab("MUHAMMAD NUR FURQON", " ", 50) << "2304130140" << endl;

        cout << endl << "Tekan 1 untuk kembali." << endl;
        int cache;
        cin >> cache;
        cin.ignore();
        break;
      }

      case 4: {
        // Keluar
        isRunningAdminMode = false;
        isRunning = false;
        mainLoop = false;
        break;
      }
    }

    float totalPrice = 0.0;

    //===========================//
    //     P E L A N G G A N     //
    //===========================//
    while(isRunning){
      int selector;
      float totalPrice = 0.0;

      cout << endl << "+============================+" << endl;
      cout         << "|          KAFE CPP          |" << endl;
      cout         << "+============================+" << endl;

      for(int i=0; i<Ndisplay; i++){
        cout << i+1 << ". " << display[i] << "\n";
      }
      cout << endl << "Pilih aksi: ";
      cin >> selector;
      cin.get();
      if(!cin){cin.clear();cin.ignore();}

      switch(selector){
      case 1: {
        // ADD FOOD
        int selectedFood;
        int totalFood;

        cout << endl << "===== TAMBAH MAKANAN =====" << endl;
        int numFood = 1;
        for(int i=0; i<NmenuMakanan; i++){
          if(menuMakanan[i] != "") cout << numFood++ << ". " << addSpaceTab(menuMakanan[i], " ", 50) << "$ " << hargaMakanan[i] << "\n";
        }
        cout << "\nPilih makanan: ";
        cin >> selectedFood;
        cin.get();
        if(!cin){cin.clear();cin.ignore();}

        cout << "Berapa banyak (isi 0 untuk mengosongkan): ";
        cin >> totalFood;
        cin.get();
        if(!cin){cin.clear();cin.ignore();}

        jumlahMakanan[selectedFood-1] = totalFood;
        break;
      }

      case 2: {
        // ADD DRINK
        int selectedDrink;
        int totalDrink;

        cout << endl << "===== TAMBAH MINUMAN =====" << endl;
        int numDrink = 1;
        for(int i=0; i<NmenuMinuman; i++){
          if(menuMinuman[i] != "") cout << numDrink++ << ". " << addSpaceTab(menuMinuman[i], " ", 50) << "$ " << hargaMinuman[i] << "\n";
        }
        cout << "\nPilih minuman: ";
        cin >> selectedDrink;
        cin.get();
        if(!cin){cin.clear();cin.ignore();}

        cout << "Berapa banyak (isi 0 untuk mengosongkan): ";
        cin >> totalDrink;
        cin.get();
        if(!cin){cin.clear();cin.ignore();}

        jumlahMinuman[selectedDrink-1] = totalDrink;
        break;
      }

      case 3: {
        // DETAILS
        cout << endl << "===== RINCIAN PEMESANAN =====" << endl;

        int numMakanan = 0;
        cout << "Makanan: \n";
        for(int i=0; i<NmenuMakanan; i++){
          if(jumlahMakanan[i] > 0 && menuMakanan[i] != ""){
            cout << ++numMakanan << ". " << addSpaceTab(menuMakanan[i], " ", 35)
            << "x" << addSpaceTab(to_string(jumlahMakanan[i]), " ", 15)
            << "$ " << hargaMakanan[i]*jumlahMakanan[i] << "\n";
            totalPrice += hargaMakanan[i]*jumlahMakanan[i];
          }
        }

        int numMinuman = 0;
        cout << "Minuman: \n";
        for(int i=0; i<NmenuMinuman; i++){
          if(jumlahMinuman[i] > 0 && menuMinuman[i] != ""){
            cout << ++numMinuman << ". " << addSpaceTab(menuMinuman[i], " ", 35)
            << "x" << addSpaceTab(to_string(jumlahMinuman[i]), " ", 15)
            << "$ " << hargaMinuman[i]*jumlahMinuman[i] << "\n";
            totalPrice += hargaMinuman[i]*jumlahMinuman[i];
          }
        }

        cout << addSpaceTab("", "-", 54) << "------------ +" << endl;
        cout << addSpaceTab("TOTAL HARGA: ", " ", 54) << "$ " << totalPrice << endl;

        cout << endl << "Tekan 1 untuk kembali." << endl;
        int cache;
        cin >> cache;
        cin.ignore();
        break;
      }

      case 4: {
        // Keluar dari menu pelanggan
        cout << "\nKembali ke menu Login" << endl;
        isRunning = false;
        break;
      }
      
      default:{
        cout << endl << "Input tidak valid!";
        break;
      }
      }

    }



    //===================//
    //     A D M I N     //
    //===================//
    while(isRunningAdminMode){
      int selector;

      cout << endl << "+============================+" << endl;
      cout         << "|          KAFE CPP          |" << endl;
      cout         << "+============================+" << endl;
      cout << "!ADMIN MODE" << endl << endl;

      for(int i=0; i<NdisplayAdmin; i++){
        cout << i+1 << ". " << displayAdmin[i] << "\n";
      }
      cout << "Pilih aksi: ";
      cin >> selector;
      cin.get();
      if(!cin){cin.clear();cin.ignore();}

      switch(selector){
        case 1: {
          // Lihat menu makanan
          cout << endl << "===== LIHAT MENU MAKANAN =====" << endl;
          cout << endl << "Menu makanan saat ini:" << endl;
          int numFood = 1;
          for(int i=0; i<NmenuMakanan; i++){
            if(menuMakanan[i] != "") cout << numFood++ << ". " << addSpaceTab(menuMakanan[i], " ", 50) << "$ " << hargaMakanan[i] << "\n";
          }

          cout << endl << "Tekan 1 untuk kembali." << endl;
          int cache;
          cin >> cache;
          cin.ignore();
          break;
        }

        case 2: {
          // Lihat menu minuman
          cout << endl << "===== LIHAT MENU MINUMAN =====" << endl;
          cout << endl << "Menu minuman saat ini:" << endl;
          int numDrinks = 1;
          for(int i=0; i<NmenuMinuman; i++){
            if(menuMinuman[i] != "") cout << numDrinks++ << ". " << addSpaceTab(menuMinuman[i], " ", 50) << "$ " << hargaMinuman[i] << "\n";
          }

          cout << endl << "Tekan 1 untuk kembali." << endl;
          int cache;
          cin >> cache;
          cin.ignore();
          break;
        }

        case 3: {
          // Ubah menu makanan
          int selectedFood = -1;
          string foodName = "";
          float foodPrice = 0;

          cout << endl << "===== UBAH MENU MAKANAN =====" << endl;
          cout << endl << "Menu makanan saat ini:" << endl;
          int numFood = 1;
          for(int i=0; i<NmenuMakanan; i++){
            if(menuMakanan[i] != "") cout << numFood++ << ". " << addSpaceTab(menuMakanan[i], " ", 50) << "$ " << hargaMakanan[i] << "\n";
          }
          while(selectedFood == -1 || selectedFood >= numFood || selectedFood < 1){
            cout << "\nPilih nomor yang akan diubah: ";
            cin >> selectedFood;
            cin.get();
            if(!cin){cin.clear();cin.ignore();}
            if(selectedFood >= numFood || selectedFood < 1) cout << "ID diluar jangkauan." << endl;
          }

          while(foodName == ""){
            cout << "Nama baru (wajib diisi): ";
            getline(cin, foodName);
          }
          menuMakanan[selectedFood-1] = foodName;

          cout << "Harga baru: ";
          cin >> foodPrice;
          cin.get();
          if(!cin){cin.clear();cin.ignore();}
          hargaMakanan[selectedFood-1] = foodPrice;
          break;
        }

        case 4: {
          // Ubah menu minuman
          int selectedDrink = -1;
          string drinkName = "";
          float drinkPrice = 0;

          cout << endl << "===== UBAH MENU MINUMAN =====" << endl;
          cout << endl << "Menu minuman saat ini:" << endl;
          int numDrinks = 1;
          for(int i=0; i<NmenuMinuman; i++){
            if(menuMinuman[i] != "") cout << numDrinks++ << ". " << addSpaceTab(menuMinuman[i], " ", 50) << "$ " << hargaMinuman[i] << "\n";
          }
          while(selectedDrink == -1 || selectedDrink >= numDrinks || selectedDrink < 1){
            cout << "\nPilih nomor yang akan diubah: ";
            cin >> selectedDrink;
            cin.get();
            if(!cin){cin.clear();cin.ignore();}
            if(selectedDrink >= numDrinks || selectedDrink < 1) cout << "ID diluar jangkauan." << endl;
          }

          while(drinkName == ""){
            cout << "Nama baru (wajib diisi): ";
            getline(cin, drinkName);
          }
          menuMinuman[selectedDrink-1] = drinkName;

          cout << "Harga baru: ";
          cin >> drinkPrice;
          cin.get();
          if(!cin){cin.clear();cin.ignore();}
          hargaMinuman[selectedDrink-1] = drinkPrice;
          break;
        }

        case 5: {
          // Tambah menu makanan
          string foodName = "";
          float foodPrice = 0;

          cout << endl << "===== TAMBAH MENU MAKANAN =====" << endl;
          cout << endl << "Menu makanan saat ini:" << endl;
          int numFood = 1;
          for(int i=0; i<NmenuMakanan; i++){
            if(menuMakanan[i] != "") cout << numFood++ << ". " << addSpaceTab(menuMakanan[i], " ", 50) << "$ " << hargaMakanan[i] << "\n";
          }

          while(foodName == ""){
            cout << "\nNama (wajib diisi): ";
            getline(cin, foodName);
          }
          menuMakanan[numFood-1] = foodName;

          cout << "Harga: ";
          cin >> foodPrice;
          cin.get();
          if(!cin){cin.clear();cin.ignore();}
          hargaMakanan[numFood-1] = foodPrice;
          break;
        }

        case 6: {
          // Tambah menu minuman
          string drinkName = "";
          float drinkPrice = 0;

          cout << endl << "===== Tambah MENU MINUMAN =====" << endl;
          cout << endl << "Menu minuman saat ini:" << endl;
          int numDrinks = 1;
          for(int i=0; i<NmenuMinuman; i++){
            if(menuMinuman[i] != "") cout << numDrinks++ << ". " << addSpaceTab(menuMinuman[i], " ", 50) << "$ " << hargaMinuman[i] << "\n";
          }

          while(drinkName == ""){
            cout << "\nNama (wajib diisi): ";
            getline(cin, drinkName);
          }
          menuMinuman[numDrinks-1] = drinkName;

          cout << "Harga: ";
          cin >> drinkPrice;
          cin.get();
          if(!cin){cin.clear();cin.ignore();}
          hargaMinuman[numDrinks-1] = drinkPrice;
          break;
        }

        case 7: {
          // Hapus menu makanan
          int selectedFood = -1;

          cout << endl << "===== HAPUS MENU MAKANAN =====" << endl;
          cout << endl << "Menu makanan saat ini:" << endl;
          int numFood = 1;
          for(int i=0; i<NmenuMakanan; i++){
            if(menuMakanan[i] != "") cout << numFood++ << ". " << addSpaceTab(menuMakanan[i], " ", 50) << "$ " << hargaMakanan[i] << "\n";
          }

          if(numFood > 2){
            while(selectedFood == -1 || selectedFood >= numFood || selectedFood < 1){
              cout << "\nPilih nomor yang akan dihapus: ";
              cin >> selectedFood;
              cin.get();
              if(!cin){cin.clear();cin.ignore();}
              if(selectedFood >= numFood || selectedFood < 1) cout << "ID diluar jangkauan." << endl;
            }

            // Menggeser daftar yang ada selanjutnya ke bagian yang sudah dihapus
            int pointer = selectedFood-1;
            menuMakanan[pointer] = "";
            hargaMakanan[pointer] = 0;
            jumlahMakanan[pointer] = 0;
            while(menuMakanan[pointer+1] != ""){
              menuMakanan[pointer] = menuMakanan[pointer+1];
              hargaMakanan[pointer] = hargaMakanan[pointer+1];
              jumlahMakanan[pointer] = jumlahMakanan[pointer+1];
              pointer++;
            }
            menuMakanan[pointer] = "";
            hargaMakanan[pointer] = 0;
            jumlahMakanan[pointer] = 0;
          } else {
            cout << "\nPenghapusan tidak dapat dilakukan." << endl;
            cout << endl << "Tekan 1 untuk kembali." << endl;
            int cache;
            cin >> cache;
            cin.ignore();
          }
          break;
        }

        case 8: {
          // Hapus menu minuman
          int selectedDrink = -1;

          cout << endl << "===== HAPUS MENU MINUMAN =====" << endl;
          cout << endl << "Menu minuman saat ini:" << endl;
          int numDrink = 1;
          for(int i=0; i<NmenuMinuman; i++){
            if(menuMinuman[i] != "") cout << numDrink++ << ". " << addSpaceTab(menuMinuman[i], " ", 50) << "$ " << hargaMinuman[i] << "\n";
          }

          if(numDrink > 2){
            while(selectedDrink == -1 || selectedDrink >= numDrink || selectedDrink < 1){
              cout << "\nPilih nomor yang akan dihapus: ";
              cin >> selectedDrink;
              cin.get();
              if(!cin){cin.clear();cin.ignore();}
              if(selectedDrink >= numDrink || selectedDrink < 1) cout << "ID diluar jangkauan." << endl;
            }

            // Menggeser daftar yang ada selanjutnya ke bagian yang sudah dihapus
            int pointer = selectedDrink-1;
            menuMinuman[pointer] = "";
            hargaMinuman[pointer] = 0;
            jumlahMinuman[pointer] = 0;
            while(menuMinuman[pointer+1] != ""){
              menuMinuman[pointer] = menuMinuman[pointer+1];
              hargaMinuman[pointer] = hargaMinuman[pointer+1];
              jumlahMinuman[pointer] = jumlahMinuman[pointer+1];
              pointer++;
            }
            menuMinuman[pointer] = "";
            hargaMinuman[pointer] = 0;
            jumlahMinuman[pointer] = 0;
          } else {
            cout << "\nPenghapusan tidak dapat dilakukan." << endl;
            cout << endl << "Tekan 1 untuk kembali." << endl;
            int cache;
            cin >> cache;
            cin.ignore();
          }
          break;
        }

        case 9: {
          // Keluar dari admin
          isRunningAdminMode = false;
          break;
        }

        default:{
          cout << endl << "Input tidak valid!";
          break;
        }
      }
    }
  }



  return 0;
}