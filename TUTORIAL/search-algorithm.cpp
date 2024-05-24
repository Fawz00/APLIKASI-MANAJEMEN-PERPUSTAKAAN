#include <iostream>
using namespace std;

void printArray(int n, int data[]) {
  for(int i=0; i<n; i++) cout << data[i] << ", ";
  cout << endl;
}

void genRandomArray(int n, int data[]) {
  for(int i=0; i<n; i++){
    srand(i);
    data[i]=rand()%100;
  }
}

void mergeSortMerge(int data[], int aux[], int a, int m, int b) {
  int l1 = a;
  int u1 = m;
  int l2 = m+1;
  int u2 = b;
  int k = l1;

  while(l1<=u1 && l2<=u2) {
    if(data[l1] < data[l2]) {
      aux[k] = data[l1];
      l1 = l1 + 1;
    } else {
      aux[k] = data[l2];
      l2 = l2 + 1;
    }
    k = k + 1;
  }

  while(l1<=u1) {
    aux[k] = data[l1];
    l1 = l1 + 1;
    k = k + 1;
  }

  while(l2<=u2) {
    aux[k] = data[l2];
    l2 = l2 + 1;
    k = k + 1;
  }
  k = a;

  while(k <=b) {
    data[k] = aux[k];
    k = k + 1;
  }
}
void mergeSort(int data[], int res[], int a, int b) {
  if(a<b) {
    int m = (a+b)/2;
    mergeSort(data, res, a, m);
    mergeSort(data, res, m+1, b);
    mergeSortMerge(data, res, a, m, b);
  }
}



void sequentialSearch(int n, int data[], int s) {
    int count = 0;
    string found = "";
    for(int i=0; i<n; i++) {
        if(data[i] == s) {
            found += to_string(i) + " ";
            count++;
        }
    }
    if(count > 0) {
        cout << "Found " << count << " item(s), at " + found + "." << endl;
    } else {
        cout << "Data not found." << endl;
    }
}

void binarySearch(int n, int data[], int s) {
    int l = 0;
    int r = n-1;
    while(l <= r) {
        int m = (l+r)/2;
        int d = data[m];
        if(d == s) {
            cout << "Data found at index " << m << "." << endl;
            return; // true;
        }
        if(s < d) r = m-1;
        if(s > d) l = m+1;
    }
    cout << "Data not found." << endl;
    // return false;
}

int main() {
    int len = 20;
    int data[len];
    genRandomArray(len, data);

    mergeSort(data, new int[len], 0, len-1);
    printArray(len, data);
    binarySearch(len, data, 41);

    return 0;
}