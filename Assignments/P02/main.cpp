//////////////////////////////////////////////////////////////////////////////
//
// Author:           Aodhan Shaw
// Title:            P02
// Course:           2143
// Semester:         Fall 2021
//
// Description:
//    Create a more robust MyVector class that utilizes operator 
//    overloading to manipulate elemtns of linked lists.
//
//////////////////////////////////////////////////////////////////////////////

// Libraries
#include <fstream>  
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Node for our linked list
struct node {
  int data;         // data value 

  node *next;       // "link" in a linked list
  node *prev;

  node(int x) {     // constructor 
    data = x;
    next = NULL;
    prev = NULL;
  }
};

//////////////////////////////////////////////////////////////////////////////
//
// Public: loadArr()
//         
// Description: Function used to open file and load values into an array
//          
// Params: int *&arr
//         int *&size
//                
//
// Returns: void
//    
//
//////////////////////////////////////////////////////////////////////////////
void loadArr(string filename, int *&arr, int &size) {
  ifstream fin;        // stream reference
                       //
  fin.open(filename);  // open the file
                       //
  fin >> size;         // get first value which contains
                       // number of remaining values in file
                       //
  arr = new int[size]; // allocate new array of correct size
                       //
  int i = 0;           // need an array index for our while loop
                       //
  // Can also use for loop since we know the exact count in file.
  // eof = end of file flag
  // `!fin.eof()` evaulates to true when we hit end of file.
  while (!fin.eof()) {
    fin >> arr[i]; // read file value straight into array
                   // at index i
    i++;           // increment array index
  }
}

//////////////////////////////////////////////////////////////////////////////
//
// Public: printArr
//         
// Description: Function used to traverse array and print values
//          
// Params: int *arr
//         int size
//                 
//
// Returns: void
//   
//
//////////////////////////////////////////////////////////////////////////////
void printArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "[" << arr[i] << "]";
  }
  cout << "\n";
}

