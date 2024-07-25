#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;


Queue::Queue() {
	capacity = 8;
	cQueue = new TElem[capacity];
	sizeArray = 0;
	front = 0;
	rear = -1;
}


void Queue::push(TElem elem) {
	if (sizeArray == capacity) {
		resizequeue();
	}
	rear = (rear + 1) % capacity;
	cQueue[rear] = elem;
	sizeArray++;
}

void Queue::resizequeue() {
	int newCapacity = capacity * 2;
	TElem* newcQueue = new TElem[newCapacity];

	for (int i = 0; i < sizeArray; i++)
	{
		// [front+i mod capacity] means to get to the index where circ queue has elems
		// and copies to newqueue index[0]
		newcQueue[i] = cQueue[(front + i) % capacity];
	}

	delete[] cQueue;
	cQueue = newcQueue;
	capacity = newCapacity;
	front = 0;
	rear = sizeArray - 1;
}

TElem Queue::top() const {
	if (isEmpty())
	{
		throw exception();
	}
	return cQueue[front];
}

TElem Queue::pop() {
	if (isEmpty())
	{
		throw exception();
	}
	TElem elem = cQueue[front];
	front = (front + 1) % capacity;
	sizeArray--;
	return elem;
}

bool Queue::isEmpty() const {
	return sizeArray == 0;
}


Queue::~Queue() {
	delete[] cQueue;
}

