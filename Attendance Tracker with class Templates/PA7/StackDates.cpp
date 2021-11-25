#include "StackDates.hpp"
StackDates::StackDates() {
	front = -1;

}

void StackDates::push(string Date) {
	//checks if overflow
	front++;
	arr[front] = Date;
}

string StackDates::pop() {
	//check if empty
	if (front < 0) {
		cout << "No absenses!" << endl;
	}
	else {
		string popped;
		
		popped = arr[front];
		arr[front] = "";
		front--;
		return popped;
	}
	
}

string StackDates::peek() {
	if (front < 0) {
		cout << "No absenses!" << endl;
		return "";
	}
	else {
		string peeked;
		peeked = arr[front];
		return peeked;
	}
}

bool StackDates::isEmpty() {
	return (front == -1);
}

StackDates::~StackDates() {

}
StackDates StackDates::invert(StackDates dates) {
	StackDates temp;
	while (!dates.isEmpty()) {
		temp.push(dates.pop());
	}
	return temp;
}

StackDates::StackDates(StackDates& copy) {
	front = copy.front;
	for (int i = 0; i <= 364; i++) {
		arr[i] = copy.arr[i];
	}
	
}

int StackDates::countDates(StackDates dates) {
	StackDates temp;
	int i = 0;
	while (!dates.isEmpty()) {
		i++;
		temp.push(dates.pop());
	}

	return i;
}
