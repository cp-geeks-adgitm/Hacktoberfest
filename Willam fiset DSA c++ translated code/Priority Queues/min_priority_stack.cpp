/* Implementaion of stack using priority Queue */
/* asked in microsoft and adobe */
#include "bits/stdc++.h"
using namespace std;


class P_queue
{   
    private:
    int heapsize = 0;
    pair<int,int> arr[100];

    public:
    // max heap 
    bool isEmpty()
    {
        return heapsize == 0;
    }

    void push(pair<int,int> elem)
    {
        int k = heapsize - 1;
        arr[++k] = elem;
        heapsize++;
        int parent = (k - 1)/2;
        while(k > 0 && arr[k].first >= arr[parent].first)
        {   
            // swappair<int,int>ng
            int temp = arr[k].first;
            arr[k].first = arr[parent].first;
            arr[parent].first = temp;

            temp = arr[k].second;
            arr[k].second = arr[parent].second;
            arr[parent].second = temp;
 
            k = parent;
            parent = (k-1)/2;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !\n";
            return;
        }
        arr[0].first = arr[heapsize-1].first;
        arr[0].second = arr[heapsize-1].second;
        heapsize--;
        // sink
        int k = 0;
        while (true)
        {
            int l = 2*k + 1;
            int r = 2*k + 2;
            int largest = l;
            if (r < heapsize && arr[r].first >= arr[l].first)
                largest = r;
            if (l >= heapsize || arr[k].first >= arr[largest].first)
                break;

            int temp = arr[k].first;
            arr[k].first = arr[largest].first;
            arr[largest].first = temp;

            temp = arr[k].second;
            arr[k].second = arr[largest].second;
            arr[largest].second = temp;

            k = largest;
           
        }    
    }

    int top()
    {
        return arr[0].second;
    }
};

class Stack
{
    private:
    int cnt; // priority
    P_queue pq;

    public:
    Stack() : cnt(0) {} // another way to initialize a constructor 
    
    void push(int val)
    {
        cnt++;
        pq.push(pair<int,int>(cnt,val));
    }

    void pop()
    {
        cnt--;
        pq.pop();
    }

    void show()
    {
        while(!pq.isEmpty()) 
        {
            cout << pq.top() << "\n";
            pq.pop();
        } 
    }
};

int main()
{
    Stack gg;
    gg.push(3);
    gg.push(1);
    gg.push(2);
    gg.pop();
    gg.pop();
    gg.pop();
    gg.pop();
    gg.show();

}