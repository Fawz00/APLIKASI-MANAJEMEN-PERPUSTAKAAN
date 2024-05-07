#include <iostream>
using namespace std;

#define CHECK_INPUT_ERROR if(!cin){cin.clear();cin.ignore();}

int main(){
	int month, days;
	float price_a=0.0, price_s=0.0, discount_a=0.0, discount_s=0.0, cost_a=0.0, cost_s=0.0;



	//=============================================//
	//          I N P U T   S E C T I O N          //
	//=============================================//

	cout	<< "Input duration\n";
	cout	<< "Month (in number):";
	cin >> month;
	CHECK_INPUT_ERROR
	cout	<< "How many days:";
	cin >> days;
	CHECK_INPUT_ERROR
	cout << endl;

	if(month == 5 || month == 10){
		price_s = 50.0;
		price_a = 65.0;
		discount = (type==1 && days>14) ? 30 : ((type==1 && days>7) ? 5 : 0);
	}else if(month == 6 || 9){
		price = (type==1) ? 75.2 : 68.7;
		discount = (type==1 && days>14) ? 20 : 0;
	}else if(month == 7 || month == 8){
		price = (type==1) ? 76.0 : 77;
	}

	discount = (type==2 && days>14) ? 10 : 0;
	discount /= 100.0;
	cost = price * days;
	cost -= discount * price;

	cout << cost;
	

	return 0;
}