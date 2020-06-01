#include <bits/stdc++.h>
using namespace std;
#define r 4
#define c 4

bool dfs(char mat[r][c],int x,int y,int nr,int nc,string str,int level)
{
    int l = str.length();
    //string match
    if(l==level)
        return true;
    //out of boundary
    if(x<0 || y<0 || x>=nr || y>=nc)
        return false;

    if(mat[x][y]==str[level])
    {
        char t = mat[x][y];
        mat[x][y] = '-';
        bool res = dfs(mat,x-1,y,nr,nc,str,level+1)|
                   dfs(mat,x+11,y,nr,nc,str,level+1)|
                   dfs(mat,x,y-1,nr,nc,str,level+1)|
                   dfs(mat,x,y+1,nr,nc,str,level+1);
        mat[x][y] = '-';
        return res;
    }
    else
    return false;
}
bool wordsearch(char mat[r][c],string str)
{   
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j] == str[0] && dfs(mat,i,j,r,c,str,0))
                return true;
        }
    }
    return false;
}
int main() {
	char mat[r][c] = {
                        {'A','B','C','D'},
                        {'E','F','G','R'},
                        {'I','J','D','E'},
                        {'K','L','O','C'}
                     };
    string str = "CODER";
    if(wordsearch(mat,str))
        cout<<"true";
    else
        cout<<"false";
	return 0;
}