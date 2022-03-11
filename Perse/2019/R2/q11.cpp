#include<iostream>
#include<vector>
using namespace std;

bool visited[100000]; vector<vector<int>> v; int ans = 0, cur = 0;

void DFS(int node) {
    if(cur > ans) ans = cur;
    if(!visited[node]) {
        cur++;
        visited[node] = true;
        for(auto x: v[node]) DFS(x);
    }
}

int main() {
    int n, c; cin >> n >> c; vector<int> m;
    for(int i=0; i<n+1; i++) v.push_back(m);
    for(int i=0; i<c; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }
    for(int i=0; i<v.size(); i++) {
        if(!v[i].empty()) {
            cur = 0; DFS(i);
        }
    }
    cout << ans;
    return 0;
}
