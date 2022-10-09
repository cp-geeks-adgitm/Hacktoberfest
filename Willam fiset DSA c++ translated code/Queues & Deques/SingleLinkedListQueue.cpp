/* Implementation of Queue using Single Linked List */
#include <iostream>
using namespace std;

class Node 
{
    public:
    int val;
    Node *next;

    Node(int val) 
    {
        this->val = val;
        this->next = NULL;
    }
 
};

class Queue 
{
    private:
    int size;
    Node *front;
    Node *rear;

    public:
    Queue() 
    {
        size = 0;
        this->front = NULL;
        this->rear = NULL;
    }

    int Getsize() const {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    // Add to rear
    void Enqueue(int element)
    {
        if (isEmpty()) {
            front = rear = new Node(element);
            size++;
            return;
        }
        Node *new_elem = new Node(element);
        rear->next = new_elem;
        rear = new_elem;
        size++;
    } 

    // remove from front
    void Dequeue() 
    {
        if (isEmpty()) {
            throw invalid_argument("Queue is Empty.");
        }
        Node *temp = front;
        front = front->next;
        size--;
        delete(temp); 
    }

    void show()
    {
        if (isEmpty()) { 
            cout << "Queue is Empty." << '\n';
        }
        Node *ptr = front;
        while(ptr != NULL) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.show();
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.show();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.show();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.show();
}