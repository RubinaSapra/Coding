#include<bits/stdc++.h>
using namespace std;
int row[]= {-1,1, 0, 0};
int col[]= {0, 0,-1 , 1};
int n=0,m=0;
bool bfs(int i, int j, int r, int c, int endi, int endj ,vector<vector<char> > &a ,int k)
{
	a[i][j]='*';
	for(int x=0;x<4;x++)
	{
		int ci = i+row[x]; int cj = j+col[x];
		if(ci>=0 && ci<r && cj>=0 && cj<c)
		{
		   if(ci == endi && cj == endj )
		   {
		   	if((k-1) <=0 )
		   	return true;
		   }
		   else if(a[ci][cj]!='*')
		   {
		   	if(bfs(ci,cj,r,c,endi,endj,a,k-1))
		   	return true;
		   }
			
		}
	}
	a[i][j]='.';
	return false;
}
int main()
{
	int k,s,e;
	cin>>n>>m>>k>>s>>e;
	vector<vector<char> > a( n ,vector<char> (m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>a[i][j];
	}
	if(bfs(s-1,e-1,n,m,s-1,e-1,a,k)) 
	cout<<"YES\n";
	else
	cout<<"NO\n";
}
