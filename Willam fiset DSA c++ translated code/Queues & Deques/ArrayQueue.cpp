/* Implementation of Queue using Arrays */
#include <iostream>
#define max_size 6

using namespace std;

class Queue 
{
    private:
    int size;
    int arr[max_size];
    int front,rear;

    public:
    Queue()
    {
        size = 0;
        front = rear = 0;
    }

    int Getsize() const {
        return rear - front;
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return rear == max_size;
    }

    void Enqueue(int element)
    {
        if (isFull()) {
            throw runtime_error("Queue is Full");
        }
        arr[rear++] = element;
        size++;
    }

    void Dequeue()
    {
        if (isEmpty()) {
            throw runtime_error("Queue is Empty.");
        }
        size--;
        front++;
    }

    void show()
    {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        for (int i = front; i < rear; ++i) {
            cout << arr[i] << ' ';
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
    cout << q.Getsize() << '\n';
    q.show();
    q.Dequeue();
    q.Dequeue();
    q.show();
    // q.Enqueue(80);
    // q.Enqueue(90);
    q.show();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    // q.Dequeue();
    // q.Dequeue();
    q.show();



    // q.Dequeue();
    // cout << q.Getsize() << '\n';
    // q.show();
    // q.Dequeue();
    // q.Dequeue();
    // q.Dequeue();
    // q.show();
}