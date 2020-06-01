#include <bits/stdc++.h>
using namespace std;
int least_avg(int arr[],int n)
{
   sort(arr,arr+n);
   int j,k,t=0;
   for(int i=n-1;i>=0;i--)
   {
   		j = 0;
   		k = i-1;
   		while(j<k)
   		{
   			if(arr[i] == arr[j]+arr[k])
   				{j++;t++;k--;}
   			if(arr[i] > arr[j]+arr[k])
   				j++;
   			else
   				k--;
   		}
   }
   return t;
}
int main() {
	//code
	int tc,k,n,*arr;
	cin>>tc;
	while(tc--)
	{
	    cin>>n;
	    arr = new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int ans = least_avg(arr,n);
	    if(ans)
	    	cout<<ans<<"\n";
	    else
	    	cout<<"-1"<<"\n";
	}
	return 0;
}