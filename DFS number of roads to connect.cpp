// Rubina Sapra
// GryffHooman
//Number of connections in a graph to make it all connected
#include<bits/stdc++.h>
using namespace std;
#define N 100
typedef long long int ll;
vector<int> adj[800001];
int color[800001];
void dfs(vector<bool>&v, int i)
{
	v[i]= true;
//	cout<<"dfs  i = "<<i<<"\n";
    for(int it=0;it<adj[i].size(); it++)
    {
    	if(!v[adj[i][it]])
    	dfs(v,adj[i][it]);
	}
}
int dfs_util(int c)
{
   vector<bool>v(c,false);
	int cnt= 0;
	for(int i=0;i<c;i++ )
	{
		if(!v[i])
		{
			//cout<<" i = "<<i<<"\n";
			dfs(v,i);
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cities, roads,x,y;
	cin>>cities>>roads;
	for(int i=0;i<roads;i++)
	{
	  cin>>x>>y;
	  adj[x].push_back(y);
	  adj[y].push_back(x);	
	}
	cout<< dfs_util(cities)-1<<"\n";
}
