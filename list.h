#ifndef LIST
#define LIST

template <typename T> struct Node{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T> struct LinkedList{ // double linked list
  int length = 0;
  Node<T>* head = nullptr;
  Node<T>* tail = nullptr;

  void push_back(T n){
    Node<T>* temp = new Node<T>();
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
    length++;
  }

  void push_front(T n){
    Node<T>* temp = new Node<T>();
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
    length++;
  }

  void printForward(){
    Node<T>* current = head;
    while(current != nullptr){
      cout << current->data << ", ";
      current = current->next;
    }
    cout << endl;
  }

  void printBackward(){
    Node<T>* current = tail;
    while(current != nullptr){
      cout << current->data << ", ";
      current = current->prev;
    }
    cout << endl;
  }

  void removeFirst() {
    if(head != NULL) {
      Node<T>* current = head;
      head = current->next;
      delete current;
      length--;
    }
  }

  void removeLast() {
    if(tail != NULL) {
      Node<T>* current = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete current;
      length--;
    }
  }

  void remove(T flag) {
    Node<T>* current = head;
    Node<T>* prevCurrent = head;
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
    Node<T>* current = head;
    Node<T>* prevCurrent = head;
    Node<T>* tmp = new Node<T>();
    tmp->data = newData;
    bool found = false;

    if(flag == head->data) {
      found = true;
      push_back(newData);
    }

    while(current != NULL && !found) {
      if(current->data == flag) {
        tmp->prev = prevCurrent;
        tmp->next = current;
        prevCurrent->next = tmp;
        current->prev = tmp;
        found = true;
        length++;
      } else {
        prevCurrent = current;
        current = current->next;
      }
    }
  }

  void sort(bool inv) {
    push_front(0);
    bool swaped = false;

    while(!swaped) {
      Node<T>* curr = head->next->next;
      Node<T>* prev = head->next;
      Node<T>* prevprev = head;
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

  int size() {
    return length;
  }
};

#endif // LIST