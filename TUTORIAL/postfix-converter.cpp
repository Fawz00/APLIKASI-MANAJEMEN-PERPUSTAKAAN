#include <iostream>
using namespace std;

#define MAX_STACK 1000

struct Stack
{
  int count = -1;
  char* data = new char[MAX_STACK];

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

  char pop() {
    if(isEmpty()) {
      cout << "The stack is empty." << endl;
      exit(EXIT_FAILURE);
    } else {
      char temp = data[count];
      count--;
      return temp;
    }
  }

  char top() {
    if(isEmpty()) {
      cout << "The stack is empty" << endl;
      exit(EXIT_FAILURE);
    } else
      return data[count];
  }
};

int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

int main() {
  string input;
  cout << "Masukkan Infix: ";
  getline(cin, input);

  Stack st;
  string result;
  for(int i=0; i<input.length(); i++) {
    char c = input[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;
    else if (c == '(')
      st.push('(');
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    } else {
      while (!st.isEmpty() && priority(input[i]) <= priority(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.isEmpty()) {
    result += st.top();
    st.pop();
  }
 
  cout << result << endl;

  return 0;
}