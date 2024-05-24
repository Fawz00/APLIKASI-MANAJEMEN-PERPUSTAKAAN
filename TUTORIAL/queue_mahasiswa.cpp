#include <iostream>
#include <string>
using namespace std;

//=============================//
//          Q U E U E          //
//=============================//
#define N 10

struct Mahasiswa {
  int NIM;
  string nama;

  void print() {
    cout << nama << ", " << NIM << endl;
  }
};

struct Queue {
  int front = -1;
  int rear = -1;
  Mahasiswa* data = new Mahasiswa[N];

  bool isFull() {
    return rear == N-1;
  }
  bool isEmpty() {
    return (rear == -1 && front == -1);
  }

  void enQueue(Mahasiswa newData) {
    if(isEmpty()) {
      front = 0;
      rear = 0;
      data[0] = newData;
    } else if(isFull()) {
      cout << "Data sudah penuh!" << endl;
      exit(EXIT_FAILURE);
    } else {
      rear++;
      data[rear] = newData;
    }
  }
  Mahasiswa deQueue() {
    if(isEmpty()) {
      cout << "Data kosong!" << endl;
      exit(EXIT_FAILURE);
    } else {
      Mahasiswa temp = data[front];
      if(front >= rear) {
        front = -1;
        rear = -1;
      } else front++;
      return temp;
    }
  }
};

int main() {
  Queue antrian;
  //antrian.deQueue();
  antrian.enQueue({123,"person 0"});
  antrian.enQueue({234,"Michael"});
  antrian.enQueue({346,"Vienette"});
  antrian.enQueue({135,"A"});

  antrian.deQueue().print();
  antrian.deQueue().print();

  return 0;
}
