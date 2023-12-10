/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students 
of second, third and final year of department can be granted membership on request. 
Similarly one may cancel the membership of club. First node is reserved for president of 
club and last node is reserved for secretary of club. Write C++ program to maintain club 
member's information using singly linked list. Store student PRN and Name. Write 
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists. */

#include <iostream>
#include <string.h>
using namespace std;

class club
{
    private:
    struct member
    {
        char name[30];
        int prn;
        member *next;
    };
    member *head = new member, *tail = new member;
    public:
    club()
    {
        strcpy(head->name, "None");
        strcpy(tail->name, "None");
        head->prn = 0;
        tail->prn = 0;
        head->next = tail;
        tail->next = NULL;
    }
    void addPresident(char name[30], int prn)
    {
        strcpy(head->name, name);
        head->prn = prn;
    }
    void addSecretary(char name[30], int prn)
    {
        strcpy(tail->name, name);
        tail->prn = prn;
    }
    void addMember(int prn, char name[30])
    {
        member *tmp = new member;
        strcpy(tmp->name, name);
        tmp->prn = prn;
        tmp->next = tail;
        member *tmp2 = head;
        while(tmp2->next != tail)
        {
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp;
    }
    void delPresident()
    {
        if(head->name == "None")
        {
            std::cout << "There is no president to remove from the club" << std::endl;
        }
        else
        {
            std::cout << "President " << head->name << " (PRN - " << head->prn << ") has been removed from the club." << std::endl;
            strcpy(head->name, "None");
            head->prn = 0;
        }
    }
    void delSecretary()
    {
        if(tail->name == "None")
        {
            std::cout << "There is no secretary to remove from the club" << std::endl;
        }
        else
        {
            std::cout << "Secretary " << tail->name << " (PRN - " << tail->prn << ") has been removed from the club." << std::endl;
            strcpy(tail->name, "None");
            tail->prn = 0;
        }
    }
    void delMember(char name[30])
    {
        member *tmp, *p;
        tmp = head;
        if(strcmp(head->name, "None") == 0 && strcmp(tail->name, "None") == 0 && head->next == tail)
        {
            std::cout << "No members in the club" << std::endl;
        }
        else
        {
            while(tmp != NULL)
            {
                if(strcmp(head->name, name) == 0)
                {
                    std::cout << "The president cannot be removed with this. Please use: 4. Remove President." << std::endl;
                    break;
                }
                else if(strcmp(tail->name, name) == 0)   //strcmp=returns zero if statement is false
                {
                    std::cout << "The secretary cannot be removed with this. Please use: 5. Remove Secretary." << std::endl;
                    break;
                }
                else if(strcmp(tmp->name, name) == 0)
                {
                    std::cout << "Member " << tmp->name << " (PRN - " << tmp->prn << ")" << "is removed from the club." << std::endl;
                    p->next = tmp->next;
                    delete tmp;
                    break;
                }
                else
                {
                    p = tmp;
                    tmp = tmp->next;
                }
                if (tmp == NULL)
                {
                    std::cout << "Member not found" << std::endl;
                }
            }
        }
    }
    void display()
    {
        member *tmp;
        tmp = head;
        if(strcmp(head->name, "None") == 0 && strcmp(tail->name, "None") == 0 && head->next == tail)
        {
            std::cout << "No members in the club" << std::endl;
        }
        else
        {
            while(tmp != NULL)
            {
                if(tmp == head)
                {
                    std::cout << "President: " << tmp->name << " (PRN - " << tmp->prn << ")" << std::endl;
                    tmp = tmp->next;
                }
                else if(tmp->next == NULL)
                {
                    std::cout << "Secretary: " << tmp->name << " (PRN - " << tmp->prn << ")" << std::endl;
                    tmp = tmp->next;
                }
                else
                {
                    std::cout << "Member: " << tmp->name << " (PRN - " << tmp->prn << ")" << std::endl;
                    tmp = tmp->next;
                }
            }
        }
    }
    void count()
    {
        int count = 0;
        member *tmp;
        tmp = head;
        if(strcmp(head->name, "None") == 0 && strcmp(tail->name, "None") == 0 && head->next == tail)
        {
            count = 0;
        }
        else if((strcmp(head->name, "None") == 0 || strcmp(tail->name, "None") == 0) && head->next == tail)
        {
            count = 1;
        }
        else
        {
            while(tmp != NULL)
            {
                count++;
                tmp = tmp->next;
            }
        }
        std::cout << "Total number of members: " << count << std::endl;
    }
    void concatenate(club c1, club c2)
    {
        member *tmp, *tmp2;
        tmp = c1.head;
        while(tmp != NULL)
        {
            addMember(tmp->prn, tmp->name);
            tmp = tmp->next;
        }
        tmp = c2.head;
        while(tmp != NULL)
        {
            addMember(tmp->prn, tmp->name);
            tmp = tmp->next;
        }
    }
};
void menu(club c)
{
    int choice;
    char name[30];
    int prn;
    do
    {
        std::cout << "\nWhat do you want to do?" << std::endl;
        std::cout << "1. Add President" << std::endl;
        std::cout << "2. Add Secretary" << std::endl;
        std::cout << "3. Add member" << std::endl;
        std::cout << "4. Remove President" << std::endl;
        std::cout << "5. Remove Secretary" << std::endl;
        std::cout << "6. Remove member" << std::endl;
        std::cout << "7. Display members" << std::endl;
        std::cout << "8. Count members" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Enter your choice (1 - 9): ";
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            std::cout << "Enter name of the president: ";
            (std::cin >> std::ws).getline(name, 30);
            std::cout << "Enter PRN of the president: ";
            std::cin >> prn;
            c.addPresident(name, prn);
            break;
            case 2:
            std::cout << "Enter name of the secretary: ";
            (std::cin >> std::ws).getline(name, 30);
            std::cout << "Enter PRN of the secretary: ";
            std::cin >> prn;
            c.addSecretary(name, prn);
            break;
            case 3:
            std::cout << "Enter name: ";
            (std::cin >> std::ws).getline(name, 30);
            std::cout << "Enter PRN: ";
            std::cin >> prn;
            c.addMember(prn, name);
            break;
            case 4:
            c.delPresident();
            break;
            case 5:
            c.delSecretary();
            break;
            case 6:
            std::cout << "Enter name: ";
            (std::cin >> std::ws).getline(name, 30);
            c.delMember(name);
            break;
            case 7:
            std::cout << "Members of the Pinnacle club from this class are: " << std::endl;
            c.display();
            break;
            case 8:
            c.count();
            break;
            case 9:
            std::cout << "Exiting this class" << std::endl;
            break;
            default:
            std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 9);
}
int main()
{
    int choice;
    club class1, class2, conclass;
    std::cout << "Welcome to Pinaccle Club!" << std::endl;
    do
    {
        std::cout << "\nWhich class do you want to work with?" << std::endl;
        std::cout << "1. Class A" << std::endl;
        std::cout << "2. Class B" << std::endl;
        std::cout << "3. Concatenate the two classes" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice (1/2/3/4): ";
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            menu(class1);
            break;
            case 2:
            menu(class2);
            break;
            case 3:
            conclass.concatenate(class1, class2);
            std::cout << "Concatenated class: " << std::endl;
            conclass.display();
            break;
            case 4:
            std::cout << "Exiting..." << std::endl;
            break;
            default:
            std::cout << "Invalid choice" << std::endl;
        }
    }while(choice != 4);
    std::cout << "\nThank you for using the program!\n\t\t-Pinnacle Club" << std::endl;
    getchar();
    return 0;
}
/*club Class:

The club class is defined to implement a singly linked list to maintain club member's information.
It contains a private structure member that holds the name, PRN (Personal Registration Number), and a pointer to the next member.
head and tail are pointers to the first and last members, respectively.
Constructor:

Initializes head and tail with default values representing "None" for names and 0 for PRN.
Member Functions:

addPresident(char name[30], int prn): Adds the president to the club by updating the head node.
addSecretary(char name[30], int prn): Adds the secretary to the club by updating the tail node.
addMember(int prn, char name[30]): Adds a member to the club by creating a new node and connecting it to the end of the list.
delPresident(): Removes the president from the club.
delSecretary(): Removes the secretary from the club.
delMember(char name[30]): Removes a member from the club by traversing the list and updating pointers.
display(): Displays the information of all members, including the president and secretary.
count(): Computes and displays the total number of members in the club.
concatenate(club c1, club c2): Concatenates the members of two clubs into the current club.
Menu Function (menu):

Takes user input to perform various operations on the club.
Uses a switch-case structure to execute the selected operation.
Invokes corresponding member functions based on user input.
Main Function:

Initializes three instances of the club class for two classes (class1 and class2) and a concatenated class (conclass).
Displays a welcome message and enters a loop to interact with the user until the user chooses to exit.
Uses a switch-case structure to select the class to work with or concatenate classes.
Invokes the menu function to perform operations on the selected class.
Displays a thank you message upon program completion.
This program allows users to manage the Pinnacle Club's members, including adding/removing members, displaying member information, computing the total number of members, and concatenating two classes.*/
