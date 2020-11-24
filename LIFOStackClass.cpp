#include <iostream>
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: to implement the "last-in-first-out" stack data structure

LIFOStackClass::LIFOStackClass() {
  head = NULL;
  tail = NULL;
}

LIFOStackClass::~LIFOStackClass() {
  this -> clear();
}

void LIFOStackClass::push(const int &newItem) {
  LinkedNodeClass* temp = head;
  // if the stack is empty
  if (tail == NULL) {
    temp = new LinkedNodeClass(NULL, newItem, NULL);
    head = temp;
    tail = temp;
  }
  else {
    head = new LinkedNodeClass(NULL, newItem, temp);
    head->setBeforeAndAfterPointers();
  }
}

bool LIFOStackClass::pop(int &outItem) {
  if (head == NULL) {
    return (false);
  }
  else {
    outItem = head -> getValue();
    head = head -> getNext();
    delete head -> getPrev();
    head -> setPreviousPointerToNull();
  }
}

void LIFOStackClass::print() const {
  LinkedNodeClass* temp = head;

  while (temp != NULL) {
    cout << temp -> getValue() << " ";
    temp = temp -> getNext();
  }
  cout << endl;
}

int LIFOStackClass::getNumElems() const {
  LinkedNodeClass* temp = head;
  int numCount = 0;

  while (temp != NULL) {
    temp = temp -> getNext();
    numCount++;
  }
  return (numCount);
}

void LIFOStackClass::clear() {
  LinkedNodeClass* temp = head;
  while (temp != NULL) {
    head = head -> getNext();
    delete temp;
    temp = head;
  }
  tail = NULL;
}