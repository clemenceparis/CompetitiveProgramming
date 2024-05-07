#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

vector<int> bfs(int st, int dis) {
    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    queue<int> q; q.push(st); visited[st] = true;
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        if(distance[node] == dis) ans.push_back(node); 
        for(auto child : adj[node]) if(!visited[child]) {
            distance[child] = distance[node]+1;
            visited[child] = true;
            q.push({child});
        }
    }
    return ans;
}

signed main() {
    int m; cin >> n >> m;
    adj = vector<vector<int>>(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b); 
        adj[b].push_back(a);
    }
    int t=0;
    map<int, int> track;
    for(int i=0; i<n; i++) track[i]=0;
    for(int i=0; i<n; i++) {
        int d; cin >> d;
        if(d == -1) continue;
        vector<int> cur = bfs(i, d);
        for(auto x : cur) track[x]++;
        t++;
    }
    vector<int> ans;
    for(auto x : track) if(x.second == t) ans.push_back(x.first);
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x+1 << ' ';
    return 0;
}