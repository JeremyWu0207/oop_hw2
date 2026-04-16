#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
	top_index = -1;
}

bool Stack::push(int val){
	if (top_index >= 9) {
		return false;
	}
	arr[++top_index] = val;
	return true;
}

bool Stack::pop(int &val){
	if (top_index < 0){
		return false;
	}
	val = arr[top_index--];
	return true;
}

void Stack::empty(){
	top_index = -1;
}

bool Stack::top(int &val){
	if (top_index < 0){
		return false;
	}
	val = arr[top_index];
	return true;
}

bool Stack::is_full() {
	return top_index >= 9;
}

bool Stack::is_empty() {
	return top_index < 0;
}

void Stack::printstack() {
	for (int i = top_index; i >= 0; i--){
		cout  << arr[i] << "\n";
	}
}

