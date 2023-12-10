/*Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.*/

#include<iostream>
#include<conio.h>               //provide console input output
using namespace std;
class stack
{
 public:
  char stack_array[20];
  int top;
  stack()
  {
    top=-1;
  }
void push(char symbol)
{  if(full())
      cout<<"\nOverflow occured\n";
    else
    { top=top+1;
      stack_array[top]=symbol;
     }
}
char pop()
{   if(empty())
       return('#');        
     else
       return(stack_array[top--]);
}
int empty()
{    if(top==-1)
       return true;
     else
       return false;
}
int full()
{    if(top==49)
       return true;
     else
       return false;
}
private:
  char infix[50];
  char postfix[50];
 public:
    void read()
    {
      cout<<"\nEnter your infix expression:";
      cin>>infix;
    }
int white_space(char symbol)
  {  if(symbol==' ' || symbol=='\t' || symbol=='\0')
         return true;
      else
        return false;
  }
void ConvertToPostfix()
 {    int prev,p;
      char entry;
      p=0;
      for(int i=0;infix[i]!='\0';i++)
      {
    if(!white_space(infix[i]))
    { switch(infix[i])
      {
        case '(': push(infix[i]);
                  break;
        case ')': while((entry=pop())!='(')
                  postfix[p++]=entry;
                  break;
        case '+':
        case '-':
        case '*':
        case '/':
        if(!empty())
          {  prev=prior(infix[i]);
             entry=pop();
         while(prev<=prior(entry))
         {  postfix[p++]=entry;
           if(!empty())
              entry=pop();
           else
              break;
         }
        if(prev>prior(entry))
           push(entry);
        }
          push(infix[i]);
          break;
          default:
          postfix[p++]=infix[i];
          break;
        }
      }
    }
      while(!empty())                //while stack is not empty
       postfix[p++]=pop();
    postfix[p]='\0';
    cout<<"\nThe postfix expression is: "<<postfix<<endl;
  }
int prior(char symbol)
{  switch(symbol)
    { case '/': return(4);          // Precedence of / is 4
      case '*': return(3);          // Precedence of * is 3
      case '+': return(2);          // Precedence of + is 2
      case '-': return(1);          // Precedence of - is 1
      case '(': return(0);          // Precedence of ( is 0
      default: return(-1);
    }
  }
};
int main()
{  char choice='y';
   stack expr;
   while(choice=='y')
  {expr.read();
   expr.ConvertToPostfix();
   cout<<"\n\nDo you want to continue ? (y/n): ";
   cin>>choice;
 }
 return 0;
}/*stack Class:

stack_array: Array to store characters in the stack.
top: Integer representing the top of the stack.
Constructor:

Initializes top to -1.
Member Functions:

push(char symbol): Pushes the given symbol onto the stack.
pop(): Pops and returns the top element from the stack.
empty(): Checks if the stack is empty.
full(): Checks if the stack is full.
read(): Reads the infix expression from the user.
white_space(char symbol): Checks if the given symbol is whitespace.
ConvertToPostfix(): Converts the infix expression to postfix using the stack.
prior(char symbol): Returns the precedence of the given operator.
main Function:

Creates an instance of the stack class called expr.
Uses a loop to allow the user to input multiple infix expressions.
Calls the read() function to input the infix expression.
Calls the ConvertToPostfix() function to convert infix to postfix.
Asks the user if they want to continue.
Postfix Conversion Algorithm (ConvertToPostfix Function):

Initializes variables prev, p, and entry.
Iterates through the infix expression character by character.
Checks if the character is not whitespace using white_space function.
Switches on the character:
'(' - Pushes onto the stack.
')' - Pops from the stack until '(' is encountered.
'+', '-', '*', '/' - Handles operator precedence and pushes/pops accordingly.
Default - Operand, appends to the postfix expression.
Pops any remaining operators from the stack and appends them to the postfix expression.
Outputs the final postfix expression.
Operator Precedence (prior Function):

Returns the precedence of the given operator*/
