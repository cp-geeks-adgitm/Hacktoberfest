/* Implementation of Priority Queue using Binary Heap(min_heap) */
#include<iostream>
using namespace std;

class PriorityQueue
{
private:
    int *arr;
    int capacity;
    int heap_size;

    void swap(int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void swim(int k)// min heap
    {
        int parent = (k-1)/2;
        while(k > 0 && arr[k] <= arr[parent]) {
            swap(parent,k);
            k = parent;
            parent = (k-1)/2;
        }
    }
    
    void sink(int k)
    {
        while(true)
        {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int smallest = left;
            if (right < heap_size && arr[right] <= arr[left])
                smallest = right;
            if (left >= heap_size || arr[k] <= arr[smallest])
                break;
            
            swap(smallest,k);
            k = smallest;
        }
    }

public:
    PriorityQueue(int cap) {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap]; 
    }

    bool isEmpty() {
        return size() == 0;
    }

    int size() {
        return  heap_size;
    }

    void add(int elem) 
    {
        if (heap_size == capacity) 
            throw invalid_argument("Queue is Full.");
        
        int indexofLastElem = heap_size - 1;
        arr[++indexofLastElem] = elem;
        heap_size++;
        swim(indexofLastElem);
    }

    // removes the element with highest priority
    void poll() 
    {
        if (isEmpty())
            throw runtime_error("Queue is Empty");

        arr[0] = arr[heap_size - 1];
        heap_size--;
        sink(0);
    }

    // removes a particular element in the heap, O(n)
    void remove(int elem)
    {
        for (int i = 0; i < heap_size; ++i)
        {
            if (arr[i]  == elem)
            {
                removeAt(i);
                return;
            }
        }
        cout << "Element Not Present" << "\n";
    }

    // removest at particular index at o(log(n))
    void removeAt(int index)
    { 
        if (isEmpty()) {
            throw runtime_error("Queue is Empty");
        }
        int indexOfLastElem = heap_size - 1;
        swap(index,indexOfLastElem);
        heap_size--;
        if (index == indexOfLastElem)
            return ;
        
        int elem = arr[index];
        sink(index);

        // if sinking does not work try swimming 
        if (elem = arr[index])
            swim(index);
    }

    void show()
    {
        if (isEmpty())
            cout << "Queue is Empty";
        for (int i = 0;i < heap_size; ++i)  
            cout << arr[i] << " ";
        cout << '\n';
    }
};

int main() 
{
    PriorityQueue pq(100);
    pq.add(10);
    pq.add(30);
    pq.add(50);
    pq.add(4);
    pq.add(100);
    pq.add(500);
    pq.add(600);
    pq.add(3);
    pq.add(2);
    pq.add(1);
    // pq.show();
    // pq.poll();
    pq.show();
    pq.remove(3);
    pq.show();

}
