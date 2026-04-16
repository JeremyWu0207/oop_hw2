#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack{
	private:
		int arr[10];
		int top_index;
	public:
		Stack();
		bool push(int val);
		bool pop(int &val);
		bool empty();
		bool top(int &val);

		bool is_full();
		bool is_empty();
		void printstack();
};


#endif
