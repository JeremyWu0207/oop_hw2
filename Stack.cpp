#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
	topindex = -1;
}

bool Stack::push(int val){
	if (topindex >= 9) {
		return false;
	}
	arr[++topindex] = val;
	return true;
}

bool Stack::pop(int &val){
	if (topindex < 0){
		return false;
	}
	val = arr[topindex--];
	return true;
}

void Stack::empty(){
	topindex = -1;
}

bool Stack::top(int &val){
	if (topindex < 0){
		return false;
	}
	val = arr[topindex];
	return true;
}

bool Stack::isFull() {
	return topindex >= 9;
}

bool Stack::isEmpty() {
	return topindex < 0;
}

void Stack::printstack() {
	for (int i = 0; i < 10; i++){
		cout  << arr[i] << "\n";
	}
}

