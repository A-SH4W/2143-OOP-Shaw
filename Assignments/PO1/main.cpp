/*****************************************************************************
*                    
*  Author:           Aodhan Shaw
*  Email:            aodhanshaw@gmail.com
*  Label:            P01
*  Title:            P01
*  Course:           2143
*  Semester:         Fall 2021
* 
*  Description:
*        MyVector class utilizes overloaded constructors to create
*        dynamically sized linked-list which can be manipulated
*        by the user.
*  Usage:
*        User input in int main() can be used to manipulate
*        items.
*  Files:            main.cpp
                     input.dat
                     test.out 
*****************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Class Node
 * 
 * Description:
 *      Node class that is used to easily create nodes for linked list
 *      Doubly linked 
 * 
 * Public Methods:
 *      Node(int d, Node* n, Node* p)
 *      - Constructor which contains Node pointer next and previous
 *        as well as int data type
 * 
 * Private Methods:
 *      N/A
 * 
 * Usage: 
 *    for(int i=size-1; i>-1; i--){
 *     head = new Node(A[i], head, NULL);
 *   
 *      
 *      
 */
class Node{
  public:
  Node(int d, Node* n, Node* p){
    data = d;                       // defining variables
    next = n;
    prev = p;
  }
  int data;
  Node* next;                       // pointers that point to
  Node* prev;                       // nodes before and after them
};

 /**
     * Public: loadArr
     * 
     * Description:
     *      Function takes in file name as well as array and array size
     *      Loads file data into an array
     * Params:
     *      - string filename       files name
     *      - int*& arr             Array created
     *      - int& size             Size of array
     *      
     * 
     * Returns:
     *      - void
     */
void loadArr(string filename, int*& arr, int& size) {
    ifstream fin;               // stream reference
                                //
    fin.open("input.dat");      // open the file
                                //
    fin >> size;                // get first value which contains
                                // number of remaining values in file
                                //
    arr = new int[size];        // allocate new array of correct size
                                //
    int i = 0;                  // need an array index for our while loop
                                //
    // Can also use for loop since we know the exact count in file.
    // eof = end of file flag
    // `!fin.eof()` evaulates to true when we hit end of file.
    while (!fin.eof()) {
        fin >> arr[i];          // read file value straight into array
                                // at index i
        i++;                    // increment array index
    }
}

 /**
     * Public: printArr
     * 
     * Description:
     *      Function traverses through array items and prints
     * 
     * Params:
     *      - int* arr          pointer to array
     *      - int size          size of array
     *      
     * 
     * Returns:
     *      - void
     */
void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "]";
    }
    cout << "\n";
}

/**
 * Class MyVector
 * 
 * Description:
 *      This class acts as a doubly linked list 
 *     
 * Public Methods:
 *  
 * MyVector();
 * MyVector(int *A, int size);
 * MyVector(string fileName);
 * MyVector(const MyVector& V1);
 * void pushFront(int val);
 * void pushFront(MyVector V2);
 * void pushRear(int val);
 * void pushRear(const MyVector& v2);
 * void pushAt(int loc,int val);
 * int popFront();
 * int popRear();
 * int popAt(int loc);
 * void find(int val);
 * bool empty();
 * 
 * 
 * Private Methods / variables:
 *      - Node* temp
 *      - Node* head
 *      - Node* tail
 * 
 * Usage: 
 *      MyVector v1;
 *      v1.pushFront(18);
 *     
 *       
 *      
 */
