#include <iostream>
using namespace std;

//Structure of the Node
struct Node
{
    int data;
    
    Node *link;
};

// top pointer to keep track of the top of the stack
Node *top = NULL;

//Function to check if stack is empty or not
bool isempty()
{
    if(top == NULL)
    return true; else
    return false;
}

//Function to insert an element in stack
void push (int value)
{
    Node *ptr = new Node();
    ptr->data = value;
    ptr->link = top;
    top = ptr;
}

//Function to delete an element from the stack
void pop ( )
{
    if ( isempty() )
        cout<<"Stack is Empty";
    else
    {
      Node *ptr = top;
      top = top -> link;
      delete(ptr);
    }
}

// Function to show the element at the top of the stack
void showTop()
{
    if ( isempty() )
        cout<<"Stack is Empty";
    else
        cout<<"Element at top is : "<< top->data;
}

// Function to Display the stack
void displayStack()
{
    if ( isempty() )
        cout<<"Stack is Empty";
    else
    {
        Node *temp=top;
        while(temp!=NULL)
        {   cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<"\n";
    }
}

// Main function

int main()
{
    int choice, flag=1, value;

    while(flag == 1)  //Menu Driven Program using Switch
    {
        cout<<"\n1.Push 2.Pop 3.showTop 4.displayStack 5.exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1: cout<<"Enter Value:\n";
                    cin>>value;
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: showTop();
                    break;
            case 4: displayStack();
                    break;
            case 5: flag = 0;
                    break;
        }
    }
    return 0;
}