#include<bits/stdc++.h>
using namespace std;
#define int long long

bool Isinocent(tuple<int, int, int> a, tuple<int, int, int> b) {
    int x = abs(get<1>(a)-get<1>(b)), y = abs(get<2>(a)-get<2>(b)), z = abs(get<0>(a)-get<0>(b));
    x*=x; y*=y; z*=z;
    if(x+y > z) return true;
    return false;
}

signed main() {
    int g, n; cin >> g >> n;
    vector<tuple<int, int, int>> grazing;
    for(int i=0; i<g; i++) {
        int x, y, t; cin >> x >> y >> t;
        grazing.push_back({t, x, y});
    }
    sort(grazing.begin(), grazing.end());
    int nbInnocent=0;
    for(int i=0; i<n; i++) {
        tuple<int, int, int> x; cin >> get<1>(x) >> get<2>(x) >> get<0>(x);
        auto it = upper_bound(grazing.begin(), grazing.end(), x);
        bool innocent = false;
        if(it != grazing.end()) {
            innocent = Isinocent(x, *it);
        } 
        if(!innocent && it != grazing.begin()) {
            it--;
            innocent = Isinocent(x, *it);
        }
        if(innocent) nbInnocent++;
    }
    cout << nbInnocent;
    return 0;
}
