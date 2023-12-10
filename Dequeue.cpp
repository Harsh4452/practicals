/* A double-ended queue (deque) is a linear list in which additions and deletions may be
made at either end. Obtain a data representation mapping a deque into a onedimensional array. Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque. */

#include <iostream>
#include <string.h>   //stores variables,characters as a string
using namespace std;

#define Size 5
class deque
{
    private:
    int f, r;
    public:
    string q[Size];
    deque()
    {
        r = f = -1;
    }
    bool empty()
    {
        if(f == -1 && r == -1)
            return true;
        else
            return false;
    }
    bool full()
    {
        if(f == 0 && r == Size-1)
            return true;
        else
            return false;
    }
    void insertRear(string x)
    {
        if(full())
            cout << "ERROR: OVERFLOW - Queue is full. " << x << " could not be inserted" << endl;
        else
        {
            if (f == -1) {f = 0;}
            if (r == Size - 1)
                cout << "ERROR: Cannot insert from rear." << x << " could not be inserted" << endl;
            else
            {
                r++;
                q[r] = x;
                cout << x << " is inserted in the Queue" << endl;
            }
        }
    }
    void insertFront(string x)
    {
        if(full())
            cout << "ERROR: OVERFLOW - Queue is full. " << x << " could not be inserted" << endl;
        else
        {
            if (r == -1) {r = 0;}
            if (f == -1)
            {
                f = 0;
                q[f] = x;
            }
            else if(f == 0)
            {
                cout << "ERROR: Cannot insert from front." << x << " could not be inserted" << endl;
            }
            else
            {
                f--;
                q[f] = x;
            }
            cout << x << " is inserted in the Queue" << endl;
        }
    }
    void deleteFront()
    {
        if(empty())
            cout << "ERROR: UNDERFLOW - Queue is empty" << endl;
        else
        {
            if(f == r)
            {
                cout << q[f] << " is deleted from front" << endl;
                f = r =-1;
            }
            else
            {
                cout << q[f] << " is deleted from front" << endl;
                f++;
            }
        }
    }
    void deleteRear()
    {
        if(empty())
            cout << "ERROR: UNDERFLOW - Queue is empty" << endl;
        else
        {
            if(f == r)
            {
                cout << q[f] << " is deleted from front" << endl;
                f = r =-1;
            }
            else
            {
                cout << q[r] << " is deleted from front" << endl;
                r--;
            }
        }
    }
    void display()
    {
        if(empty())
            cout << "The Queue is empty";
        else
        {
            cout << "The Queue is: ";
            for(int i = f; i <= r; i++)
                cout << q[i] << " | ";
        }
        cout << endl;
    }
};
int main()
{
    deque q1;
    int ch;
    string x;
    while(ch != 6)
    {
        cout << "Enter your choice to perform the deque operation:" << endl;
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
            cout << "Enter element to be inserted at front: ";
            cin >> x;
            q1.insertFront(x);
            break;
            case 2:
            cout << "Enter element to be inserted at rear: ";
            cin >> x;
            q1.insertRear(x);
            break;
            case 3:
            q1.deleteFront();
            break;
            case 4:
            q1.deleteRear();
            break;
            case 5:
            q1.display();
            break;
            case 6:
            break;
            default:
            cout << "Enter correct choice";
            break;
        }
    }
}/*1. Class Definition:
Create a class named Deque.
Include private members: front, rear, maxSize, and a dynamic array array.
2. Constructor:
Initialize maxSize with the specified size.
Set front and rear to -1.
Allocate memory for the dynamic array array of size maxSize.
3. Empty Check Function (isEmpty):
Check if front is equal to -1.
If true, return true (indicating the deque is empty); otherwise, return false.
4. Full Check Function (isFull):
Check if the deque is full.
If front is 0 and rear is maxSize - 1, or if front is equal to rear + 1, return true.
Otherwise, return false.
5. Insert at Front Function (insertFront):
Check if the deque is full using isFull.
If true, display an overflow error message and return.
If front is -1 (indicating an empty deque), set front and rear to 0.
If front is already at the beginning, set it to maxSize - 1; otherwise, decrement front.
Insert the item into the array at the front index.
Display a message indicating the successful insertion at the front.
6. Insert at Rear Function (insertRear):
Check if the deque is full using isFull.
If true, display an overflow error message and return.
If front is -1 (indicating an empty deque), set front and rear to 0.
If rear is already at the end, set it to 0; otherwise, increment rear.
Insert the item into the array at the rear index.
Display a message indicating the successful insertion at the rear.
7. Delete from Front Function (deleteFront):
Check if the deque is empty using isEmpty.
If true, display an underflow error message and return a sentinel value (e.g., INT_MIN).
Retrieve the item from the array at the front index.
If front is equal to rear after deletion, set both front and rear to -1.
If front is at the end, set it to 0; otherwise, increment front.
Display a message indicating the successful deletion from the front and return the deleted item.
8. Delete from Rear Function (deleteRear):
Check if the deque is empty using isEmpty.
If true, display an underflow error message and return a sentinel value (e.g., INT_MIN).
Retrieve the item from the array at the rear index.
If front is equal to rear after deletion, set both front and rear to -1.
If rear is at the beginning, set it to maxSize - 1; otherwise, decrement rear.
Display a message indicating the successful deletion from the rear and return the deleted item.
9. Display Function (display):
Display the current state of the deque.*/
