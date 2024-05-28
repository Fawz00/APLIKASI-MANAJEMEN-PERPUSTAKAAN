#include <iostream>
#include <chrono>
#include <cstdint>
using namespace std;

struct Node{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct DoubleLinkedList{
  int length = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  void pushBack(int n){
    Node* temp = new Node();
    temp -> data = n;
    if(head == nullptr){
      head = temp;
      tail = temp;
    } else{
      tail -> next = temp;
      temp -> prev = tail;
      tail = temp;
      temp -> next = nullptr;
    }
  }

  void pushFront(int n){
    Node* temp = new Node();
    temp -> data = n;
    if(head == nullptr){
      head = temp;
      tail = temp;
    } else{
      head -> prev = temp;
      temp -> next = head;
      head = temp;
      temp -> prev = nullptr;
    }
  }

  void printForward(){
    Node* current = head;
    while(current != nullptr){
      cout << current->data << ", ";
      current = current->next;
    }
    cout << endl;
  }

  void printBackward(){
    Node* current = tail;
    while(current != nullptr){
      cout << current->data << ", ";
      current = current->prev;
    }
    cout << endl;
  }

  void removeFirst() {
    if(head != NULL) {
      Node* current = head;
      head = current->next;
      delete current;
    }
  }

  void removeLast() {
    if(tail != NULL) {
      Node* current = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete current;
    }
  }

  void remove(int flag) {
    Node* current = head;
    Node* prevCurrent = head;
    bool found = false;

    if(flag == head->data) {
      found = true;
      removeFirst();
    }

    while(current != NULL && !found) {
      if(current->data == flag) {
        prevCurrent->next = current->next;
        current->next = current->prev;
        delete current;
        found = true;
      } else {
        prevCurrent = current;
        current = current->next;
      }
    }
  }

  void insertBefore(int flag, int newData) {
    Node* current = head;
    Node* prevCurrent = head;
    Node* tmp = new Node();
    tmp->data = newData;
    bool found = false;

    if(flag == head->data) {
      found = true;
      pushBack(newData);
    }

    while(current != NULL && !found) {
      if(current->data == flag) {
        tmp->prev = prevCurrent;
        tmp->next = current;
        prevCurrent->next = tmp;
        current->prev = tmp;
        found = true;
      } else {
        prevCurrent = current;
        current = current->next;
      }
    }
  }

  void sort(bool inv) {
    pushFront(0);
    bool swaped = false;

    while(!swaped) {
      Node* curr = head->next->next;
      Node* prev = head->next;
      Node* prevprev = head;
      swaped = true;
      while(curr != NULL) {
        bool check = prev->data > curr->data;
        if(inv) check = prev->data < curr->data;
        if(check) {
          swaped = false;
          prev->next = curr->next;
          curr->next = prev;
          prevprev->next = curr;
        }
        prevprev = prev;
        prev = curr;
        curr = curr->next;
      }
    }
    removeFirst();
  }

  int timeSinceEpochMillisec() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  }

  void fillRandom(int len) {
    for(int i=0; i<len; i++) {
      srand(timeSinceEpochMillisec()*i);
      pushBack(rand()%100);
    }
  }
};

int main(){
    DoubleLinkedList ls;
    ls.fillRandom(10);
    ls.sort(false);
    ls.printForward();
}
