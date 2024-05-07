#include "balisage.h"
#include <bits/stdc++.h> 
using namespace std;

int trouver_carrefour_commun(vector<int> U, vector<int> V, vector<int> zone_samantha, vector<int> zone_adrien) {
	vector<vector<int>> adj(U.size()+1);
	for(int i=0; i<U.size(); i++) {
		adj[U[i]].push_back(V[i]);
		adj[V[i]].push_back(U[i]);
	}
	int rootA = zone_adrien[0];
	int change = adrien_vers_samantha(rootA);

	set<int> inZoneS;
	for(int i=0; i<zone_samantha.size(); i++) inZoneS.insert({zone_samantha[i]});

	vector<bool> visited(U.size()+1, false);
	queue<int> q; q.push(change); 
	int closes=0;

	while(!q.empty()) {
		int node = q.front(); q.pop();
		if(visited[node]) continue;
		if(inZoneS.count(node)) {
			closes=node; break;
		}
		visited[node] = true;
		for(auto child : adj[node]) if(!visited[child]) {
			q.push(child);
		}
	}

	int changeClo = samantha_vers_adrien(closes);

	for(int i=0; i<zone_adrien.size(); i++) if(zone_adrien[i] == changeClo) return closes;

	return -1;
}
