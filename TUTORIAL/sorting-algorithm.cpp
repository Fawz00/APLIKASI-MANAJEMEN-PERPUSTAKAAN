#include <iostream>
#include <chrono>
#include <cstdint>
using namespace std;

uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void printArray(int n, int data[]) {
  for(int i=0; i<n; i++) cout << data[i] << ", ";
  cout << endl;
}

void genRandomArray(int n, int data[]) {
  for(int i=0; i<n; i++){
    data[i]=rand()%100;
  }
}

void bubbleSort(int n, int data[], bool inv) {
  bool swaped = false;
   while(!swaped){
    swaped = true;
    for(int i=1; i<n; i++){
      bool check = data[i-1] > data[i];
      if(inv) check = data[i-1] < data[i];
      if(check) {
        swaped = false;
        int temp = data[i];
        data[i] = data[i-1];
        data[i-1] = temp;
      }
    }
  }
}

void selectionSort(int n, int data[], bool inv) {
  for(int i=0; i<n; i++){
    for(int j=1; j<=n; j++){
      if(data[i]>data[j]){
        int temp = data[j];
        data[j] = data[i];
        data[i] = temp;
      }
    }
  }
}

void insertionSort(int n, int data[], bool inv) {
  for(int i=1; i<n; i++) {
    int key=data[i];
    int j;
    for(j=i-1; j>=0 && data[j]>key; j--) {
      data[j+1]=data[j];
    }
    data[j+1]=key;
  }
}

void shellSort(int n, int data[], bool inv) {
  int dst=n;
  while(dst>1) {
    dst=dst/2;
    bool don=true;
    while(don){
      don=false;
      for(int j=0; j<n-dst; j++){
        int i=j+dst;
        if(data[j]>data[i]){
          int temp = data[i];
          data[i] = data[j];
          data[j] = temp;
          don=true;
        }
      }
    }
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

int main() {
  int len = 100000;
  int data[len];
  int res[len];
  genRandomArray(len, data);

  printArray(len, data);
  uint64_t startTime = timeSinceEpochMillisec();
  mergeSort(data, res, 0, len-1);
  uint64_t t = timeSinceEpochMillisec()-startTime;
  printArray(len, data);

  cout << "Time: " << t << " ms." << endl;
  
  return 0;
}