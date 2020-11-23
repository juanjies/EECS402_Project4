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

  /*
  SortedListClass testList;
  
  testList.printForward();
  testList.insertValue(42);
  testList.printForward();
  */
  int outItem = 0;
  FIFOQueueClass testQueue;
  cout << "Queue testing: " << endl;

  testQueue.print();
  testQueue.enqueue(1);
  testQueue.enqueue(3);
  testQueue.enqueue(5);
  cout << "Number of Elements: " << testQueue.getNumElems();
  testQueue.print();
  testQueue.dequeue(outItem);
  cout << "Number of Elements: " << testQueue.getNumElems();
  testQueue.print();
  testQueue.clear();
  testQueue.print();

  return 0;
}

#endif