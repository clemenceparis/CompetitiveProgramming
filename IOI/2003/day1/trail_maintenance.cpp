#include<bits/stdc++.h>
using namespace std;
 
vector<int> Link, Size;
 
int find(int a) {
    while(a != Link[a]) a = Link[a];
    return Link[a];
}
 
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(Size[a] < Size[b]) swap(a, b);
    Size[a] += Size[b];
    Link[b] = a;
}
 
bool same(int a, int b) {
    return find(a) == find(b);
}
 
signed main() {
    int n, t; cin >> n >> t;
    vector<tuple<int, int, int>> adj[2];
    int idx=0;
    while(t--) {
        Size = vector<int>(n+1, 1);
        Link = vector<int>(n+1);
        for(int i=0; i<=n; i++) Link[i] = i;
        int a, b, c; cin >> a >> b >> c;
        adj[idx].push_back({c, a, b});
        sort(adj[idx].begin(), adj[idx].end());
        int ans=0;
        for(int i=0; i<adj[idx].size(); i++) {
            if(!same(get<1>(adj[idx][i]), get<2>(adj[idx][i]))) {
                ans+=get<0>(adj[idx][i]);
                unite(get<1>(adj[idx][i]), get<2>(adj[idx][i]));
                adj[1-idx].push_back(adj[idx][i]);
            }
        }
        if(adj[1-idx].size() == n-1) cout << ans << '\n';
        else cout << "-1\n";
        adj[idx].clear();
        idx = 1-idx;
    }
    return 0;
}   

