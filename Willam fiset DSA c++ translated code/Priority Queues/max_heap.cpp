#include<iostream>
#include<math.h>
using namespace std;


/* Building a max heap */
class BinaryHeap
{
    private:
    int* arr;
    int n;
    int capacity;

    void swap(int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

public:
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    void Heapify(int k) 
    {
        int largest  = k;
        int l = 2 * k + 1;
        int r = 2 * k + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != k) {
            swap(largest,k);
            Heapify(largest);
        }
    }

    int get_size()
    {
        return n;
    }
    BinaryHeap(int sz) {
        this->n = 0;
        this->capacity = sz;
        arr = new int[capacity];
    }
    
  
    void add(int elem)
    {
        if (n == capacity) {
            throw runtime_error("Heap is full");
        }
        
        n++;
        int i = n - 1;
        arr[i] = elem;
        
        int parent = (i-1)/2;
        while(i != 0 && arr[parent] < arr[i]) {
            swap(parent,i);
            i = parent;
            parent = (i - 1)/2;
        }
    }

    void show() {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

void BuildHeap(BinaryHeap &h) 
{

    for(int i = h.get_size()/2-1; i >= 0; i--)
    {	
        h.Heapify(i);
    }

}
//  void max_heapify(int arr[], int n, int k) 
//     {
//         int largest  = k;
//         int l = 2 * k + 1;
//         int r = 2 * k + 2;

//         if (l < n && arr[l] > arr[largest])
//             largest = l;

//         if (r < n && arr[r] > arr[largest])
//             largest = r;

//         if (largest != k) {
//             swap(arr[k],arr[largest]);
//             max_heapify(arr,n,largest);
//         }
//     }

//   // converts an unsorted array into binary heap where n is length of array
//     void buildHeap(int arr[],int n) 
//     {
//         // index of last no-leaf node
//         int startidx = (n/2) - 1;

//         for (int i = startidx; i >= 0; i--) {
//             max_heapify(arr,n,i);
//         }
//     }

//     void printHeap(int arr[], int n) 
//     {
//         for (int i = 0; i < n; ++i)
//             cout << arr[i] << " ";
        
//         cout << endl;
//     }


int main() 
{
    BinaryHeap maxH(100);
    
    maxH.add(51);
    maxH.add(5);
    maxH.add(23);
    maxH.add(15);
    maxH.add(25);
    maxH.add(53);
    maxH.add(42);
    maxH.add(12);
    maxH.add(7);
    maxH.add(81);
    maxH.add(121);
    maxH.add(96);
    maxH.add(-2);
    maxH.add(-12);
    maxH.add(39);
    maxH.show();
       
}
