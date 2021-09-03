/*****************************************************************************
*                    
*  Author:           Aodhan Shaw
*  Email:            aodhanshaw@gmail.com
*  Label:            A04
*  Title:            Circular Array
*  Course:           2143-OOP
*  Semester:         Fall Semester 2021
* 
*  Description:
*        Circular array based queue. 
* 
*  Usage:
*        Run files
* 
*  Files:               Banner
                        main.cpp
                        README.md
*****************************************************************************/

#include <iostream>     // Including library

using namespace std;                                   

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class packages the necessary variables and methods
 *      needed to create a circular array based queue. This includes 
 *      variables that identify the "Front" and "Rear" of the queue,
 *      as well as updates the current size of the queue. Methods 
 *      such as, "void Push()" and "int Pop()", can be used to add or
 *      remove integers in the queue. 
 * 
 * Public Methods:
 *              CircularArrayQue()
 *      void    Push(int item)
 *      int     Pop()
 *      
 * Private Methods:
 *      void    init(int size)
 *      bool    Full() 
 *       
 * 
 * Usage: 
 * 
 *      CircularArrayQue();      // Constructor that creates size
 *                               // of array based queue 
 *      
 *      C1.Push();               // Push integer onto array
 *      C1.Pop();                // Remove and return integer from array
 */

class CircularArrayQue {
private:
    int *Container;             // Integer pointer to Container
    int Front;                  // Integer in front of array
    int Rear;                   // Integer at end of the array
    int QueSize;                // Items in the queue
    int CurrentSize;            // Tracks size of array

    /**
     * Private: init
     * 
     * Description:
     *      initializes array size
     * 
     * Params:
     *      int:    size of array
     * 
     * Returns:
     *      no return (void)
     */

    void init(int size = 0) {   // Initialzing size of array to 0
        Front = Rear = CurrentSize = 0;
        QueSize = size; 
    }

    /**
     * Private: Full
     * 
     * Description:
     *      Deterimnes using boolean if array is full
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      Returns Boolean T/F
     */

    bool Full() {
        return CurrentSize == QueSize;    // acknowledges queue has been 
    }                                     // filled to max capacity

public:
    
    /**
     * Public: CircularArrayQue
     * 
     * Description:
     *      Constructor
     * 
     * Params:
     *      N/A 
     * Returns:
     *      since it is a constructor, there is no
     *      explicit return type
     */

    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
     * Public: CircularArrayQue
     * 
     * Description:
     *      Same constructor but overloaded
     * 
     * Params:
     *      int:    size of queue
     * 
     * Returns:
     *      N/A
     */

    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public: Push
     * 
     * Description:
     *      Used to push integers into queue
     * 
     * Params:
     *      int:    item or integer being added
     * 
     * Returns:
     *      void
     */
    
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    
    /**
     * Public: Pop
     * 
     * Description:
     *      Used to remove and store integer from queue
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      returns int "temp" item
     */

    int Pop() {
        int temp = Container[Front];    // temp is variable that acts as
        Front = (Front + 1) % QueSize;  // place holder for item being removed
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {           // infile operation

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5); // calls for constructor and send size

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);             // calls for push function to add integer
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;     // displays queue

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
};