#include <cstdlib>
#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: The sorted list class does not store any data directly. 
//          Instead, it contains a collection of LinkedNodeClass objects
//          each of which contains one element.

SortedListClass::SortedListClass() {
  head = NULL;
  tail = NULL;
}

SortedListClass::SortedListClass(const SortedListClass &rhs) {  

  LinkedNodeClass* temp = rhs.head;

  if (rhs.head != NULL || rhs.tail != NULL) {
    for (int i = 0; i < rhs.getNumElems(); i++) {
      head = new LinkedNodeClass(temp -> getPrev(), 
        temp -> getValue(), 
        temp -> getNext() );
      temp = temp -> getNext();
    } 
  }

  else if (rhs.head == NULL || rhs.tail == NULL) {
    head = NULL;
    tail = NULL;
  }
}

SortedListClass::~SortedListClass() {
  this -> clear();
}

void SortedListClass::clear() {
  LinkedNodeClass* temp = head;

  if (head == NULL || tail == NULL) {
    ;
  }
  else {
    for (int i = 0; i < this -> getNumElems(); i++)
    temp = temp -> getNext();
    delete head;
    head = temp;
  }
}

void SortedListClass::insertValue(const int &valToInsert) {
  LinkedNodeClass* temp = head;
  LinkedNodeClass* insertNode = NULL;

  int tempVal = temp -> getValue();

  while (tempVal <= valToInsert) {
    temp = temp -> getNext(); 
    tempVal = temp -> getValue();
  }
  insertNode = new LinkedNodeClass(temp,
                                   valToInsert,
                                   temp -> getNext());
  insertNode -> setBeforeAndAfterPointers();
}

void SortedListClass::printForward() const {
  LinkedNodeClass* temp = head;
  cout << "Forward List Contents Follow:" << endl;
  
  if (temp == NULL) {
    cout << "List is Empty" << endl;
  }
  else {
    while (temp != NULL) {
      cout << "  " << temp -> getValue() << endl;
      temp = temp -> getNext();
    }
    cout << "End of List Contents";
  }
}

void SortedListClass::printBackward() const {
  LinkedNodeClass* temp = tail;
  cout << "Backward List Contents Follow:" << endl;

  if (temp == NULL) {
    cout << "List is Empty" << endl;
  }
  else {
    while (temp != NULL) {
      cout << "  " << temp -> getValue() << endl;
      temp = temp -> getPrev();
    }
    cout << "End of List Contents";
  }
}

bool SortedListClass::removeFront(int &theVal) {
  LinkedNodeClass* temp = head;

  if (head == NULL) {
    return (false);
  }
  else {
    temp = temp -> getNext();
    theVal = head -> getValue();
    delete head;
    head = temp;
    return (true);
  }
}

bool SortedListClass::removeLast(int &theVal) {
  LinkedNodeClass* temp = tail;

  if (tail == NULL) {
    return (false);
  }
  else {
    temp = temp -> getPrev();
    theVal = tail -> getValue();
    delete tail;
    tail = temp;
    return (true);
  }
} 

int SortedListClass::getNumElems() const {
  LinkedNodeClass* temp = head;
  int numElems = 0;
  
  while (temp != 0) {
    numElems++;
  }
  return (numElems);
}

bool SortedListClass::getElemAtIndex(const int index, int &outVal) const {
  LinkedNodeClass* temp = head;
  // within the list range
  if (index < (this -> getNumElems())) {
    for (int i = 0; i < index; i++) {
      temp = temp -> getNext();
    }
    outVal = temp -> getValue();
    return (true);
  }
  // out of the list range
  else {
    return (false);
  }
}


