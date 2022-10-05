#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int c=0;
    while(n!=0){
        c++;
        n/=10;
    }
    cout<<c<<endl;
    //write your code here
    
}