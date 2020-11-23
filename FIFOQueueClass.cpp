#include <iostream>
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: to implement the "first-in-first-out" queue data structure

FIFOQueueClass::FIFOQueueClass() {
  head = NULL;
  tail = NULL;
}

FIFOQueueClass::~FIFOQueueClass() {
  this -> clear();
}

void FIFOQueueClass::enqueue(const int &newItem) {
  LinkedNodeClass* insertNode = NULL;

  if (head == NULL) {
    tail = new LinkedNodeClass(NULL, newItem, NULL);
    head = tail;
  }
  else {
    insertNode = new LinkedNodeClass(tail, newItem, NULL);
    tail = insertNode;
    tail -> setBeforeAndAfterPointers();
    insertNode = NULL;
  }
}

bool FIFOQueueClass::dequeue(int &outItem) {
  if (head == NULL) {
    return (false);
  }
  else {
    outItem = head -> getValue();
    head = head -> getNext();
    delete head -> getPrev();
    return (true);
  }
}

void FIFOQueueClass::print() const {
  LinkedNodeClass* temp = head;
  while (temp != NULL) {
    cout << temp -> getValue() << " ";
    temp = temp -> getNext();
    cout << "test" << endl;
  }
  cout << endl;
}

int FIFOQueueClass::getNumElems() const {
  LinkedNodeClass* temp = head;
  int numCount = 0;

  while (temp != NULL) {
    temp = temp -> getNext();
    numCount++;
  }
  return (numCount);
}

void FIFOQueueClass::clear() {
  LinkedNodeClass* temp = head;
  while (temp != NULL) {
    head = head -> getNext();
    delete temp;
    temp = head;
  }
}

