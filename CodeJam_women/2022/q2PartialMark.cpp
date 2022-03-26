#include<iostream>
#include<vector>
using namespace std;

int solve() {
    int d, n, u, nums_l = 0, cur = 0; cin >> d >> n >> u;
    vector<pair<int, pair<int, int>>> v;
    while(d--) {
        int m, l, e; cin >> m >> l >> e; v.push_back({m, {l, e}});
    }
    vector<int> o;
    while(n--) {
        int a; cin >> a; o.push_back(a);
    }
    for(int i=0; i<v.size(); i++) {
        if(cur == o.size() || o[cur] < v[i].first || nums_l < 0) break;
        nums_l += v[i].second.first;
        while(cur != o.size() && ((o[cur] >= v[i].first && i == v.size()-1)||(o[cur] >= v[i].first && o[cur] < v[i+1].first)) && nums_l >= u) {
            nums_l -= u; cur++;
        }
    }
    return cur;
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) cout << "Case #" << i+1 << ": " << solve() << endl;
    return 0;
}

