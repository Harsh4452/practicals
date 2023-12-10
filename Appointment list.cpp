/* Write C++ program for storing appointment schedule for day. Appointments are booked
randomly using linked list. Set start and end time and min and max duration for visit slot.
Write functions for: 
a) Display free slots
b) Book appointment
c) Cancel appointment (check validity, time bounds, availability)
d) Sort list based on time
e) Sort list based on time using pointer manipulation */

#include<iostream>

struct Node // Node Structure of each Appointment
{
   int start;
   int end;
   int min;
   int max;
   bool status; // 0 (false) for free and 1 (true) for booked
   struct Node *next;
};

class Schedule
{
   private:
   int size;
   Node *head; // Head of the Linked List
   public:
   Schedule()
   {
      head = NULL;
   }
	void create_Schedule();
	void display_Schedule();
   void display_Free();
	void book_App();
	void cancel_App();
	void sort_App1();
   void sort_App2();
};

void Schedule :: create_Schedule() // Function Definition to create Appointment Schedule
{
   int i;
   Node *temp, *last;
   head = NULL;
   std::cout<<"\n\t How many Appointment Slots: ";
   std::cin>>size;
   for(i=0; i<size; i++)
   {
      std::cout << "\nEnter information of slot " << i+1;
      temp = new Node; // Step 1: Dynamic Memory Allocation
      std::cout<<"\n\n\t Enter Start Time: ";   // Step 2: Assign Data & Address
      std::cin>>temp->start; 
      std::cout<<"\n\t Enter End Time: ";
      std::cin>>temp->end;
      std::cout<<"\n\n\t Enter Minimum Duration: ";
      std::cin>>temp->min;
      std::cout<<"\n\t Enter Maximum Duration: ";
      std::cin>>temp->max;
      temp->status = false;
      temp->next = NULL;
      if(head == NULL)
      {
         head = temp;
         last = head;
      }
      else
      {
         last->next = temp;
         last = last->next;
      }
   }
}

void Schedule :: display_Schedule() // Function definition to display the Schedule
{
   Node *temp;
   bool flag = true;
   temp = head;
   if(head == NULL)
   {
      std::cout << "\n\t Schedule not created";
   }
   else
   {
      while(temp != NULL)
      {
         std::cout<<"\n\n\t Start Time: "<<temp->start;
         std::cout<<"\n\t End Time: "<<temp->end;
         std::cout<<"\n\t Minimum Duration: "<<temp->min;
         std::cout<<"\n\t Maximum Duration: "<<temp->max;
         if(temp->status)
         {
            std::cout<<"\n\t Status: Booked";
            flag = false;
         }
         else
         {
            std::cout<<"\n\t Status: Free";
         }
         temp = temp->next;
      }
      if(flag)
      {
         std::cout<<"\n\n\t No Appointments Booked";
      }
   }
}

void Schedule :: display_Free() // Function definition to display the free slots
{
   Node *temp;
   bool flag = true;
   temp = head;
   if(head == NULL)
   {
      std::cout << "\n\t Schedule not created";
   }
   else
   {
      std::cout << "\n\n\t Free Slots: ";
      while(temp != NULL)
      {
         if(temp->status == false)
         {
            std::cout << "\n\n\t Start Time: " << temp->start;
            std::cout << "\n\t End Time: " << temp->end;
            std::cout << "\n\t Minimum Duration: " << temp->min;
            std::cout << "\n\t Maximum Duration: " << temp->max;
            flag = false;
         }
         temp = temp->next;
      }
      if(flag)
      {
         std::cout << "\n\n\t No Free Slots";
      }
   }
}

void Schedule :: book_App() // Function definition to book an appointment
{
   display_Free();
   int start;
   if(head != NULL)
   {
      std::cout << "\n\n\t Enter the Start Time of the Appointment Slot you want to book: ";
      std::cin >> start;
      Node *temp;
      temp = head;
      while(temp != NULL)
      {
         if(temp->start == start)
         {
            if(temp->status)
            {
               std::cout << "\n\n\t Appointment Slot is already Booked!";
               break;
            }
            else
            {
               temp->status = true;
               std::cout << "\n\n\t Appointment Booked Successfully!";
               break;
            }
         }
         temp = temp->next;
      }
   }
}

