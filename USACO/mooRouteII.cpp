#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n, m; cin >> n >> m;
    vector<vector<tuple<int, int, int>>> adj(n);
    while(m--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[a-1].push_back({b, c-1, d});   
    }
    for(int i=0; i<n; i++) sort(adj[i].begin(), adj[i].end());
    vector<int> diff(n);
    for(int i=0; i<n; i++) cin >> diff[i];
    vector<int> ans(n, -1); ans[0] = 0;
    queue<pair<int, int>> q; q.push({0, INT_MIN});

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i=adj[p.first].size()-1; i>=0; i--) {
            if(p.second+diff[p.first] <= get<0>(adj[p.first][i])) {
                q.push({get<1>(adj[p.first][i]), get<2>(adj[p.first][i])});
                if(ans[get<1>(adj[p.first][i])] == -1 || ans[get<1>(adj[p.first][i])] > get<2>(adj[p.first][i])) ans[get<1>(adj[p.first][i])] = get<2>(adj[p.first][i]);
                adj[p.first].pop_back();
            } else break;
        }
    }

    for(auto x : ans) cout << x << '\n';
    return 0;
}
