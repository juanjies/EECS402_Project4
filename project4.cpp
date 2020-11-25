#include <iostream>
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"

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


  // Sorted list testing part 
  
  SortedListClass listOne;
  cout << "Sorted List testing: " << endl;

  listOne.printForward();
  listOne.insertValue(3);
  listOne.insertValue(5);
  listOne.insertValue(7);
  listOne.insertValue(3);
  listOne.insertValue(7);

  // deep copy from listOne to list Two
  SortedListClass listTwo(listOne); 
  listTwo.insertValue(0);
  listTwo.insertValue(20);

  int tempValOne = 0;
  int tempValTwo = 0;
  cout << "List one is: ";
  listOne.printForward();
  listOne.printBackward();
  cout << "Num of element: " << listOne.getNumElems() << endl;
  listOne.getElemAtIndex(4, tempValOne);
  cout << "the 4th element is: " << tempValOne << endl; 
  listOne.getElemAtIndex(5, tempValTwo);
  cout << "the 5th element is: " << tempValTwo << endl; 
  listOne.removeFront(tempValOne);
  listOne.removeLast(tempValOne);
  listOne.insertValue(4);
  listOne.insertValue(6);
  listOne.printForward();
  listOne.printBackward();
  listOne.removeFront(tempValOne);
  listOne.removeFront(tempValOne);
  listOne.removeLast(tempValOne);
  listOne.removeLast(tempValOne);
  //RESUBMISSION CODE UPDATE
  if (!listOne.removeFront(tempValOne)) {
    cout << "false: the list is empty!" << endl;
  }
  else {
    cout << "there are something in the list" << endl;
  }
  if (!listOne.removeLast(tempValOne)) {
    cout << "false: the list is empty!" << endl;
  }
  else {
    cout << "there are something in the list" << endl;
  }
  listOne.printForward();
  listOne.printBackward();
  listOne.clear();
  listOne.printForward();

  cout << "List two is: ";
  listTwo.printForward();
  listTwo.printBackward();

  // Queue testing part

  int outItemQueue = 0;
  FIFOQueueClass testQueue;
  cout << "Queue testing: " << endl;

  testQueue.print();
  testQueue.enqueue(5);
  testQueue.enqueue(9);
  testQueue.enqueue(7);
  testQueue.enqueue(8);
  cout << "Number of Elements: " << testQueue.getNumElems() << endl;
  testQueue.print();
  testQueue.dequeue(outItemQueue);
  testQueue.dequeue(outItemQueue);
  testQueue.dequeue(outItemQueue);
  //RESUBMISSION CODE UPDATE
  if (!testQueue.dequeue(outItemQueue)) {
    cout << "false: the queue is empty!" << endl;
  }
  else {
    cout << "there are something in the list" << endl;
  }
  cout << "Number of Elements: " << testQueue.getNumElems() << endl;
  testQueue.print();
  if (!testQueue.dequeue(outItemQueue)) {
    cout << "false: the queue is empty!" << endl;
  }
  else {
    cout << "there are something in the list" << endl;
  }
  testQueue.enqueue(1);
  testQueue.enqueue(1);
  testQueue.enqueue(3);
  testQueue.enqueue(6);
  testQueue.print();
  testQueue.clear();
  cout << "Number of Elements: " << testQueue.getNumElems() << endl;
  testQueue.print();

  // Stack testing part

  int outItemStack = 0;
  LIFOStackClass testStack;
  cout << "Stack testing: " << endl;

  testStack.print();
  testStack.push(8);
  testStack.push(7);
  testStack.push(9);
  testStack.push(5);
  cout << "Number of Elements: " << testStack.getNumElems() << endl;
  testStack.print();
  testStack.pop(outItemStack);
  testStack.pop(outItemStack);
  testStack.pop(outItemStack);
  //RESUBMISSION CODE UPDATE
  if (!testStack.pop(outItemStack)) {
    cout << "false: the stack is empty" << endl;
  }
  else {
    cout << "there are something in the list" << endl;
  }
  cout << "Number of Elements: " << testStack.getNumElems() << endl;
  testStack.print();
  if (!testStack.pop(outItemStack)) {
    cout << "false: the stack is empty" << endl;
  }
  else {
    cout << "there are something in the list" << endl;
  }
  testStack.push(8);
  testStack.push(7);
  testStack.push(9);
  testStack.push(5);
  testStack.clear();
  cout << "Number of Elements: " << testStack.getNumElems() << endl;
  testStack.print();

  return 0;
}
#endif