void Schedule :: cancel_App() // Function definition to cancel an appointment
{
   int start;
   std::cout << "\n\n\t Enter the Start Time of the Appointment Slot you want to cancel: ";
   std::cin >> start;
   Node *temp;
   temp = head;
   while(temp != NULL)
   {
      if(temp->start == start)
      {
         if(temp->status)
         {
            temp->status = false;
            std::cout << "\n\n\t Appointment Cancelled Successfully!";
            break;
         }
         else
         {
            std::cout << "\n\n\t Appointment Slot is already Free!";
            break;
         }
      }
      temp = temp->next;
   }
}

void Schedule :: sort_App1() //Function Definition to Sort Appointments by swapping values in the nodes
{
   int i, val;
   Node *temp;
   for(i=0; i < size-1; i++) 	
   {
      temp = head;
      while(temp->next != NULL)
      { 
         if(temp->start > temp->next->start)
         {
            val = temp->start;
            temp->start = temp->next->start;
            temp->next->start = val;
            val = temp->end;
            temp->end = temp->next->end;
            temp->next->end = val;
            val = temp->min;
            temp->min = temp->next->min;
            temp->next->min = val;
            val = temp->max;
            temp->max = temp->next->max;
            temp->next->max = val;
         }
         temp = temp->next;
      }   
   }
   std::cout<<"\n\n\t The Appointments are Sorted!!!";
}

void Schedule :: sort_App2() // Function Definition to Sort Appointments by swapping the pointers of the nodes
{
   int i;
   Node *temp, *temp2, *temp3, *temp4;
   for(i=0; i < size-1; i++) 	
   {
      temp = head;
      while(temp->next != NULL)
      { 
         if(temp->start > temp->next->start)
         {
            if(temp == head)
            {
               temp2 = temp->next;
               temp3 = temp2->next;
               temp->next = temp3;
               temp2->next = temp;
               head = temp2;
            }
            else
            {
               temp2 = temp->next;
               temp3 = temp2->next;
               temp4 = head;
               while(temp4->next != temp)
               {
                  temp4 = temp4->next;
               }
               temp->next = temp3;
               temp2->next = temp;
               temp4->next = temp2;
            }
         }
         temp = temp->next;
      }   
   }
   std::cout<<"\n\n\t The Appointments are Sorted!!!";
}

int main()
{
   int choice = 0;
   Schedule S1;
   do
   {    
      std::cout<<"\n\n\t *** Menu ***";
      std::cout<<"\n 1. Create Appointment Schedule";
      std::cout<<"\n 2. Display Appointment Schedule";
      std::cout<<"\n 3. Display Free Slots";
      std::cout<<"\n 4. Book an Appointment";
      std::cout<<"\n 5. Cancel an Appointment";
      std::cout<<"\n 6. Sort slots based on Time";
      std::cout<<"\n 7. Sort slots based on Time using Pointer Manipulation";
      std::cout<<"\n 8. Exit";
      std::cout<<"\n\n\t Enter your choice: ";                        
      std::cin>>choice;
      switch(choice)
      {
         case 1:
         S1.create_Schedule();
         break;
         case 2:
         S1.display_Schedule();
         break;
         case 3:
         S1.display_Free();
         break;
         case 4:
         S1.book_App();
         break;
         case 5:
         S1.cancel_App();
         break;
         case 6:
         std::cout << "\n\t Sorted Appointment Schedule Based on Time: ";
         S1.sort_App1();
         break;
         case 7:
         std::cout << "\n\t Sorted Appointment Schedule Based on Time using Pointer Manipulation: ";
         S1.sort_App2();
         break;
         case 8:
         std::cout << "\n\t Thank You!";
         break;
         default:
         std::cout<<"\n\t Wrong choice!!!";
      }
   }while(choice != 8);
}
/*1. Node Structure:This structure represents each appointment slot. It stores information such as start and end times, minimum and maximum durations, and the status indicating whether it's booked or free. The structure is designed to be part of a linked list.
Schedule Class:The Schedule class manages the linked list of appointments. It has a private head pointer and functions to create, display, book, cancel, and sort appointments.
3. Member Function Definitions:

create_Schedule()
Takes user input to create a schedule of appointments using dynamic memory allocation.
display_Schedule()
Displays details of all appointments in the schedule, indicating whether they are booked or free.
display_Free()
Displays details of free appointment slots.
book_App()
Allows the user to book an available appointment slot.
cancel_App()
Allows the user to cancel a booked appointment.
sort_App1()
Sorts appointments based on start time by swapping values in nodes.
sort_App2()
Sorts appointments based on start time by swapping pointers of nodes.
4. Main Function:The main function initializes a Schedule object and presents a menu-driven interface to the user. The user can create a schedule, display it, book or cancel appointments, and sort the schedule based on time.*/


