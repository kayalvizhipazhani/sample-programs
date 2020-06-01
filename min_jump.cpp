 #include <bits/stdc++.h>
using namespace std;
int min_jump(int arr[],int n)
{
    int jump[n];
    jump[0] = 0;
    if(arr[i]==0 || n==1)
        return -1;
    for(int i=1;i<n;i++)
    {
        jump[i] = INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(i<=j+arr[j] && jump[j] != INT_MAX)
            {
                jump[i] = min(jump[i],jump[j]+1);
                break;
            }
        }
        if(jump[i]==INT_MAX)
            return -1;
    }
    return jump[n-1]; 
}
int main() {
	int arr[] = {2,1,3,2,3,4,5,1,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
	cout<<min_jump(arr,n);
	cout<<"\n";
	return 0;
}