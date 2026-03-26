#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"

using namespace std;

int main(){
	Time t;
	cout << "Initial Time is 00:00:00 AM" << endl; 
	cout << "Please set time: ";
	getline(cin, time);

	stringstream ss(t);
    string str;
    while(getline(ss,str,' ')){
        cout << str << endl;
    }


	
  	return 0;
}
