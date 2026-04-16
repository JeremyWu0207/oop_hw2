#include <iostream>
#include <string>
#include <sstram>
#include "Stack.h"

using namespace std;

int main() {
	Stack s;
	string inputline;

	getline(cin, getline);
	stringstream ss(inputline);
	int num;
	while (ss >> num) {
		s.push(num);
	}

	int choice;
	while (1) {
		cout << "\n1. push\n2. pop \n3. empty\n4. top\n";
		if (!(cin>>choice)) break;

		if (choice == 1) {
			if (s.isfull()) {
				cout << "\nThe stack is full. \n";
			}
			else {
				int val;
				cin >> val;
				s.push(val);
				cout << "\npush number: " << val << "\nStack :\n";
				s.printstack();
			}
		}

		else if (choice == 2) {
			if (s.pop(val)) {
				cout << "\n pop number : " << val << "\nStack :\n";
				s.printstack();
			}
			else {
				cout << "\n The stack is empty.\n";
			}
		}

		else if (choice == 3) {
			s.empty();
			cout << "\nEmpty the stack.\n";
		}

		else if (choice == 4) {
			int val;
			if (s.top(val)) {
				<< "\nTop number is " << val << "\n";
			}
			else {
				cout << "\nThe stack is empty.\n";
			}
		}
	}

	return 0;
}
