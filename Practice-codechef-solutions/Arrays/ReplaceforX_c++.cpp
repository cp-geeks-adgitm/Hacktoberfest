#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,p,k;
        cin>>n>>x>>p>>k;
        int nums[n];
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        sort(nums, nums+n);
        int count=0;
        if(k==p)
        {
            int t= nums[p-1];
            int i= p-1;
            if(x<t)
            {
                while(nums[i]>x)
                {
                    count++;
                    if(i>0)
                    i--;
                    else break;
                }
                cout<<count;
                
            }
            else if(x==t)
            {
                cout<<0;
            }
            else
            {
                while(nums[i]<x)
                {
                    count++;
                    if(i<n-1)
                    i++;
                    else
                    break;
                }
                cout<<count;
            }
        }
        else if(k<p)
        {
            if(x<nums[p-1])
            {
                cout<<-1;
            }
            else
            {
               int i=p-1;
                while(nums[i]<x)
                {
                    count++;
                    if(i<n-1)
                    i++;
                    else
                    break;
                } 
                cout<<count;
            }
        }
        else
        {
            
          if(x>nums[p-1])
          cout<<-1;
          
            else
            {
                int i=p-1;
                while(nums[i]>x)
                {
                    count++;
                    if(i>0)
                    i--;
                    else
                    break;
                }
                cout<<count;
            }
        }
        
        cout<<"\n";
    }
	return 0;
}
