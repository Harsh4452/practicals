
/* A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, 
and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters
“poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse
the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program 
with functions- 
a) To print original string followed by reversed string using stack 
b) To check whether given string is palindrome or not */

#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class STACK
{
	private:
		char a[max];
		int top;
	
	public:
		STACK()
		{
			top=-1;	
		}	
		
		void push(char);
		void reverse();	
		void convert(char[]);
		void palindrome();
};

void STACK::push(char c)
{
	top++;
	a[top] = c;
	a[top+1]='\0';
	
	cout<<endl<<c<<" is pushed on stack ...";
}

void STACK::reverse()
{
	char str[max];
	
	cout<<"\n\nReverse string is : ";
		
	for(int i=top,j=0; i>=0; i--,j++)
	{
		cout<<a[i];
		str[j]=a[i];
	}
	
	cout<<endl;
}


void STACK::convert(char str[])
{
	int j,k,len = strlen(str);

	for(j=0, k=0; j<len; j++)
	{
		if( ( (int)str[j] >= 97 && (int)str[j] <=122 ) || ( (int)str[j] >= 65 && (int)str[j] <=90 ))
		{
			if( (int)str[j] <=90 )
			{
				str[k] = (char)( (int)str[j] + 32 );
			}else
			{
				str[k] = str[j];				
			}

			k++;			
		}
	}
	str[k]='\0';

	cout<<endl<<"Converted String : "<<str<<"\n";
}




void STACK::palindrome()
{	
	char str[max];
	int i,j;		

	for(i=top,j=0; i>=0; i--,j++)
	{
		str[j]=a[i];
	}
	str[j]='\0';
	
	
	if(strcmp(str,a) == 0)
		cout<<"\n\nString is palindrome...";
	else
		cout<<"\n\nString is not palindrome...";
}


int main()
{
	STACK stack;

	char str[max];
	int i=0;
	
	cout<<"\nEnter string to be reversed and check is it palindrome or not : \n\n";
	
	cin.getline(str , 50);
	
	stack.convert(str);
	
	while(str[i] != '\0')
	{
		stack.push(str[i]);
		i++;
	}

	stack.palindrome();

	stack.reverse();
	
}
/*STACK Class:

The STACK class is defined to implement a stack data structure.
Member Variables:

a: An array to represent the stack.
top: An integer variable to keep track of the top of the stack.
Member Functions:

push(char c): Pushes a character onto the stack.
reverse(): Reverses the characters in the stack and prints the reversed string.
convert(char str[]): Converts the input string to lowercase and removes non-alphabetic characters.
palindrome(): Checks whether the original string is a palindrome or not.
push Function:

Increments top and assigns the character to a[top].
Updates a[top+1] to '\0' to ensure the correct termination of the string.
Prints a message indicating that the character has been pushed onto the stack.
reverse Function:

Initializes an array str to store the reversed string.
Prints the reversed string while constructing the str array.
convert Function:

Converts the input string to lowercase and removes non-alphabetic characters.
Updates the input string with the modified one.
Prints the converted string.
palindrome Function:

Compares the reversed string (constructed in the reverse function) with the original string.
Prints whether the string is a palindrome or not.
main Function:

Creates an instance of the STACK class called stack.
Reads a string input from the user using cin.getline.
Calls convert to convert the input string.
Pushes each character of the string onto the stack using push.
Calls palindrome to check if the string is a palindrome.
Calls reverse to print the reversed string.*/

