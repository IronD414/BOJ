#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

#define INF INT_MAX

int V, E, K, u, v, w;
int vertices[20001];
pair<int, int> tmp_edge, tmp_vertex;
map<int,int> edges[20001];	// [from]<to, weight>
priority_queue < pair<int, int>> minheap;	// <distance, vertex>

void dijkstra(){
	while (!minheap.empty()) {
		int src_vt = minheap.top().second, src_dist = -minheap.top().first;
		minheap.pop();
		for (auto adj : edges[src_vt]) {
			int pre_dist = vertices[adj.first];
			int post_dist = src_dist + adj.second;
			if (post_dist < pre_dist) {
				vertices[adj.first] = post_dist;
				tmp_vertex = { -post_dist, adj.first };
				minheap.push(tmp_vertex);
			}
		}
	}
}

int main() {
	cin >> V >> E >> K;
	for (int i = 0; i <= V; i++) vertices[i] = INF;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		tmp_edge = { v,w };
		auto exist = edges[u].find(v);
		if (exist != edges[u].end() && exist->second > w)
			exist->second = w;
		else if (exist == edges[u].end()) edges[u].emplace(v, w);
	}
	vertices[K] = 0;
	tmp_vertex = { 0,K };
	minheap.push(tmp_vertex);
	dijkstra();
	for (int i = 1; i <= V; i++)
	{
		string output = vertices[i] == INF ? "INF" : to_string(vertices[i]);
		cout << output << "\n";
	}
}