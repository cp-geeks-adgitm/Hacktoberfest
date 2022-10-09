/* Implementation of stack using singly linked List */
#include <iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;

    Node(int value) 
    {
       data = value;
    }
};

class Stack 
{
    private:
    Node *top;
    int size;

    public:
    Stack() 
    {
        this->top = nullptr;
        size = 0;
    }

    int Getsize() {
        return size;
    }

    bool isEmpty() {
        return Getsize() == 0;
    }

    void push(int element) 
    {
        Node *new_elem = new Node(element);
        new_elem->next = top;
        top = new_elem;
        size++;
    }

    void pop()
    {   
        if (isEmpty()) {
            throw invalid_argument("Stack is Empty Cannot pop !");
        }

        Node *temp = top;
        top = top->next;
        size--;
        delete(temp);
    }

    void show() 
    {
        if (isEmpty()) {
            cout << "Stack is Empty!";
        }

        Node *ptr = top;
        while (ptr != nullptr) 
        {
            cout << ptr->data << '\n';
            ptr = ptr->next;
        }
    }
};

int main() 
{
    Stack s;
    s.push(10);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(100);
    // s.show();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.show();
}