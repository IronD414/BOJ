#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,V;
vector<int> adj[1001];
queue<int> Q;
bool dfs_disc[1001] = {false,};
bool bfs_disc[1001] = {false,};

void dfs(int v){
	cout << v << " ";
	dfs_disc[v] = true;
	for (auto it : adj[v]){
		if (!dfs_disc[it]){
			dfs(it);
		}
	}
}

void bfs(int v){
	cout << "\n";
	Q.push(v);
	bfs_disc[v] = true;
	cout << v << " ";
	while (!Q.empty()){
		int x = Q.front();
		Q.pop();
		for (auto it : adj[x]){
			if (!bfs_disc[it]){
				bfs_disc[it] = true;
				cout << it << " ";
				Q.push(it);
			}
		}
	}
	cout << "\n";
}

int main(int argc, char const *argv[])
{
	cin>>N>>M>>V;
	int x,y;
	for (int i=0;i<M;++i){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i=0;i<1001;++i){
		if (!adj[i].empty()) sort(adj[i].begin(), adj[i].end());
	}
	dfs(V);
	bfs(V);
	return 0;
}