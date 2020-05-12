#include<bits/stdc++.h>
using namespace std;
#define N 100
typedef long long int ll;
vector<int> adj[2005];
int color[2005];
bool checkbip(int s)
{
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int start = q.front();
		q.pop();
		for(int l = 0 ; l<adj[start].size();l++)
		{
			int adjacent = adj[start][l];
			if(color[adjacent]== color[start])
			return false;
			else if(color[adjacent]==-1)
			 {
			   color[adjacent] = !color[start];
			   q.push(adjacent);
			 }
			
		}
	}
	return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,bugs,interac,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>bugs>>interac;
    	for(int k=1;k<=bugs;k++)
    	adj[k].clear();
    	for(int j=0;j<interac ;j++)
    	{
    		cin>>x>>y;
    		adj[x].push_back(y); 
    		adj[y].push_back(x);
		}   
		memset(color, -1, sizeof(color));
		bool res=true;
		for(int k=1;k<=n;k++)
		{
			if(color[k] == -1)
			{
				color[k]=1;
				res = res & checkbip(k);
			}
		}
		if(res) 
		cout<<"Scenario #"<<(i+1)<<":\n"<<"No suspicious bugs found!\n";
		else
		cout<<"Scenario #"<<(i+1)<<":\n"<<"Suspicious bugs found!\n";
	}
	
}
