#ifndef LIST
#define LIST

struct Map{
  int key;
  int value;
};

struct book {
  long id;
  string title;
  string author;
  string publisher;
  int year;
};

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

  void removeAt(int i) {
    Node<T>* current = head;

    if(i == 0) {
      removeFirst();
    }
    if(i == length-1) {
      removeLast();
    }

    for(int c=0; c<length && current != NULL; c++) {
      if(c == i) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        length--;
      } else {
        current = current->next;
      }
    }
  }

  bool contain(T flag) {
    Node<T>* current = head;

    if(flag == head->data) {
      return true;
    }

    while(current != NULL) {
      if(current->data == flag) {
        return true;
      } else {
        current = current->next;
      }
    }
    return false;
  }

  T get(int i) {
    Node<T>* current = head;

    for(int c=0; c<length && current != NULL; c++) {
      if(c == i) {
        return current->data;
      } else {
        current = current->next;
      }
    }
    return current->data;
  }

  void insertBefore(T flag, T newData) {
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

  int size() {
    return length;
  }
};

void sort(int n, Map data[], bool inv) { // shell sort
  int dst=n;
  while(dst>1) {
    dst=dst/2;
    bool don=true;
    while(don){
      don=false;
      for(int j=0; j<n-dst; j++){
        int i=j+dst;
        bool b = data[j].value > data[i].value;
        if(inv) b = data[j].value < data[i].value;
        if(b){
          Map temp = data[i];
          data[i] = data[j];
          data[j] = temp;
          don=true;
        }
      }
    }
  }
}

#endif // LIST