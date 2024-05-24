#include <iostream>
using namespace std;

//====================================//
// Nama  : Fawwaz Haryolukito Pambudi //
// NIM   : 2304130169                 //
//====================================//

struct Node {
  int NIM;
  string nama;
  Node* next = NULL;
};

struct SingleLinkedList {
  Node* head = NULL;
  Node* tail = NULL;

  void pushBack(int _NIM, string _nama) {
    Node* tmp = new Node(); // Instance dari struct Node
    tmp->NIM = _NIM;
    tmp->nama = _nama;

    if(head == NULL) {
      head = tmp;
      tail = tmp;
    } else {
      tail->next = tmp;
      tail = tail->next;
    }
  }

  void pushFront(int _NIM, string _nama) {
    Node* curr = head;
    Node* tmp = new Node();
    tmp->NIM = _NIM;
    tmp->nama = _nama;

    if(head == NULL) {
      head = tmp;
      tail = tmp;
    } else {
      head = curr->next;
      tmp->next = curr;
      head = tmp;
    }
  }

  void print() {
    Node* curr = head;
    while(curr != NULL) {
      cout << curr->NIM << ": " << curr->nama << ", ";
      curr = curr->next;
    }
    cout << "\n";
  }

  void printBackward() {
    Node* curr = head;
    string res = "";
    while(curr != NULL) {
      res = to_string(curr->NIM) + ": " + curr->nama + ", " + res;
      curr = curr->next;
    }
    cout << res;
    cout << "\n";
  }

  void insertBefore(int NIM, int newNIM, string newNama) {
    Node* curr = head;
    Node* prev = head;
    Node* tmp = new Node();
    bool foundItem = false;
    tmp->NIM = newNIM;
    tmp->nama = newNama;

    if(NIM == prev->NIM) {
      tmp->next = head;
      head = tmp;
      foundItem = true;
    }

    while(curr != NULL && !foundItem) {
      if(curr->NIM == NIM) {
        prev->next = tmp;
        tmp->next = curr;
        foundItem = true;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void insertAfter(int NIM, int newNIM, string newNama) {
    Node* curr = head;
    Node* prev = head->next;
    Node* tmp = new Node();
    bool foundItem = false;
    tmp->NIM = newNIM;
    tmp->nama = newNama;

    if(NIM == tail->NIM) {
      tail->next = tmp;
      tail = tmp;
      foundItem = true;
    }

    while(curr != NULL && !foundItem) {
      if(prev->NIM == NIM) {
        prev->next = tmp;
        tmp->next = curr;
        curr = tmp;
        foundItem = true;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void removeLast() {
    Node* curr = head;
    Node* prev = head;
    bool foundItem = false;

    while(curr != NULL && !foundItem) {
      if(curr->next == NULL) {
        prev->next = NULL;
        tail = prev;
        delete curr;
        foundItem = true;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void removeFirst() {
    Node* curr = head;
    if(head != NULL) {
      head = curr->next;
      delete curr;
    }
  }

  void remove(int NIM) {
    Node* curr = head;
    Node* prev = head;
    bool foundItem = false;

    if(head->NIM == NIM) {
      removeFirst();
      foundItem = true;
    }

    while(curr != NULL && !foundItem) {
      if(curr->NIM == NIM) {
        prev->next = curr->next;
        delete curr;
        foundItem = true;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

};


int main() {
  SingleLinkedList ls;
  ls.pushBack(111, "Mark");
  ls.pushBack(132, "Mariya");
  ls.pushBack(404, "Fawwaz HP");
  ls.pushBack(432, "Alya");
  ls.print();
  ls.insertAfter(432, 201, "Lannyna");
  ls.print();
  ls.insertBefore(404, 122, "Dabro");
  ls.print();
  ls.removeLast();
  ls.print();
  ls.pushFront(696, "Pasha");
  ls.print();
  ls.printBackward();
  ls.removeFirst();
  ls.print();

  return 0;
}
