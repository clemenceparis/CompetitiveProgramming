#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<int> spy(m);
    for(int i=0; i<m; i++) cin >> spy[i];
    sort(spy.begin(), spy.end());
    vector<int> ans;
    bool last=true;
    for(int i=1; i<m; i++) {
        if((spy[i]-spy[i-1])%2 == 0) {
            ans.push_back((spy[i]+spy[i-1])/2);
            i++;
            if(i == m) last=false;
        } else {
            ans.push_back(spy[i-1]);
        }
    }
    if(last) ans.push_back(spy[m-1]);
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
}
