#include<bits/stdc++.h>
using namespace std;
#define int long long

int avg = 0;
vector<int> v;
vector<int> subtreeSum;
vector<vector<int>> adj;
vector<tuple<int, int, int>> ans;

void cal(int node, int prev) {
    for(auto child : adj[node]) if(child != prev) {
        cal(child, node);
        subtreeSum[node] += subtreeSum[child]; 
    }
    subtreeSum[node]+=v[node]-avg;
}

void up(int node, int prev) {
    for(auto child : adj[node]) if(child != prev) {
        up(child, node);
    }
    if(subtreeSum[node] > 0) {
        ans.push_back({node, prev, subtreeSum[node]});
        subtreeSum[node] = 0;
    }
}

void down(int node, int prev) {
    if(prev != -1 && subtreeSum[node] < 0) {
        ans.push_back({prev, node, -subtreeSum[node]});
        subtreeSum[node]=0;
    } 
    for(auto child : adj[node]) if(child != prev) {
        down(child, node);
    }
}

signed main() {
    int n; cin >> n;
    v = vector<int>(n);
    subtreeSum = vector<int>(n);
    adj = vector<vector<int>>(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        avg+=v[i];  
    }
    avg/=n;
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    cal(0, -1);
    up(0, -1);
    down(0, -1);
    cout << ans.size() << '\n';
    for(auto x : ans) cout << get<0>(x)+1 << ' ' << get<1>(x)+1 << ' ' << get<2>(x) << '\n';
    return 0;
}


