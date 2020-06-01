#include <bits/stdc++.h>
#define N 50
using namespace std;

bool is_rectangle_there(int arr[N][N], int n, int x);

int main()
{
    int arr[N][N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>> arr[i][j];
        
        int x;
        cin>>x;
        
        if( is_rectangle_there(arr,n,x) )
            cout<< "Yes" << endl;
        else
            cout<< "No" << endl;
    }
	return 0;
}
// } Driver Code Ends


bool is_rectangle_there(int arr[N][N], int n, int x)
{
    // code here
    
    
    int sum[n][n];
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        sum[i][j]=0;
    }
    
    
    for(int i=0;i<n;i++){
        
        for(int j=i;j>=0;j--){
            
            for(int k=0;k<n;k++)
            sum[j][k]=sum[j][k]+arr[i][k];
            
            int start=0,end=0,ans=0;
            while(1){
                
                if(ans==x){
                    return 1;
                }
                if(ans>x){
                    ans=ans-sum[j][start];
                    start++;
                }
                else{
                    if(end==n)
                    break;
                    ans=ans+sum[j][end];
                    end++;
                }
            }
            
        }
        
    }
    
    return 0;
}
