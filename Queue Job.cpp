/*
Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.
*/
#include <iostream>
#include <string.h>
using namespace std;

#define Size 5
class jobq
{
    private:
    int f, r;
    public:
    string q[Size];
    jobq()
    {
        f = -1;
        r = -1;
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
        if(r == Size-1)
            return true;
        else
            return false;
    }
    void insert(string x)
    {
        if(full())
            cout << "ERROR: OVERFLOW - Queue is full. " << x << " could not be inserted" << endl;
        else
        {
            if (f == -1) {f = 0;}
            r++;
            q[r] = x;
            cout << x << " is inserted in the Queue" << endl;
        }
    }
    void del()
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
    jobq q1;
    q1.insert("Job 1");
    q1.insert("Job 2");
    q1.insert("Job 3");
    q1.display();
    q1.insert("Job 4");
    q1.insert("Job 5");
    q1.display();
    q1.insert("Job 6");
    q1.display();
    q1.del();
    q1.display();
    q1.del();
    q1.display();
    q1.del();
    q1.display();
    q1.del();
    q1.display();
    q1.del();
    q1.display();
    q1.del();
    q1.display();
}
/*jobq Class:

f (front) and r (rear) are integers to keep track of the front and rear of the queue.
q is an array of strings to store job names.
Constructor:

Initializes f and r to -1.
Member Functions:

empty(): Checks if the queue is empty.
full(): Checks if the queue is full.
insert(string x): Inserts a job into the queue.
del(): Deletes a job from the front of the queue.
display(): Displays the jobs in the queue.
main Function:

Creates an instance of the jobq class called q1.
Inserts jobs ("Job 1" to "Job 5") into the queue using insert.
Displays the queue using display.
Inserts more jobs ("Job 6") into the queue.
Displays the updated queue.
Deletes jobs from the front of the queue using del.
Displays the queue after each deletion.
Job Insertion (insert Function):

Checks if the queue is full using full.
If full, outputs an overflow message.
If not full, updates the front and rear accordingly and inserts the job.
Job Deletion (del Function):

Checks if the queue is empty using empty.
If empty, outputs an underflow message.
If not empty:
If front equals rear, there is only one element in the queue. Deletes it and sets front and rear to -1.
If there is more than one element, deletes the front element and increments front.
Queue Display (display Function):

Checks if the queue is empty using empty.
If empty, outputs an empty message.
If not empty, iterates through the queue from front to rear and displays each job.
Output:

Displays messages indicating the insertion, deletion, and current state of the queue.*/
