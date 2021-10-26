// 622. Design Circular Queue

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int* arr;
    int size, front, rear;
    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        front = rear = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        if(front == -1) front = 0; //one element
        rear = (rear+1)%size;
        arr[rear] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        if(front == rear) front = rear = -1; // one element
        else front = (front +1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(front == -1) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((front == 0 && rear == size-1) || front == rear+1) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */