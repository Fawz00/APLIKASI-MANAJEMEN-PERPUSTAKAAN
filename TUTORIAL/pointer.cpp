#include<iostream>
using namespace std;

// Fungsi untuk Pass By Value
void passByValue(int iNumber, float fNumber, char cChar) {
  printf("\nPass By Value:\n");
  printf("iNumber (sebelum): %a\n", iNumber);
  printf("fNumber (sebelum): %a\n", fNumber);
  printf("cChar (sebelum)  : %a\n", cChar);

  iNumber = 10;
  fNumber = 5.5;
  cChar = 'B';

  printf("iNumber (setelah): %a\n", iNumber);
  printf("fNumber (setelah): %a\n", fNumber);
  printf("cChar (setelah)  : %a\n", cChar);
}

// Fungsi untuk Pass By Reference
void passByReference(int &iNumber, float &fNumber, char &cChar) {
  printf("\nPass By Reference:\n");
  printf("iNumber (sebelum): %a\n", iNumber);
  printf("fNumber (sebelum): %a\n", fNumber);
  printf("cChar (sebelum)  : %a\n", cChar);

  iNumber = 20;
  fNumber = 7.7;
  cChar = 'C';

  printf("iNumber (setelah): %a\n", iNumber);
  printf("fNumber (setelah): %a\n", fNumber);
  printf("cChar (setelah)  : %a\n", cChar);
}

int main() {
  // Deklarasi pointer variable
  int* iPtr;
  char* cPtr;
  float* fPtr;

  // Deklarasi non-pointer variables
  int iNumber = 5;
  char cChar = 'A';
  float fNumber = 3.14;

  // Assign alamat non-pointer variables ke pointer variables
  iPtr = &iNumber;
  cPtr = &cChar;
  fPtr = &fNumber;

  // Print nilai dari tiap variable pointer dan non-pointer
  cout << "Nilai dari iNumber: " << iNumber << endl;
  cout << "Nilai dari cChar: " << cChar << endl;
  cout << "Nilai dari fNumber: " << fNumber << endl;

  cout << "Nilai dari *iPtr: " << *iPtr << endl;
  cout << "Nilai dari *cPtr: " << *cPtr << endl;
  cout << "Nilai dari *fPtr: " << *fPtr << endl;

  // Print alamat dari tiap variable pointer dan non-pointer
  cout << "Alamat dari iNumber: " << &iNumber << endl;
  cout << "Alamat dari cChar: " << (void*)&cChar << endl; // casting ke void pointer karena cChar adalah char
  cout << "Alamat dari fNumber: " << &fNumber << endl;

  cout << "Alamat dari iPtr: " << iPtr << endl;
  cout << "Alamat dari cPtr: " << (void*)cPtr << endl; // casting ke void pointer karena cPtr adalah char*
  cout << "Alamat dari fPtr: " << fPtr << endl;

  // Panggil fungsi dengan Pass By Value
  passByValue(iNumber, fNumber, cChar);

  // Print nilai setelah pemanggilan fungsi Pass By Value
  cout << "\nNilai setelah pemanggilan fungsi Pass By Value:\n";
  cout << "iNumber: " << iNumber << endl;
  cout << "fNumber: " << fNumber << endl;
  cout << "cChar: " << cChar << endl;

  // Panggil fungsi dengan Pass By Reference
  passByReference(iNumber, fNumber, cChar);

  // Print nilai setelah pemanggilan fungsi Pass By Reference
  cout << "\nNilai setelah pemanggilan fungsi Pass By Reference:\n";
  cout << "iNumber: " << iNumber << endl;
  cout << "fNumber: " << fNumber << endl;
  cout << "cChar: " << cChar << endl;

  return 0;
}
