#include <bits/stdc++.h>
using namespace std;
int min_dis(int arr[],int n,int x,int y)
{
    int i,pre,min = INT_MAX;
    for(i=0;i<n;i++)
    {
    	if(arr[i]==x || arr[i]==y)
    	{
    		pre = i;
    		break;
    	}
    }
    for( ;i<n;i++)
    {
    	if(arr[i]==x || arr[i]==y)
    	{
    		if(arr[i] != arr[pre] && min>i-pre)
    		{
    			min = i-pre;
    			pre = i;
    		}
    		else
    		{
    			pre = i;
    		}
    	}
    }
    return min;
}
int main() {
	int tc,x=1,y=2,n=4;
	int arr[n] = {1,2,3,2};
	cout<<min_dis(arr,n,x,y);
	cout<<"\n";
	return 0;
}