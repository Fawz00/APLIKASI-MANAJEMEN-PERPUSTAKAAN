#include <iostream>
#include <string>

using namespace std;

#define CHECK_INPUT_ERROR if(!cin){cin.clear();cin.ignore();}

int main(){
  float pa, pb, v, t, cV=0, cpa=0, cpb=0;

  cout << "Input volume of the pool:" << endl;
  cin >> v;
  CHECK_INPUT_ERROR
  cout << endl;

  cout << "Input first pipe water flow: (per hour)" << endl;
  cin >> pa;
  CHECK_INPUT_ERROR
  cout << endl;

  cout << "Input second pipe water flow: (per hour)" << endl;
  cin >> pb;
  CHECK_INPUT_ERROR
  cout << endl;

  cout << "Input time:" << endl;
  cin >> t;
  CHECK_INPUT_ERROR
  cout << endl;

  cV = (pa*t)+(pb*t);
  cpa = (pa*t)/cV;
  cpb = (pb*t)/cV;
  cV /= v;

  if( cV > 1.0 ){
    cout << "For " << t << " hour(s) the pool overflows with " << cV*v << " liters.";
  } else {
    cout << "The pool is " << cV*100.0 << "% full. Pipe 1: " << cpa*100.0 << "%. Pipe 2: " << cpb*100.0 << "%.";
  }

  return 0;
}
