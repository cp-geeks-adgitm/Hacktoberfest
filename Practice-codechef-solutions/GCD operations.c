#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
	    if((i+1) % arr[i] == 0)
	    {
	        count++;
	    }
	}
	if(count == n)
	{
	    printf("YES\n");
	}
	else printf("NO\n");
	}
	return 0;
}

