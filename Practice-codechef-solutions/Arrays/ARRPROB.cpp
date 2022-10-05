#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	  int   a[n];
	  long long s1=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	            s1+=a[i];
	    }
	    for(int i=0;i<n;i++){
	        cout<<s1-a[i]<<" ";
	       
	    }
	    cout<<endl;
	}
	return 0;
}
