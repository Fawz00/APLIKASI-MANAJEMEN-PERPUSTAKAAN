#include <iostream>
#include <chrono>
#include <cstdint>
#include <string>
using namespace std;

int timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

struct Node {
  int data;
  Node* next = NULL;
};

struct SingleLinkedList {
  int length = 0;
  Node* head = NULL;
  Node* tail = NULL;

  void pushBack(int _data) {
    Node* tmp = new Node();
    tmp->data = _data;

    if(head == NULL) {
      head = tmp;
      tail = tmp;
    } else {
      tail->next = tmp;
      tail = tail->next;
    }
    length++;
  }

  void pushFront(int _data) {
    Node* curr = head;
    Node* tmp = new Node();
    tmp->data = _data;

    if(head == NULL) {
      head = tmp;
      tail = tmp;
    } else {
      head = curr->next;
      tmp->next = curr;
      head = tmp;
    }
    length++;
  }

  void printForward() {
    Node* curr = head;
    while(curr != NULL) {
      cout << curr->data << ", ";
      curr = curr->next;
    }
    cout << "\n";
  }

  void printBackward() {
    Node* curr = head;
    string res = "";
    while(curr != NULL) {
      res = to_string(curr->data) + ", " + res;
      curr = curr->next;
    }
    cout << res;
    cout << "\n";
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

  void insertBefore(int data, int newData) {
    Node* curr = head;
    Node* prev = head;
    Node* tmp = new Node();
    bool foundItem = false;
    tmp->data = newData;

    if(data == curr->data) {
      tmp->next = head;
      head = tmp;
      foundItem = true;
      length++;
    }

    while(curr != NULL && !foundItem) {
      if(curr->data == data) {
        prev->next = tmp;
        tmp->next = curr;
        foundItem = true;
        length++;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void insertAfter(int data, int newData) {
    Node* curr = head;
    Node* prev = head->next;
    Node* tmp = new Node();
    bool foundItem = false;
    tmp->data = newData;

    if(data == tail->data) {
      tail->next = tmp;
      tail = tmp;
      foundItem = true;
      length++;
    }

    while(curr != NULL && !foundItem) {
      if(prev->data == data) {
        prev->next = tmp;
        tmp->next = curr;
        curr = tmp;
        foundItem = true;
        length++;
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
        length--;
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
      length--;
    }
  }

  void remove(int data) {
    Node* curr = head;
    Node* prev = head;
    bool foundItem = false;

    if(head->data == data) {
      removeFirst();
      foundItem = true;
    }

    while(curr != NULL && !foundItem) {
      if(curr->data == data) {
        prev->next = curr->next;
        delete curr;
        length--;
        foundItem = true;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void fillRandom(int len) {
    for(int i=0; i<len; i++) {
      srand(timeSinceEpochMillisec()*i);
      pushBack(rand()%100);
    }
    
  }

};


int main() {
  SingleLinkedList ls;
  // ls.fillRandom(10000);

  // int startTime = timeSinceEpochMillisec();
  // ls.sort(false);
  // cout << "Time: " << timeSinceEpochMillisec()-startTime << " ms." << endl;
  // cout << ls.length << endl;

  ls.pushBack(4);
  ls.pushBack(2);
  ls.pushBack(16);
  ls.insertBefore(16, 90);
  ls.printForward();

  return 0;
}
