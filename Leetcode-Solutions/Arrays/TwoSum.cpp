@@ -0,0 +1,137 @@
//Two sum problem

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//function to sort the vector using count sort and return back to the function
vector<int> countsort(vector<int> s, int a, int tar){

    int c=s[0];

    //find the maximum in the vector
    for(int i=1; i<a; i++)
    {
        c=max(c,s[i]);
    }


    int arr[c+1];

    //initialising all elements in arr to 0
    for(int i=0; i<=c; i++)
    {
        arr[i]=0;
    }

    //storing the frequency of each number "n" in vector s in the nth number index in arr.   
    for(int i=0; i<a; i++)
    {
        arr[s[i]]++;
    }


    vector<int> s1;

    //storing the sorted vector in s1 
    for(int i=0; i<=c; i++)
    {
        if(arr[i]!=0)
        {
            for(int j =0; j<arr[i]; j++)
            {
                s1.push_back(i);
            }
        }
    } 


    //returning the sorted vector
    return s1;
}  

void getsumindices(vector<int> s1, int *arr, int n,int a,int tar)
{
    int low=0;
    int high=a-1;

    //initially taking low and high at two corners
    //checking the below condition to get to the target
    while(low<high)
    {
        if(s1[low]+s1[high]==tar)
        {
           break;
        }
        else if(s1[low]+s1[high]>tar)
        {
            high--;
        }
        else if(s1[low]+s1[high]<tar){
            low++;
        }
    }


     //got the two numbers now to print their indices in arr the main array
    int d=0;
    int d1=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==s1[low])
        {
             d=i;
        }

        if(arr[i]==s1[high])
        {
            d1=i;
        }
    }
    //print the two indices
    cout<<min(d,d1)<<" "<<max(d,d1)<<endl;

}   


int main()
{
    //input size of array
    int n;
    cin>>n;

    // input elements in array
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    //input the target value to check
    int tar;
    cin>>tar;

    vector<int> s;
    int a=0;

    //taking all the values less than the target value in an vector
    for(int i=0; i<n; i++)
    {
        if(arr[i]<tar)
        {
            s.push_back(arr[i]);
            a++;
        }
    }

    //calling function to sort the vector in ascending order 
    vector<int> s1=countsort(s,a,tar);

    //calling function to get the indices of number when added gives target value 
    getsumindices(s1,arr,n,a,tar);

}
