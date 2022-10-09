/* This program performs Searching, inserting, deleting in an Array */
/* This Program is more suitable for Working in Sorted Arrays */
#include <iostream>
using namespace std;

class Array 
{
    public:
    int arr[1000]; 
    int len;    

    public:
    Array() 
    {
        len = 0;
    }
   
    int Size() const 
    {
        return len;
    }

    void Add(int element,int index)
    {
        if (index < 0 || index > len) 
        {
            cout << "illegal input" ;
        }
        else 
        {
            for (int i = len; i > index; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[index] = element;
            len++;
        }
    }
    void remove(int index)  // 3 -2 9 6 7
    {
        if (index < 0 || index >= len)
            cout << "illegeal input";
        else
        {
            for (int i = index; i < len-1; i++)
            {
                arr[i] = arr[i+1];
            }
            len--;
        }
    }
    int Search(int element)
    {
	    for(int i = 0; i < len; i++) 
	    {
		    if(arr[i] == element)
			    return i;
	    }
	    return -1;	
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
  Array ar;

  ar.Add(10,0);
  ar.Add(20,1);
  ar.Add(30,2);
  ar.Add(40,3);
  ar.Add(50,4);
  ar.Add(6,0);
//   ar.remove(0);
//   ar.remove(1);
  ar.show();

}