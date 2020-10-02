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
int item,f=0;
cin>>item;
int begin=0,end=n,mid=0;
while(begin<=end){
	mid=begin+(end-begin)/2;
	if(A[mid]==item){
		cout<<"Found the item at "<<mid+1;
		f=1;
		break;
	}else if(A[mid]>item){
		end=mid-1;
	}else{
		begin=mid+1;
	}

}
if(f==0){
	cout<<"Item not found"<<endl;
}
return 0;
}
