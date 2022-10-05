#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int a=0,b=1;
      int c=a+b;
      cout<<a<<endl;
      cout<<b<<endl;
      while(c<n){
        cout<<c<<endl;
        a=b;
        b=c;
        c=a+b;
        
      }
    //write your code here
    
}