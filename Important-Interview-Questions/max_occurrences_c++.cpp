#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[n],Count,Max_count=0;
    int a = 0;
    while(a<n){
        cin >> arr[a];
        a++;
    }
    
    a=0;
    while(a<n){
        Count=1;
        int b=a+1;
        while(b<n){
            if(arr[a] == arr[b])
                Count++;
            b++;
        }
        if(Count > Max_count)
            Max_count=Count; 
        a++;
    }
    
    a=0;
    while(a<n){
        Count=1;
        int b=a+1;
        while(b<n){
            if(arr[a] == arr[b])
                Count++;
            b++;
        }
        if(Count == Max_count)
            cout << arr[a] << "\n";
        a++;
    }
}