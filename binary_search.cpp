#include <iostream>
using namespace std;
// binary search is valid when you have monotonic array it is not valid when array is unsorted
// steps
// 1. finding middle element
// 2. compare mid with key if equal return index otherwise decide in which part we need to search for now
int binarysearch(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        // jb right side m jana h
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        // jb left side m jana ho tb
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int even[] = {2, 3, 4, 5};
    int odd[] = {7, 9, 11};
    int index = binarysearch(even, 4, 5);
    cout << "index of 5 is " << index << endl;
    return 0;
}
// why we studied linear search in place of binary search as its time complexity is o(n ) whereas for binary it is log(n)
