#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
vector<int> Link, Size;

int find(int x) {
    while(x != Link[x]) x = Link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(Size[a] < Size[b]) swap(a, b);
    Size[a] += Size[b];
    Link[b] = a;
}

signed main() {
    ifstream ifs("moocast.in"); ofstream ofs("moocast.out");
    int n; ifs >> n;
    Size = vector<int>(n, 1);
    for(int i=0; i<n; i++) Link.push_back(i);
    v = vector<pair<int, int>>(n);
    for(int i=0; i<n; i++) ifs >> v[i].first >> v[i].second;
    vector<tuple<int, int, int>> adj;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int a = v[i].first-v[j].first, b = v[i].second-v[j].second; a*=a; b*=b;
            adj.push_back({a+b, i, j});
        }
    }
    sort(adj.begin(), adj.end());
    for(int i=0; i<adj.size(); i++) {
        if(!same(get<1>(adj[i]), get<2>(adj[i]))) {
            unite(get<1>(adj[i]), get<2>(adj[i]));
            if(Size[find(get<1>(adj[i]))] == n) {
                ofs << get<0>(adj[i]); break;
            }
        }
    }
    return 0;   
}
