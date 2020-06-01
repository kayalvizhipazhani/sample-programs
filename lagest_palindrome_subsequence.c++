#include <iostream>

using namespace std;

int fun(string str)
{
    int n = str.length();
	int l[n][n];
	for(int i=0;i<n;i++)
	{
	   l[i][i] = 1;
	}
	for(int d=2;d<=n;d++)
	{
	    for(int i=0;i<n-d+1;i++)
	    {
	        int j =i+d-1;
	        if(str[i]==str[j] && d==2)
	            l[i][j] =  2;
	        if(str[i]==str[j])
	            l[i][j] = l[i+1][j-1]+2;
	        else
	            l[i][j] = max(l[i][j-1],l[i+1][j]);
	    }
	}
	return l[0][n-1];
}
int main()
{   
	string str;
	cin>>str;
	cout<<fun(str);
return 0;
}
