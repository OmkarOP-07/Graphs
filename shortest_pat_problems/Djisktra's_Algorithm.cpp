#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
	{
		vector<pair<int, int>> adj[V + 1];
		
		for (auto &it: edges)
			{
			adj[it[0]].push_back({it[1], it[2]});
			adj[it[1]].push_back({it[0], it[2]});
		}
		
		priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>> > pq;
		
		vector<int> dist(V + 1, 1e9), parent(V + 1);
		
		for (int i = 1; i <= V; i++)
			parent[i] = i;
		
		dist[src] = 0;
		pq.push({0, src});
		
		while (!pq.empty())
			{
			int distance = pq.top().first;
			int node = pq.top().second;
			pq.pop();
			
			if (distance > dist[node])
				continue;
			
			for (auto it:adj[node])
				{
				int nnode = it.first;
				int wt = it.second;
				
				if (distance + wt<dist[nnode])
					{
					dist[nnode] = distance + wt;
					pq.push({dist[nnode], nnode});
					parent[nnode] = node;
				}
			}
		}
		
		if (dist[dest] == 1e9)
			return {-1};
		
		vector<int> path;
		
		int node = dest;
		
		while (parent[node] != node)
			{
			path.push_back(node);
			node = parent[node];
		}
		
		path.push_back(src);
		reverse(path.begin(), path.end());
		return path;
	}
};

// Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
// Output: [4, 3, 0]
// Explanation:

int main()
{

}