#include <iostream>
using namespace std;

#define MAX_STACK 100

struct Stack
{
  int count = -1;
  int* data = new int[MAX_STACK];

  bool isEmpty() {
    return (count == -1);
  }
  bool isFull() {
    return (count == MAX_STACK);
  }

  void push(int input) {
    if(isFull()) {
      cout << "The stack is already Full." << endl;
    } else {
      count++;
      data[count] = input;
    }
  }

  int pop() {
    if(isEmpty()) {
      cout << "The stack is empty." << endl;
      exit(EXIT_FAILURE);
    } else {
      int temp = data[count];
      count--;
      return temp;
    }
  }

  int top() {
    if(isEmpty()) {
      cout << "The stack is empty" << endl;
      exit(EXIT_FAILURE);
    } else
      return data[count];
  }
};


int main() {
  Stack st;
  st.push(500);
  st.push(-1);
  st.push(0);
  
  cout << st.top() << endl;
  cout << st.pop() << endl;
  cout << st.pop() << endl;
  cout << st.pop() << endl;

  return 0;
}