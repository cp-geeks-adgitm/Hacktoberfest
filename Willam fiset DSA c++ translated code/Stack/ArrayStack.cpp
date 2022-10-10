/* Implementation of stack using Arrays */
#include<iostream>
using namespace std;

#define max_size 1000

class Stack 
{
    private:
    int arr[max_size];
    int top;

    public:
    Stack()
    {
        top = -1;    
    }
    
    int Getsize() const {
        return top+1;
    }

    bool isEmpty() {
        return Getsize() == 0;
    }
    void push(int element) {
        if (top == max_size - 1) {
            throw invalid_argument("Stack Overflow");
        }
        arr[++top] = element;
    }

    void pop() {
        if (isEmpty()) {
            throw invalid_argument("Stack Underflow");
        }
        top--;
    }

    void show() {
        if (isEmpty()) {
            cout << "Stack is Empty !\n";
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << "\n";
        }
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.push(30);
    // s.show();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    // s.pop();
    // s.pop();
    s.show();
    
}