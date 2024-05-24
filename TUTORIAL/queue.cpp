#include <iostream>
#include <string>
using namespace std;

//=============================//
//          Q U E U E          //
//=============================//
#define N 10

struct Queue {
  int front = -1;
  int rear = -1;
  string* data = new string[N];

  bool isFull() {
    return rear == N-1;
  }
  bool isEmpty() {
    return (rear == -1 && front == -1);
  }

  void enQueue(string newData) {
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
  string deQueue() {
    if(isEmpty()) {
      cout << "Data kosong!" << endl;
      exit(EXIT_FAILURE);
    } else {
      string temp = data[front];
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
  antrian.enQueue("person 0");
  antrian.enQueue("Michael");
  antrian.enQueue("Vienette");
  antrian.enQueue("A");
  cout << antrian.deQueue() << endl;
  cout << antrian.deQueue() << endl;

  return 0;
}