class MyVector{
  private:
  Node* temp;                       // pointers that keep track of
  Node* head;                       // begining and end of linked list
  Node* tail;
  public:
  
/**
* Public : MyVector
* 
* Description:
*      Default Constructor
* 
* Params:
*      N/A
* 
* Returns:
*      N/A
*/
  MyVector(){                       //Default constructor
  head = NULL;
  tail = NULL;
  }

/**
* Public : MyVector
* 
* Description:
*      adds each item from an array type
* 
* Params:
*      - int*A      pointer to array
*      - int size   size of array
* 
* Returns:
*      - N/A
*/
  MyVector(int* A, int size){      
  head = NULL;
  tail = NULL;
    for(int i=size-1; i>-1; i--){
      head = new Node(A[i], head, NULL);
    if(tail == NULL)
    {
      tail = head;
    }
    else
    {
      head->next->prev = head;   
    }
    }
  };

/**
* Public : MyVector
* 
* Description:
*      read until eof loading each value into list
* 
* Params:
*      - string filename
* 
* Returns:
*      - N/A
*/
  MyVector(string filename){
    
  };

/**
* Public : MyVector
* 
* Description:
*      traverse other.list adding each value to this.list
* 
* Params:
*      - const MyVector& V1
* 
* Returns:
*      - N/A
*/
  MyVector(const MyVector& V1){
    //copy constructor
  };

/**
* Public : pushFront
* 
* Description:
*      adds single value to front of this.list
* 
* Params:
*      - int val
* 
* Returns:
*      - void
*/
  void pushFront(int val){
    head = new Node(val, head, NULL);
    if(tail == NULL){
      tail = head;
    }
    else{
      head->next->prev = head;   
    }
  };

/**
* Public : pushFront
* 
* Description:
*      adds entire other.list to front of this.list
* 
* Params:
*      - (MyVector V2)
* 
* Returns:
*      - void
*/
  void pushFront(MyVector V2);

/**
* Public : pushRear
* 
* Description:
*      adds single value to end of this.list
* 
* Params:
*      - int val
* 
* Returns:
*      - void
*/
  void pushRear(int val){
    tail = new Node(val, NULL, tail);
    if(head == NULL)
    {
      head = tail;
    }
    else 
    {
      tail->prev->next = tail;
    }
  };

/**
* Public : pushRear
* 
* Description:
*      adds entire other.list to end of this.list
* 
* Params:
*      - (const MyVector& v2)
* 
* Returns:
*      - void
*/
  void pushRear(const MyVector& v2){
      Node *temp = v2.head;
    while (temp){
         pushRear(temp->data);
         temp = temp->next;
         }
  };

/**
* Public : pushAt
* 
* Description:
*      adds value at specific location
* 
* Params:
*      - int *A
*      - int loc
*      - int val
* Returns:
*      - void
*/
  void pushAt(int *A, int loc,int val){
    A[loc] = val;
    
  };

/**
* Public : popFront
* 
* Description:
*      removes single value from front of list
* 
* Params:
*      
* Returns:
*      - int
*/
  int popFront(){
   if(!empty()){
    int popped = head->data;
    Node* deleteMe = head;
    head = head ->next;
    delete deleteMe;
    return popped;
    }
    return 1;
  };

/**
* Public : popRear
* 
* Description:
*      removes single value from rear of list
* 
* Params:
*      
* Returns:
*      - int
*/
  int popRear(){
    if(!empty()){
    int popped = tail->data;
    Node* deleteMe = tail;
    tail = tail->prev;
    tail->next=NULL;
    delete deleteMe;                
    return popped;
    }
    return 1;
  };

/**
* Public : popAt
* 
* Description:
*      removes single value from specific location
* 
* Params:
*       -int loc
*      
* Returns:
*      - int
*/
  int popAt(int loc){
    Node* travel;
  
  return 1;
  };

/**
* Public : find
* 
* Description:
*      finds value in list
* 
* Params:
*     int val 
* Returns:
*      - void
*/
  void find(int val);

/**
* Public : empty
* 
* Description:
*      checks if linked list is empty
* 
* Params:
*      n/a
* Returns:
*      - boolean
*/
  bool empty(){
  return head == nullptr;
  }

/**
* Public : print
* 
* Description:
*      prints values
* 
* Params:
*      
* Returns:
*      - void
*/
  void print(ofstream& myfile) {
    
    //myfile.open("test.out");
        Node* temp = head;  // temp pointer copies head

        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            myfile << temp->data;
            cout << temp->data;  // print data from node
            if (temp->next) {
                myfile << ", ";
                cout << ", ";
            }
            temp = temp->next;  // move to next node
        }
        myfile << endl;
        cout << endl;
    }
};


int main(){
ofstream myfile;
myfile.open ("test.out");
int x = 0;

myfile << "2143\n" << "P01\n" << "Aodhan Shaw\n\n\n";

MyVector v1;                        // creating object of class MyVector
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print(myfile);
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};        // initializing array
MyVector v2(A,5);
v2.print(myfile);
// [11, 25, 33, 47, 51]

v2.pushFront(9);
//v2.inOrderPush(27);
v2.pushRear(63);
v2.print(myfile);
// [9, 11, 25, 27, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print(myfile);
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print(myfile);
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
myfile<<x<<endl;
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print(myfile);
// [18, 20, 25, 9, 11, 25, 27, 33]
myfile<<x<<endl;
cout<<x<<endl;
// 47

//x = v2.popAt(3);
//v2.print();
// [9, 11, 25, 33, 47, 51, 63]
//cout<<x<<endl;
// 27

//x = v2.find(51);
//cout<<x<<endl;
// 5

//x = v2.find(99);
//cout<<x<<endl;
// -1

//MyVector v3(v1);
//v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

//v3.pushFront(v2);
//v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

//MyVector v4("input.dat");
//v4.pushRear(v3);
//v4.print();
// [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 
// 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 
// 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
 
 myfile.close();
  return 0;
}
