#ifndef DISPLAY_H
#define DISPLAY_H

  int screenWidth = 100;
  int screenHeight = 15;
  #define CHECK_INPUT if(!cin){cin.clear();cin.ignore();}

  #define DENDA_TERLAMBAT 0.2F
  #define DENDA_HILANG 0.8F
  #define DENDA_RUSAK 0.4F

  string addSpaceTab(string a, string c, int b) {
    b = b>screenWidth ? screenWidth : b;
    string d = "";
    int e = b - a.size();
    if(e < 0) e = 0;

    for(int i=0; i<e; i++) {
      d = d+c;
    }
    return a+d;
  }
  string fixedText(string a, int size) {
    string output = a;
    if(a.size()>size) {
      output = a.substr(0,size);
      output[size-1] = '.';
      output[size-2] = '.';
      output[size-3] = '.';
    }
    return output;
  }
  string decStr(float a, int b) {
    int intPart = (int)a;
    float decimalPart = a - intPart;
    string result = to_string(intPart);
    if (b > 0) {
        result += ".";
        for (int i = 0; i < b; ++i) {
            decimalPart *= 10;
            int digit = (int)decimalPart;
            result += to_string(digit);
            decimalPart -= digit;
        }
    }
    return result;
  }
  void clearScreen() {
    // Windows: CLS
    // Linux  : CLEAR
    system("cls");
  }
  void showList(const string* list, int size) {
    for(int i=1; i<=size; i++) {
      cout << addSpaceTab(to_string(i)+". ", " ", 4) << list[i-1] << endl;
    }
  }
  

  void pause() {
    cout << endl << "Masukkan 1 untuk melanjutkan." << endl;
    int cache;
    cin >> cache;
    cin.ignore();
  }

  void showTitle(string t) {
    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" "+t+" ", " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl << endl;
  }

  profile getAccountFromId(string id) {
    for(int i=0; i<accounts.size(); i++) {
      if( accounts.get(i).id == id ) {
        return accounts.get(i);
        break;
      }
    }
    return {"", "", false};
  }



  //=====================================================//
  //                    S C R E E N S                    //=====================================================
  //=====================================================//
  void loginScreen();
  void redirectScreen(string);
  void adminScreen(string);
  void userScreen(string);

  // Show All Book
  // ===========================================================================================================

  void showAllBooks() {
    clearScreen();

    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" Daftar koleksi buku ", " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl << endl;

    cout << addSpaceTab("Kode", " ", 6) << addSpaceTab("Judul", " ", 38) << addSpaceTab("Pengarang", " ", 20) << addSpaceTab("Penerbit", " ", 20) << addSpaceTab("Tahun", " ", 6) << addSpaceTab("Ket.", " ", 10) << endl;
    cout << addSpaceTab("", "-", 100) << endl;
    for(int i=0; i<bookData.size(); i++) {
      book currentBook = bookData.get(i);
      bool isBorrowed = false;
      for(int j=0; j<borrowedBooks.size(); j++) {
        if( borrowedBooks.get(j).bookId == bookData.get(i).id ) {
          isBorrowed = true;
          break;
        }
      }
      cout << addSpaceTab(to_string(currentBook.id).substr(0,5), " ", 6) << addSpaceTab(fixedText(currentBook.title,37), " ", 38) << addSpaceTab(fixedText(currentBook.author,19), " ", 20) << addSpaceTab(fixedText(currentBook.publisher,19), " ", 20) << addSpaceTab(to_string(currentBook.year), " ", 6) << addSpaceTab( isBorrowed?"Dipinjam":"" , " ", 10) << endl;
    }
  }

  void showAllBooksSorted(string type, bool inv) {
    Map tmp[bookData.size()];

    if(type == "tahun") {
      for(int i=0; i<bookData.size(); i++) {
        tmp[i] = {i, bookData.get(i).year};
      }
    }else if(type == "id") {
      for(int i=0; i<bookData.size(); i++) {
        tmp[i] = {i, bookData.get(i).id};
      }
    }
    sort(bookData.size(), tmp, false);

    clearScreen();

    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" Daftar koleksi buku ", " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl << endl;

    cout << addSpaceTab("Kode", " ", 6) << addSpaceTab("Judul", " ", 38) << addSpaceTab("Pengarang", " ", 20) << addSpaceTab("Penerbit", " ", 20) << addSpaceTab("Tahun", " ", 6) << addSpaceTab("Ket.", " ", 10) << endl;
    cout << addSpaceTab("", "-", 100) << endl;
    for(int i=0; i<bookData.size(); i++) {
      book currentBook = bookData.get(tmp[i].key);
      bool isBorrowed = false;
      for(int j=0; j<borrowedBooks.size(); j++) {
        if( borrowedBooks.get(j).bookId == bookData.get(tmp[i].key).id ) {
          isBorrowed = true;
          break;
        }
      }
      cout << addSpaceTab(to_string(currentBook.id).substr(0,5), " ", 6) << addSpaceTab(fixedText(currentBook.title,37), " ", 38) << addSpaceTab(fixedText(currentBook.author,19), " ", 20) << addSpaceTab(fixedText(currentBook.publisher,19), " ", 20) << addSpaceTab(to_string(currentBook.year), " ", 6) << addSpaceTab( isBorrowed?"Dipinjam":"" , " ", 10) << endl;
    }
  }

  void showAllBorrowedBooks(string userId) {
    clearScreen();

    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" Daftar buku yang dipinjam ", " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl << endl;

    cout << addSpaceTab("Kode buku", " ", 12) << addSpaceTab("Judul Buku", " ", 50) << addSpaceTab("Sisa waktu", " ", 15) << addSpaceTab("Denda", " ", 12) << endl;
    cout << addSpaceTab("", "-", 100) << endl;

    for(int i=0; i<borrowedBooks.size(); i++) {
      if(borrowedBooks.get(i).profileId == userId) {
        string bookTitle;
        long bookId = borrowedBooks.get(i).bookId;
        float dur;
        float pay = 0.0F;

        for (int j = 0; j<bookData.size(); j++) {
          if( bookData.get(j).id == borrowedBooks.get(i).bookId ) {
            bookTitle = bookData.get(i).title;
            break;
          }
        }

        // calc duration
        int current_time = time(0);
        dur = (float)((borrowedBooks.get(i).borrowStartDate+borrowedBooks.get(i).borrowDuration)-current_time)/86400.0F;
        if(dur < 0) {
          pay = -dur * DENDA_TERLAMBAT;
        }

        cout << addSpaceTab(to_string(bookId).substr(0,11), " ", 12) << addSpaceTab(fixedText(bookTitle,49), " ", 50) << addSpaceTab(fixedText(decStr(dur,1)+" hari",14), " ", 15) << addSpaceTab(fixedText("$ "+decStr(pay,2),11), " ", 12) << endl;
      }
    }
  }

  // Register Screen
  // ===========================================================================================================

  void registerScreen(profile *account) {
    clearScreen();
    int answer;

    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" BUAT PROFIL BARU ", " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl << endl;

    cout << "Profil belum ada, buat profil baru:" << endl;
    cout << endl;
    cout << addSpaceTab("NIM / NIP", " ", 18) << ": " << account->id << endl;
    cout << addSpaceTab("Nama", " ", 18) << ": ";
    getline(cin, account->name);
    cout << addSpaceTab("Super User access [1=Ya | 0=Tidak]", " ", 18) << ": ";
    answer = -256;
    while(answer<0 || answer>1){
      if(answer!=-256) cout << "Input tidak valid!" << endl;
      cin >> answer;
      cin.get();
      CHECK_INPUT
    }
    if(answer==1) {
      account->superUser = true;
    } else account->superUser = false;
    cout << endl;
    cout << addSpaceTab("Simpan perubahan? [1=Ya | 0=Tidak]", " ", 10) << ": ";
    answer = -256;
    while(answer<0 || answer>1){
      if(answer!=-256) cout << "Input tidak valid!" << endl;
      cin >> answer;
      cin.get();
      CHECK_INPUT
    }
    if(answer==1) {
      accounts.push_back(*account);
      redirectScreen(account->id);
    } else loginScreen();
  }

  // Login Screen
  // ===========================================================================================================

  void loginScreen() {
    clearScreen();

    profile currentProfile;
    bool accountAvailable = false;

    // cout << addSpaceTab("", "=", 100) << endl;
    // cout << addSpaceTab(" PERPUSTAKAAN ", " ", 100) << endl;
    // cout << addSpaceTab("", "=", 100) << endl << endl;
    showTitle("PERPUSTAKAAN");

    cout << "Log in untuk melanjutkan" << endl;
    string selection[] = {
      "Log in",
      "Keluar aplikasi"
    };
    int n = sizeof(selection)/sizeof(string);
    showList(selection, n);

    cout << endl;
    cout << "Masukkan pilihan: ";
    int answer = -1;
    cin >> answer;
    cin.get();
    CHECK_INPUT

    switch (answer) {
      case 1: {
        cout << "Masukkan NIM / NIP: ";
        getline(cin, currentProfile.id);

        for(int i=0; i<accounts.size(); i++) {
          if( accounts.get(i).id == currentProfile.id ) {
            accountAvailable = true;
            break;
          }
        }

        if(!accountAvailable) {
          registerScreen(&currentProfile);
        } else redirectScreen(currentProfile.id);

        break;
      }

      case 2: {
        clearScreen();
        return;
        break;
      }
    
    default: {
        cout << "Input tidak valid!";
        pause();
        loginScreen();
        break;
      }
    }

  }

  // Redirect Screen
  // ===========================================================================================================

  void redirectScreen(string profileId){
    profile account = getAccountFromId(profileId);
    clearScreen();
    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" Halo, " + account.name + "! ", " ", 100) << endl;
    cout << addSpaceTab("z", "=", 100) << endl;
    cout << endl;
    if(account.superUser) {
      cout << "Masuk sebagai" << endl;
      string selection[] = {
        "Admin",
        "Pengguna",
        "Log out"
      };
      int n = sizeof(selection)/sizeof(string);
      showList(selection, n);

      cout << endl;
      cout << "Masukkan pilihan: ";
      int answer = -1;
      cin >> answer;
      cin.get();
      CHECK_INPUT
      switch (answer) {
        case 1:
          // ADMIN
          adminScreen(profileId);
          break;
        
        case 2:
          // USER
          userScreen(profileId);
          break;
        
        case 3:
          loginScreen();
          break;
        
        default:
          cout << "Input tidak valid!";
          pause();
          redirectScreen(profileId);
          break;
      }

    } else {
      // Jumbotron "Selamat datang!"
      cout << " _____      _                       _         _       _                    _ \n/  ___|    | |                     | |       | |     | |                  | |\n\\ `--.  ___| | __ _ _ __ ___   __ _| |_    __| | __ _| |_ __ _ _ __   __ _| |\n `--. \\/ _ \\ |/ _` | '_ ` _ \\ / _` | __|  / _` |/ _` | __/ _` | '_ \\ / _` | |\n/\\__/ /  __/ | (_| | | | | | | (_| | |_  | (_| | (_| | || (_| | | | | (_| |_|\n\\____/ \\___|_|\\__,_|_| |_| |_|\\__,_|\\__|  \\__,_|\\__,_|\\__\\__,_|_| |_|\\__, (_)\n                                                                      __/ |  \n                                                                     |___/   " << endl;
      pause();
      userScreen(profileId);
    }
  }

  // ADMIN
  // ===========================================================================================================
  
  void adminScreen(string accId) {
    profile account = getAccountFromId(accId);
    clearScreen();
    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" Masuk sebagai admin. " + account.name, " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl;
    cout << endl;
    cout << "Pilih aksi" << endl;
    string selection[] = {
      "Lihat daftar koleksi buku",
      "Tambahkan buku koleksi",
      "Edit buku koleksi",
      "Hapus buku pada koleksi",
      "Lihat daftar peminjam",
      "Keluar"
    };
    int n = sizeof(selection)/sizeof(string);
    showList(selection, n);

    cout << endl;
    cout << "Masukkan pilihan: ";
    int answer = -1;
    cin >> answer;
    cin.get();
    CHECK_INPUT
    switch (answer) {
      case 1: {
        // Show all book
        showAllBooksSorted("tahun", false);
        pause();
        adminScreen(accId);
        break;
      }
      
      case 2: {
        // Add new book to the collection
        clearScreen();
        cout << addSpaceTab("", "=", 100) << endl;
        cout << addSpaceTab(" Tambahkan buku ke koleksi ", " ", 100) << endl;
        cout << addSpaceTab("", "=", 100) << endl;

        string newTitle;
        cout << "Judul: ";
        getline(cin, newTitle);

        string newAuthor;
        cout << "Pengarang: ";
        getline(cin, newAuthor);

        string newPublisher;
        cout << "Penerbit: ";
        getline(cin, newPublisher);

        int newYear = 1997;
        cout << "Tahun terbit: ";
        cin >> newYear;
        cin.get();
        CHECK_INPUT

        bookData.push_back( {currentBookId++, newTitle, newAuthor, newPublisher, newYear} );
        adminScreen(accId);
        break;
      } 

      case 3 : { 
        //edit buku 
        clearScreen();
        cout << addSpaceTab("", "=", 100) << endl;
        cout << addSpaceTab(" Edit buku koleksi ", " ", 100) << endl;
        cout << addSpaceTab("", "=", 100) << endl;

        showAllBooksSorted("tahun", false);
        cout << "\n";

        long id_;
        cout << "Masukkan id buku: ";
        cin >> id_;
        cin.get();
        CHECK_INPUT

        string newTitle;
        cout << "Judul: ";
        getline(cin, newTitle);

        string newAuthor;
        cout << "Pengarang: ";
        getline(cin, newAuthor);

        string newPublisher;
        cout << "Penerbit: ";
        getline(cin, newPublisher);

        int newYear = 1997;
        cout << "Tahun terbit: ";
        cin >> newYear;
        cin.get();
        CHECK_INPUT

        bool finished = false;
        bool isBorrowed = false;
        for(int i=0; i<borrowedBooks.size(); i++) {
          if(borrowedBooks.get(i).bookId == id_) {
            isBorrowed = true;
            break;
          }
        }
        if(!isBorrowed) {
          for(int i=0; i<bookData.size(); i++) {
            if( bookData.get(i).id == id_ ) {
              bookData.removeAt( i );
              finished = true;
              break;
            }
          }
          bookData.push_back( {id_, newTitle, newAuthor, newPublisher, newYear} );
          showAllBooks();
          cout << endl;
          if(!finished) {
            cout << "Error, kode buku tidak ditemukan.";
            pause();
          } else {
            cout << "Buku berhasil diubah.";
            pause();
          }
        }

        adminScreen(accId);
        break;
      }

      case 4: {
        // Remove book from collection
        showAllBooks();

        long bookId = -1;
        cout << endl << "Kode buku yang akan dihapus: ";
        cin >> bookId;
        cin.get();
        CHECK_INPUT
        bool finished = false;
        bool isBorrowed = false;
        for(int i=0; i<borrowedBooks.size(); i++) {
          if(borrowedBooks.get(i).bookId == bookId) {
            isBorrowed = true;
            break;
          }
        }
        if(!isBorrowed) {
          for(int i=0; i<bookData.size(); i++) {
            if( bookData.get(i).id == bookId ) {
              bookData.removeAt( i );
              finished = true;
              break;
            }
          }
          showAllBooks();
          cout << endl;
          if(!finished) {
            cout << "Error, kode buku tidak ditemukan.";
            pause();
          } else {
            cout << "Buku berhasil dihapus.";
            pause();
          }
        } else {
          showAllBooks();
          cout << endl;
          cout << "Tidak dapat menghapus buku, buku sedang dipinjam.";
          pause();
        }
        adminScreen(accId);
        break;
      }

      case 5: {
        // Lihat daftar peminjam
        clearScreen();
        cout << addSpaceTab("", "=", 100) << endl;
        cout << addSpaceTab(" Daftar Peminjam ", " ", 100) << endl;
        cout << addSpaceTab("", "=", 100) << endl << endl;

        cout << addSpaceTab("NIM / NIP", " ", 12) << addSpaceTab("Nama", " ", 32) << addSpaceTab("Kode buku", " ", 11) << addSpaceTab("Judul Buku", " ", 35) << addSpaceTab("Sisa waktu", " ", 10) << endl;
        cout << addSpaceTab("", "-", 100) << endl;

        for (int i=0; i<borrowedBooks.size(); i++) {
          string bookTitle;
          long bookId = borrowedBooks.get(i).bookId;
          string name;
          float dur; // in day

          //find profile name by id
          for (int j = 0; j<accounts.size(); j++) {
            if( accounts.get(j).id == borrowedBooks.get(i).profileId ) {
              name = accounts.get(j).name;
              break;
            }
          }

          //find book title by id
          for (int j = 0; j<bookData.size(); j++) {
            if( bookData.get(j).id == bookId ) {
              bookTitle = bookData.get(j).title;
              break;
            }
          }

          // calc duration
          int current_time = time(0);
          dur = (float)((borrowedBooks.get(i).borrowStartDate+borrowedBooks.get(i).borrowDuration)-current_time)/86400.0F;

          // Show to screen
          cout << addSpaceTab(borrowedBooks.get(i).profileId.substr(0,11), " ", 12) << addSpaceTab(fixedText(name,31), " ", 32) << addSpaceTab(fixedText(to_string(bookId),10), " ", 11) << addSpaceTab(fixedText(bookTitle,34), " ", 35) << addSpaceTab(fixedText(decStr(dur,1)+" hari",9), " ", 10) << endl;

        } 
        adminScreen(accId);
        break;
      }

      case 6: {
        // Exit
        redirectScreen(accId);
        break;
      }
      
      default: {
        cout << "Input tidak valid!";
        pause();
        adminScreen(accId);
        break;
      }
    }
  }

  // USER
  // ===========================================================================================================

  void userScreen(string profileId) {
    profile account = getAccountFromId(profileId);
    clearScreen();
    cout << addSpaceTab("", "=", 100) << endl;
    cout << addSpaceTab(" P E R P U S T A K A A N ", " ", 100) << endl;
    cout << addSpaceTab("", "=", 100) << endl;
    cout << "Log in sebagai " << account.name << "." << endl << endl;

    cout << "Pilih aksi" << endl;
    string selection[] = {
      "Lihat daftar koleksi buku",
      "Lihat buku yang dipinjam",
      "Pinjam buku",
      "Kembalikan buku",
      "Laporkan hilang / rusak",
      "Keluar"
    };
    int n = sizeof(selection)/sizeof(string);
    showList(selection, n);

    cout << endl;
    cout << "Masukkan pilihan: ";
    int answer = -1;
    cin >> answer;
    cin.get();
    CHECK_INPUT
    switch (answer) {
      case 1: {
        // Show all book
        showAllBooks();
        pause();
        userScreen(profileId);
        break;
      }

      case 2: {
        showAllBorrowedBooks(profileId);
        pause();
        userScreen(profileId);
        break;
      }

      case 3: {
        //Borrow
        showAllBooks();

        long bookId = -1;
        cout << endl << "Kode buku yang akan dipinjam: ";
        cin >> bookId;
        cin.get();
        CHECK_INPUT

        int finished = -1;
        if(finished==-1) for(int i=0; i<bookData.size(); i++) {
          if(finished==-1) for(int j=0; j<borrowedBooks.size(); j++) {
            if(borrowedBooks.get(j).bookId != bookId) {
              if( bookData.get(i).id == bookId ) {
                long current_time = time(0);
                borrowedBooks.push_back( {bookId, profileId, current_time, 1209600L} );
                finished = 1;
                break;
              }
            } else {
              finished = 0;
              break;
            }
          }
        }
        showAllBooks();
        cout << endl;
        if(finished == -1) {
          cout << "Error, kode buku tidak ditemukan.";
          pause();
        } else if(finished == 1){
          cout << "Peminjaman berhasil dilakukan.";
          pause();
        } else {
          cout << "Gagal meminjam buku, buku sedang dipinjam.";
          pause();
        }

        userScreen(profileId);
        break;
      }

      case 4: {
        // Returning
        showAllBorrowedBooks(profileId);
        cout << endl;

        long bookId = -1;
        cout << "Kode buku yang akan dikembalikan: ";
        cin >> bookId;
        cin.get();
        CHECK_INPUT

        float pay = 0.0F;
        bool finished = false;
        for(int i=0; i<borrowedBooks.size(); i++) {
          if(borrowedBooks.get(i).profileId == profileId) {
            if(borrowedBooks.get(i).bookId == bookId) {
              long current_time = time(0);
              float dur = (float)((borrowedBooks.get(i).borrowStartDate+borrowedBooks.get(i).borrowDuration)-current_time)/86400.0F;
              if(dur < 0) {
                pay = -dur * DENDA_TERLAMBAT;
              }
              borrowedBooks.removeAt( i );
              finished = true;
              break;
            }
          }
        }
        showAllBorrowedBooks(profileId);
        cout << endl;
        if(!finished) {
          cout << "Error, kode buku tidak ditemukan.";
          pause();
        } else {
          cout << "Buku berhasil dikembalikan.";
          if(pay > 0.0F) {
            cout << endl << "Jangan lupa bayar denda sebesar: $" << decStr(pay,2) << " .";
          }
          pause();
        }
        userScreen(profileId);
        break;
      }

      case 5: {
        // Lapor hilang / rusak
        showAllBorrowedBooks(profileId);
        cout << endl;

        float pay = 0.0F;

        long bookId = -1;
        cout << "Kode buku pinjaman yang hilang atau rusak: ";
        cin >> bookId;
        cin.get();
        CHECK_INPUT

        bool finished = false;
        for(int i=0; i<borrowedBooks.size(); i++) {
          if( borrowedBooks.get(i).profileId == profileId && borrowedBooks.get(i).bookId == bookId) {
            finished = true;

            cout << endl << "1. Hilang" << endl;
            cout << "2. Rusak" << endl;
            int type = -1;
            cout << "Masukkan pilihan: ";
            cin >> type;
            cin.get();
            CHECK_INPUT
            if(type == 1) {
              pay = DENDA_HILANG;
            } else if(type == 2){
              pay = DENDA_RUSAK;
            } else finished = false;

            // calc duration
            int current_time = time(0);
            float dur = (float)((borrowedBooks.get(i).borrowStartDate+borrowedBooks.get(i).borrowDuration)-current_time)/86400.0F;
            if(dur < 0) {
              pay += -dur * DENDA_TERLAMBAT;
            }

            if(finished) {
              borrowedBooks.removeAt( i );
              for(int j=0; j<bookData.size(); j++) {
                if( bookData.get(j).id == bookId ) {
                  bookData.removeAt( j );
                  break;
                }
              }
            }

            break;
          }
        }

        showAllBorrowedBooks(profileId);
        cout << endl;

        if(!finished) {
          cout << "Error, input tidak valid.";
          pause();
        } else {
          cout << "Denda yang harus dibayar: $" << decStr(pay, 2) << " .";
          pause();
        }

        userScreen(profileId);
        break;
      }

      case 6: {
        if( account.superUser ) {
          redirectScreen(profileId);
        } else loginScreen();
        break;
      }
    
      default: {
        cout << "Input tidak valid!";
        pause();
        userScreen(profileId);
        break;
      }
    }
  }

#endif //DISPLAY_H
