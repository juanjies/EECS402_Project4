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
  LinkedNodeClass* tempTwoPrev = NULL;
  LinkedNodeClass* tempTwoNext = NULL;

  if (rhs.head != NULL || rhs.tail != NULL) {
    for (int i = 0; i < rhs.getNumElems(); i++) {
      if (i == 0) {
        tempTwoPrev = new LinkedNodeClass(NULL,
                                          tempOne -> getValue(), NULL);
        head = tempTwoPrev;
        tempOne = tempOne -> getNext();
      }
      else if (i == (rhs.getNumElems() - 1)) {
        tempTwoNext = new LinkedNodeClass(tempTwoPrev,
                                          tempOne -> getValue(), NULL);
        tempTwoNext -> setBeforeAndAfterPointers();
        tail = tempTwoNext;
      }
      else {
        tempTwoNext = new LinkedNodeClass(tempTwoPrev,
                                          tempOne -> getValue(), NULL);
        tempTwoNext -> setBeforeAndAfterPointers();
        tempOne = tempOne -> getNext();
        tempTwoPrev = tempTwoNext;
      }
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

  // int tempVal = 0;
  /*
  if (temp != NULL) {
    tempVal = temp -> getValue();
    while (valToInsert <= tempVal) {
      temp = temp -> getNext(); 
      tempVal = temp -> getValue();
    }
    insertNode = new LinkedNodeClass(temp -> getPrev(),
                                     valToInsert,
                                     temp);
    insertNode -> setBeforeAndAfterPointers();
  }

  else if (temp == NULL) {
  */
    insertNode = new LinkedNodeClass(NULL, valToInsert, NULL);
    head = insertNode;
    tail = insertNode;
    insertNode = NULL;
  // }
}

void SortedListClass::printForward() const {
  LinkedNodeClass* temp = head;
  cout << "Forward List Contents Follow:" << endl;
  
  if (temp == NULL) {
    cout << "List is Empty" << endl;
  }
  // else {
    //while (temp != NULL) {
    //  cout << "  " << (temp -> getValue()) << endl;
//      cout << "next pointer is pointing to " 
//           << temp -> getNext() << endl;
//      temp = temp -> getNext();
    //}
  //  cout << "End of List Contents" << endl;
  // }
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


