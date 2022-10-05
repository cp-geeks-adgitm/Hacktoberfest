#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
	freopen("inputtest.txt","r",stdin);
	freopen("outputtest.txt","w",stdout);
#endif
vector<int> A;
int n;
cin>>n;
for(int i=0;i<n;i++){
	int x;
	cin>>x;
	A.push_back(x);
}
cout<<"Enter the item to be searched \n";
int item,f=0,pos=-1;
cin>>item;
for(int i=0;i<n;i++){
	if(A[i]==item){
		pos=i+1;
		f=1;
		//break;
	}
}
if(f==0){
	cout<<"Item not found"<<endl;
}else{
	cout<<"Found the item at "<<pos;

}
	return 0;
}
