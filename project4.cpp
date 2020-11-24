#include <iostream>
#include "SortedListClass.h"
#include "FIFOQueueClass.h"

using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main()
{
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.

  
  SortedListClass listOne;
  cout << "Sorted List testing: " << endl;

  listOne.printForward();
  listOne.insertValue(3);
  listOne.insertValue(5);
  listOne.insertValue(7);
  listOne.insertValue(1);
  listOne.insertValue(9);
  
  /*
  // deep copy from listOne to list Two
  SortedListClass listTwo(listOne); 
  int theVal = 0;
  listTwo.removeFront(theVal);
  listTwo.removeLast(theVal);
  listTwo.insertValue(6);
  listTwo.insertValue(4);
*/
  int theVal = 0;
  cout << "List one is: ";
  listOne.printForward();
  listOne.printBackward();
  cout << "Num of element: " << listOne.getNumElems() << endl;
  listOne.getElemAtIndex(4, theVal);
  cout << "the 4th element is: " << theVal << endl; 
  listOne.removeFront(theVal);
  listOne.removeLast(theVal);
  listOne.insertValue(4);
  listOne.insertValue(6);
  listOne.printForward();
  listOne.clear();
  listOne.printForward();
//  cout << "List two is: ";
//  listTwo.printForward();
 

/*
  int outItem = 0;
  FIFOQueueClass testQueue;
  cout << "Queue testing: " << endl;

  testQueue.print();
  testQueue.enqueue(2);
  testQueue.enqueue(4);
  testQueue.enqueue(6);
  cout << "Number of Elements: " << testQueue.getNumElems() << endl;
  testQueue.print();
  testQueue.dequeue(outItem);
  cout << "Number of Elements: " << testQueue.getNumElems() << endl;
  testQueue.print();
  testQueue.clear();
  cout << "Number of Elements: " << testQueue.getNumElems() << endl;
  testQueue.print();
  cout << "Finish testing queue!" << endl;
*/
  return 0;
}

#endif