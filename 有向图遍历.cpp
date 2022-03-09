#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
#define _ ios_base::sync_with_stdio(0),cin.tie(0)
const int maxn=1e3+5;
vector<int> mp[maxn];
bool vis[maxn];
void dfs(int start)
{
	int count=0;
	for(int i=0;i<mp[start].size();i++)
	{
		if(vis[mp[start][i]]==0)
		{
			vis[mp[start][i]]=true;
			dfs(mp[start][i]);
			count++;
		}
	}
	cout<<count<<endl;
}

int main()
{
	_;
	int n,m;
	memset(vis,0,sizeof vis);
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v); 
		vis[u][v]=1;
	}
	
	dfs(1);
}
