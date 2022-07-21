#include<iostream>
#include<vector>
using namespace std;

int ans=0, start = 0; vector<vector<int> > adj;

void DFS(int node, int prev, int l) {
    if(l > ans) {
        ans = l; start = node;
    }
    for(auto child: adj[node]) {
        if(child != prev) DFS(child, node, l+1);
    }
}

int main() {
    int n; cin >> n;
    adj = vector<vector<int> >(n);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    DFS(0, -1, 0);
    DFS(start, -1, 0);
    cout << ans;
    return 0;
}
