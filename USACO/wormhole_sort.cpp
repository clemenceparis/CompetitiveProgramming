#include<iostream>
#include<fstream>
#include<memory.h>
#include<vector>
#include<set>
using namespace std;

int n; vector<int> weights, cows; vector<vector<pair<int, int> > > adj;

bool same(vector<int> & v) {
    for(int i=0; i<v.size(); i++) if(i != v[i]) return false;
    return true;
}

void DFS(int node, int small, int componentID, vector<int> & components) {
    if(components[node]) return;
    components[node] = componentID;
    for(auto child : adj[node]) if(child.second >= small) {
        DFS(child.first, small, componentID, components);
    }
}

bool check(int small) {
    int cur = 1; vector<int> components(n);
    for(int i=0; i<n; i++) if(!components[i]) {
        DFS(i, small, cur, components); cur++;
    }
    for(int i=0; i<n; i++) if(components[cows[i]] != components[i]) return false;
    return true;
}

int lastTrue(int lo, int hi) {
    lo--;
    while(lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    ifstream ifs("wormsort.in"); ofstream ofs("wormsort.out");
    int m; ifs >> n >> m;
    cows = vector<int>(n);
    for(int i=0; i<n; i++) {
        ifs >> cows[i]; cows[i]--;
    }
    if(same(cows)) {
        ofs << -1; return 0;
    }
    adj = vector<vector<pair<int, int> > >(m);
    for(int i=0; i<m; i++) {
        int a, b, w; ifs >> a >> b >> w; a--; b--;
        adj[a].push_back(make_pair(b, w)); adj[b].push_back(make_pair(a, w));
    }
    ofs << lastTrue(1, 1e9);
    return 0;
}

