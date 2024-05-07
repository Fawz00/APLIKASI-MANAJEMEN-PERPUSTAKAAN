#ifndef DATA_H
#define DATA_H

  // BOOK
  struct book {
    long id;
    string title;
    string author;
    string publisher;
    int year;
  };
  long currentBookId = time(0)/100000;
  vector<book> bookData;

  // BORROWED BOOK
  struct borrowedBook {
    long bookId;
    string profileId;
    long borrowStartDate;
    long borrowDuration;
  };
  vector<borrowedBook> borrowedBooks;

  // PROFILE
  struct profile {
    string id;
    string name;
    bool superUser;
  };
  vector<profile> accounts;

  // DEFAULT VALUE
  void setDefaultBookData() {
    // ADD NEW BOOK      ID                TITLE   AUTHOR               PUBLISHER   YEAR
    bookData.push_back( {17642, "5 cm", "Donny Dhirgantoro", "Grasindo", 2005} );
    bookData.push_back( {currentBookId++, "Laskar Pelangi", "Andrea Hirata", "Bentang Pustaka", 2005} );
    bookData.push_back( {currentBookId++, "Kamus Populer Transportasi dan Logistik", "STMT Trisakti", "Penerbit Erlangga", 2011} );
    bookData.push_back( {currentBookId++, "Kota Semarang Dalam Kenangan", "Jongkie Tio", "J. Tio", 2001} );
    bookData.push_back( {currentBookId++, "Recent Corals of the Marshall Islands", "John West Wells", "U.S. Government Printing Office", 1954} );
    bookData.push_back( {currentBookId++, "Gojira King of the Monsters", "Jim Shepard", "Solid Objects", 2010} );
    bookData.push_back( {currentBookId++, "Electromagnetic Radiation from an Ionized Hydrogen Plasma", "S. R. Berman", "Physical Research Laboratory, Space Technology Laboratories", 1959} );
    bookData.push_back( {currentBookId++, "Cold Fusion Advances in Condensed Matter Nuclear Science", "Jean-Paul Biberian", "Elsevier Science", 2020} );
    bookData.push_back( {currentBookId++, "Multi-Objective Optimization using Artificial Intelligence Techniques", "Seyedali Mirjalili, Jin Song Dong", "Springer", 2023} );
    bookData.push_back( {17644, "Evolutionary Machine Learning Techniques Algorithms and Applications", "Seyedali Mirjalili, Hossam Faris, Ibrahim Aljarah", "Springer", 2020} );
  }
  void setDefaultAccountData() {
    // ADD ACCOUNT        USER ID       NAME                        ADMIN
    accounts.push_back( {"2304130169", "FAWWAZ HARYOLUKITO PAMBUDI", true} );
    accounts.push_back( {"2304130178", "MUHAMMAD ZUNIAR HILMI", true} );
    accounts.push_back( {"2304130140", "ISI", true} );
    accounts.push_back( {"2304130168", "ISI", true} );
  }
  void setDefaultBorrow() {
    int current_time = time(0);
    borrowedBooks.push_back( {17642, "2304130168", current_time-86400, 345600} );
    borrowedBooks.push_back( {17644, "2304130160", current_time-345600, 86400} );
  }

#endif //DATA_H