//////////////////////////////////////////////////////////////////////////////
//
// Class Name: MyVector
//         
// Description: This class acts as a doubly linked list which utilizes
//    overloaded operators to manipulate elements of a linked list.
//          
// Private Members / Methods:
//   node* head
//   node* tail
//         
// Public Members / Methods:
//  int size;        
//  MyVector()
//  MyVector(int A[], int arrsize)
//  void push_Back(int i)
//  void Push(int x)
//  friend fstream& operator <<(fstream & os, const MyVector &other)
//  friend ostream& operator <<(ostream & os, const MyVector &other)
//  MyVector operator + (const MyVector& other)
//  MyVector operator - (const MyVector& other)
//  MyVector operator * (const MYVector& other)
//  MyVector operator / (const MyVector& other)
//  MyVector operator == (const MyVector& other)
//  void print()
//  
// Usage:
// 
//  MyVector v3 = v1 + v2;
//  cout << v3 << endl;
//  (writes out [11,22,33,4,9] to console.)
//    
//
//////////////////////////////////////////////////////////////////////////////
class MyVector {
private:
  node *head; // base pointer of list
  node *tail;
public:
int size;

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector()
//         
// Description: default constructor
//          
// Params: N/A
//               
//
// Returns: N/A
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector() {
    head  = tail = NULL; // NULL = zeros
                 // and zeros imply empty
    size = 0;    
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector()
//         
// Description: Overloaded Constructor
//          
// Params: int A[]
//         int arrsize
//         
//
// Returns: N/A
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector(int A[], int arrsize) {
    head = NULL;    // NULL = zeros
                    // and zeros imply empty

    for (int i = 0; i < arrsize; i++) {
      push_Back(A[i]);
    }
    
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: push_Back()
//         
// Description: Method used to push data and create nodes for linked list
//          
// Params: int i - integer data stored in i
//               
//
// Returns: void
//    
//
//////////////////////////////////////////////////////////////////////////////
    void push_Back(int i) {
    node* tempPtr = new node(i);
        if (!head) {
            head = tail = tempPtr;
        } 
        else {
            tail->next = tempPtr;
            tail = tempPtr;
        }
        size++;  // add to size of list
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public:  Push()
//         
// Description: Push method used to push values onto linked list
//          
// Params: int x - whatver integer value stored in x
//               
//
// Returns: void
//    
//
//////////////////////////////////////////////////////////////////////////////
    void Push(int x) {
    node *tempPtr = new node(x);    // create a new node and
                                    // add data to it

    if (!head) {                    // `!head` implies empty list
                                    // So does `head == NULL`

      head = tempPtr;               // `head = tempPtr` places addrress of
                                    // tempPtr in head (points head to tempPtr)

    } else {                        // list not empty
      tempPtr->next = head;         // point tempPtr's next to what head points to
      head = tempPtr;               // now point head to tempPtr
    }
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: friend fstream& operator <<( fstream & os, const MyVector &other)
//         
// Description: overloading << operator to read in from file
//          
// Params:  fstream & os
//          const MyVector & other
//         
//
// Returns: fstream&
//    
//
//////////////////////////////////////////////////////////////////////////////
  friend fstream& operator <<( fstream & os, const MyVector &other){
    node* temp = other.head; 
    while(temp){
      os << temp->data;
      if (temp->next){
        os << "->";
      }
      temp = temp->next;
    }
    os << endl;
    return os;
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public:  friend ostream& operator<< ( ostream & os, const MyVector &other)
//         
// Description: overloading << operator to print to console
//          
// Params:  ostream & os
//          const MyVector & other
//              
//
// Returns: ostream&
//    
//
//////////////////////////////////////////////////////////////////////////////
  friend ostream& operator<< ( ostream & os, const MyVector &other){
    node* temp = other.head;
    while(temp){
      os << "["<< temp->data << "]";
      if (temp->next){
        os << "->";
      }
      temp = temp->next;
    }
    os << endl;
    return os;
  }

  int &operator[](int index){
    node* temp = head;
    for(int i=0; i < index; i++){
      temp = temp->next;
    } 
    return temp->data;
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector operator + (const MyVector& other)
//         
// Description: overload + operator to add linked list elements together
//          
// Params: const MyVector& other
//               
//
// Returns: MyVector
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector operator + (const MyVector& other) {

    node* travel = head;                    // traveling pointers to travers lists
    node* travel2 = other.head;

    MyVector newVector;
  
    while(travel && travel2){
      newVector.push_Back(travel->data + travel2->data); 
      travel = travel->next;
      travel2 = travel2->next;
    }

    while(travel){
      newVector.push_Back(travel->data);
      travel = travel->next;
    }

    while(travel2){
      newVector.push_Back(travel2->data);
      travel2 = travel2->next;
    }
    
    return newVector;

  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector operator - (const MyVector& other) 
//         
// Description: overload - operator to subtract linked list elements
//          
// Params:    const MyVector& other    
//
// Returns: MyVector
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector operator - (const MyVector& other) {

    node* travel = head;              // traveling pointers to travers lists
    node* travel2 = other.head;

    MyVector newVector;
  
    while(travel && travel2){
      newVector.push_Back(travel->data - travel2->data); 
      travel = travel->next;
      travel2 = travel2->next;
    }

    while(travel){
      newVector.push_Back(travel->data);
      travel = travel->next;
    }

    while(travel2){
      newVector.push_Back(travel2->data);
      travel2 = travel2->next;
    }
    
    return newVector;                   

  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector operator * (const MyVector& other)
//         
// Description: Overloads * operator to multiply linked list elements
//          
// Params: const MyVector& other
//                 
//
// Returns: MyVector
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector operator * (const MyVector& other) {

    node* travel = head;
    node* travel2 = other.head;

    MyVector newVector;
  
    while(travel && travel2){
      newVector.push_Back(travel->data * travel2->data); 
      travel = travel->next;
      travel2 = travel2->next;
    }

    while(travel){
      newVector.push_Back(travel->data);
      travel = travel->next;
    }

    while(travel2){
      newVector.push_Back(travel2->data);
      travel2 = travel2->next;
    }
    
    return newVector;

  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector operator / (const MyVector& other)
//         
// Description: Overloads / operator to divide linked list elements
//          
// Params: const MyVector& other
//                 
//
// Returns: MyVector
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector operator / (const MyVector& other) {

    node* travel = head;
    node* travel2 = other.head;

    MyVector newVector;
  
    while(travel && travel2){
      newVector.push_Back(travel->data / travel2->data); 
      travel = travel->next;
      travel2 = travel2->next;
    }

    while(travel){
      newVector.push_Back(travel->data);
      travel = travel->next;
    }

    while(travel2){
      newVector.push_Back(travel2->data);
      travel2 = travel2->next;
    } 
    return newVector;
  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: MyVector operator == (const MyVector& other)
//         
// Description: Test to see if linked lists are equal
//          
// Params: const MyVector& other
//                
//
// Returns: MyVector
//    
//
//////////////////////////////////////////////////////////////////////////////
  MyVector operator == (const MyVector& other) {

    node* travel = head;
    node* travel2 = other.head;

    MyVector newVector;
  
    while(travel && travel2){
      newVector.push_Back(travel->data == travel2->data); 
      travel = travel->next;
      travel2 = travel2->next;
    }

    while(travel){
      newVector.push_Back(travel->data);
      travel = travel->next;
    }

    while(travel2){
      newVector.push_Back(travel2->data);
      travel2 = travel2->next;
    }
    
    return newVector;

  }

//////////////////////////////////////////////////////////////////////////////
//
// Public: print
//         
// Description: method used to traverse linked list a print values
//          
// Params: N/A
//         
//
// Returns: void
//    
//
//////////////////////////////////////////////////////////////////////////////
  void print() {
    node *temp = head; // temp pointer copies head

    while (temp) { // this loops until temp is NULL
                   // same as `while(temp != NULL)`

      cout <<"[" << temp->data << "]"; // print data from node
      if (temp->next) {
        cout << "->";
      }
      temp = temp->next; // move to next node
    }
    cout << endl;
  }

  ~MyVector() {
      // destructor
  }
};

//////////////////////////////////////////////////////////////////////////////

int main() {

int a1[] = { 1, 2, 3, 4, 5 };
int a2[] = { 10, 20, 30 };

MyVector v1(a1,5);
MyVector v2(a2,3);
v1.print();
v2.print();

ofstream file_out;
file_out.open("output.txt");

cout << v1[2] << endl;
file_out << v1[2] << endl;
// writes out 3

v1[4] = 9;
// v1 now = [1,2,3,4,9]

cout << v1 << endl;
cout << v2 << endl;
// writes out [1,2,3,4,9] to console.

file_out << v1 << endl;
file_out << v2 << endl;
// writes out [1,2,3,4,9] to your output file.

MyVector v3 = v1 + v2;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [11,22,33,4,9] to console.

v3 = v1 - v2;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [-9,-18,-27,4,9] to console.

v3 = v2 - v1;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [9,18,27,4,9] to console.

v3 = v2 * v1;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 * v2;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 / v2;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [0,0,0,4,9] to console.

v3 = v2 / v1;
cout << v3 << endl;
file_out << v3 << endl;
// writes out [10,10,10,4,9] to console.

cout << (v2 == v1) << endl;
file_out << (v2 == v1)<< endl;
// writes 0 to console (false) .

MyVector v4 = v1;
cout << (v4 == v1) << endl;
file_out << (v4 == v1) << endl;
// writes 1 to console (true) .
}