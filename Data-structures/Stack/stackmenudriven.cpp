/*  C++ Menu Driven Program for Stack Operations Using Arrays  */


#include<stdio.h>
#include<iostream>

using namespace std;

class Stack
{
int top;
int arr[50];
public:
    Stack()
{
       top=-1;
}

    void push();
    void pop();
    void view();
    int isEmpty();
    int isFull();
};

int Stack::isEmpty()
{
    return (top==(-1)?1:0);
}

int Stack::isFull()
{
    return ( top == 50 ? 1 : 0 );
}

void Stack::push()
{
    if(isFull())
    {
        cout<<"\nSTACK IS FULL { OVERFLOW }";
    }
    else
    {
        int i;
        cout<<"\nEnter an element :: ";
        cin>>i;
        ++top;
        arr[top]=i;
        cout<<"\nInsertion successful.\n";
    }
}

void Stack::pop()
{
    int num;
    if(isEmpty())
    {
            cout<<"\n STACK IS EMPTY [ UNDERFLOW ] ";
    }
    else
    {
    cout<<"\nDeleted item is : "<<arr[top]<<"\n";
    top--;
    }
}

void Stack::view()
{
    if(isEmpty())
    {
            cout<<"\n STACK IS EMPTY [ UNDERFLOW ] ";
    }
    else
    {
    cout<<"\nSTACK :\n";
    for(int i=top;i>=0;i--)
    {
            cout<<arr[i]<<"\n";
    }
    }
}


int main()
{
    Stack s;
    int ch;
    ch=0;
    while(ch!=4)
    {
        cout<<"\n1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display\n";
        cout<<"4. Quit\n";
        cout<<"\nEnter your Choice :: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                s.push();
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.view();
                break;

            case 4:
                ch=4;
                cout<<"\nPress any key .. ";
                break;

            default:
                cout<<"\nWrong Choice!! \n";
                break;
        }
    }

    return 0;
}