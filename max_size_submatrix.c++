#include<bits/stdc++.h>
#define bool int
#define r 6
#define c 5
using namespace std;

void max_size(bool M[r][c])
{
    int s[r][c],i,j;
    //copy first column of M[][] to s[][]
    for(i=0;i<r;i++)
    {
        s[i][0] = M[i][0];
    }
    //copy first row of M[][] to s[][]
    for(j=0;j<c;j++)
    {
        s[0][j] = M[0][j];
    }
    //maximum entries of M[][] values to store a s[][]
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(M[i][j]==1)
            {
                s[i][j] = min(s[i-1][j],min(s[i][j-1],s[i-1][j-1]))+1;
            }
            else
            {
                s[i][j] = 0;
            }
        }
    }
    //find the maximum sub matrix and index of maximum sub matrix
    int max_sub = s[0][0],max_i = 0,max_j = 0;
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(max_sub<s[i][j])
            {
                max_sub = s[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    //print the maximum sub matrix 
    for(i=max_i;i>max_i-max_sub;i--)
    {
        for(j=max_j;j>max_j-max_sub;j--)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
   // int r = 6,c = 5;
    bool M[r][c] = 
    {
        {0,1,1,0,1},
        {1,1,0,1,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0}
    };
    max_size(M);
    return 0;
}