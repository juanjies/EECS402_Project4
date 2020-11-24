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
  // copy ctor for deep copy
  LinkedNodeClass* tempOne = rhs.head;
  LinkedNodeClass* tempTwoPrev = head;
  LinkedNodeClass* tempTwoNext = NULL;

  // if the list is empty
  if (rhs.head == NULL && rhs.tail == NULL) {
    head = NULL;
    tail = NULL;
  }
  // if the list is NOT empty
  else if (rhs.head != NULL && rhs.tail != NULL) {
    for (int i = 0; i < rhs.getNumElems(); i++) {
      // copy the first node and link the head to it
      if (i == 0) {
        tempTwoNext = new LinkedNodeClass(NULL, 
                                          tempOne -> getValue(), NULL);
        tempTwoPrev = tempTwoNext;
        head = tempTwoPrev;
        tempOne = tempOne -> getNext();
      }
      // copy the last node
      else if (i == (rhs.getNumElems() - 1)) {
        tempTwoNext = new LinkedNodeClass(tempTwoPrev,
                                          tempOne -> getValue(), NULL);
        tempTwoPrev = tempTwoNext;
        tempTwoPrev -> setBeforeAndAfterPointers();
        tail = tempTwoNext;
      }
      // copy other nodes in the middle
      else {
        tempTwoNext = new LinkedNodeClass(tempTwoPrev,
                                          tempOne -> getValue(), NULL);
        tempTwoPrev = tempTwoNext;
        tempTwoPrev -> setBeforeAndAfterPointers();
        tempOne = tempOne -> getNext();
      }
    } 
  }
}

SortedListClass::~SortedListClass() {
  this -> clear();
}

void SortedListClass::clear() {
  LinkedNodeClass* temp = head;
  if (head == NULL && tail == NULL) {
    ;
  }
  else {
    for (int i = 0; i < (this -> getNumElems()); i++) {
      temp = temp -> getNext();
      delete head;
      head = temp;
    }
    tail = NULL;
  }
}

void SortedListClass::insertValue(const int &valToInsert) {
  LinkedNodeClass* temp = head;
  LinkedNodeClass* insertedNode = NULL;

  int tempVal = 0;
  // if the list is empty
  if (temp == NULL) {
    insertedNode = new LinkedNodeClass(NULL, valToInsert, NULL);
    head = insertedNode;
    tail = insertedNode;
    temp = head;
    insertedNode = NULL;
  }
  // the list is NOT empty
  else if (temp != NULL) {
    tempVal = temp -> getValue();
    // find the correct location to insert
    while (valToInsert >= tempVal && temp != tail) {
        temp = temp -> getNext(); 
        tempVal = temp -> getValue();
    }
    // if valToInsert is greater than all on the list
    if (valToInsert >= tempVal && temp == tail) {
      insertedNode = new LinkedNodeClass(temp, valToInsert, NULL);
      insertedNode -> setBeforeAndAfterPointers();
      tail = insertedNode;
      insertedNode = NULL;
    }
    // if valToInsert is less than all on the list
    else if (valToInsert < tempVal && temp == head) {
      insertedNode = new LinkedNodeClass(NULL, valToInsert, temp);
      insertedNode -> setBeforeAndAfterPointers();
      head = insertedNode;
      insertedNode = NULL;
    }
    // any others in the middle of the list
    else {
      insertedNode = new LinkedNodeClass(temp -> getPrev(),
                                         valToInsert,
                                         temp);
      insertedNode -> setBeforeAndAfterPointers();
      insertedNode = NULL;
    }
  }
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
    cout << "End of List Contents" << endl;
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
  
  while (temp != NULL) {
    numElems++;
    temp = temp -> getNext();
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


