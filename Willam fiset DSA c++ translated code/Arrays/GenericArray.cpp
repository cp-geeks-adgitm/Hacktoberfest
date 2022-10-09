#include <iostream>
using namespace std;

template<class T>
class Array 
{
    public:
    T *arr; 
    T len;    
    T capacity;

    public:
    Array() 
    {
        len = 0;
        capacity = 0;
    }
   
    Array(T capacity) 
    {
        capacity = capacity;
        arr  = new T[capacity];
    }

    int Size() const 
    {
        return len;
    }

    bool isEmpty() 
    {
        return Size() == 0;
    }

    T get(int index)
    {
        if (index >= len || index < 0 )
            throw invalid_argument("Index is out of bounds");
        
        return arr[index];
    }

    void Set(int index, T element)
    {
        if (index >= len || index < 0 )
            throw invalid_argument("Index is out of bounds");
        
        arr[index] = element;
    }
    
    void clear()
    {
        for (int i = 0; i < len; ++i)
            arr[i] = NULL;
        
        len = 0;
    }

    void Add(T element)
    {
        if (len + 1 >= capacity)
        {
            if (capacity == 0) 
                capacity = 1;
            else 
                capacity *= 2; // double the size

            T *new_arr = new T[capacity];
            for (int i = 0; i < len; i++) 
                new_arr[i] = arr[i];

            arr = new_arr;  // make the old array as the new array  
        }

        arr[len++] = element;
    }

    // Removes an element at the specified index in this array.
    T removeAt(int index)
    {
        if (index >= len || index < 0)
            throw invalid_argument("Index is out of bounds");

        T data = arr[index];
        T *new_arr = new T[len-1];
        for (int i = 0,j = 0; i < len; i++,j++)
        {
            if (i == index) 
                j--;
            else
                new_arr[j] = arr[i];
        }
        arr = new_arr;
        capacity = --len;

        return data;
    }


    void show() 
    {
        for (int i = 0; i < len; ++i) 
            cout << arr[i] << " ";
        cout << '\n';
    }

};  

int main() 
{
  Array<int> ar;

  ar.Add(3);
  ar.Add(7);
  ar.Add(6);
  ar.Add(-2);
  ar.Add(9);
  ar.removeAt(0);
// ar.remove(1);
// ar.remove(1);
  ar.show();

}