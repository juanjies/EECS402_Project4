#include <cstdlib>
#include "LinkedNodeClass.h"

// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: This class will be used to store individual nodes of 
//          a doubly-linked data structure.  

LinkedNodeClass::LinkedNodeClass(LinkedNodeClass* inPrev, 
                                  const int &inVal, 
                                  LinkedNodeClass* inNext) {
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
}

int LinkedNodeClass::getValue() const {
  return (nodeVal);
}

LinkedNodeClass* LinkedNodeClass::getNext() const {
  return (nextNode);
}

LinkedNodeClass* LinkedNodeClass::getPrev() const {
  return (prevNode);
}

void LinkedNodeClass::setNextPointerToNull() {
  nextNode = NULL;
}

void LinkedNodeClass::setPreviousPointerToNull() {
  prevNode = NULL;
}

void LinkedNodeClass::setBeforeAndAfterPointers() {
  if (prevNode != NULL) {
    prevNode -> nextNode = this;
  }
  if (nextNode != NULL) {
    nextNode -> prevNode = this;
  }
}
