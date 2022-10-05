#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	string s;
	cin>>s;
	char arr[n];
	for(int i=0;i<n;i++)
	{
	    arr[i]=s[i];
	}
	
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i];
	}
	return 0;
}
