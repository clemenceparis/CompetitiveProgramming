#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    if(n == 1) {
        cout << "1\n1"; return 0;
    }
    vector<vector<int>> friends(n);
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        bool add=false;
        for(int j=0; j<a; j++) {
            int b; cin >> b;
            if(b > i+1 && !add) {
                friends[i].push_back(i+1);
                add=true;
            }
            friends[i].push_back(b);
        }
        if(!add) friends[i].push_back(i+1);
    }
    int cur=1;
    map<vector<int>, int> m;
    for(int i=0; i<n; i++) {
        if(m.count(friends[i])) continue;
        m[friends[i]] = cur;
        cur++;
    }
    if(m.size() == 1) {
        cout << "2\n";
        for(int i=1; i<n; i++) cout << "1 ";
        cout << "2\n1 2";
    } else {
        cout << m.size() << '\n';
        vector<int> group(n);
        for(int i=0; i<n; i++) {
            cout << m[friends[i]] << ' ';
            group[i] = m[friends[i]];
        }
        cout << '\n';
        set<Node> adj;
        for(int i=0; i<n; i++) {
            for(int j=0; j<friends[i].size(); j++) {
                adj.insert({min(group[i], group[friends[i][j]-1]), max(group[i], group[friends[i][j]-1])});
            }
        }

        for(auto x : adj) if(x.first != x.second) {
            cout << x.first << ' ' << x.second << '\n';
        }
    }
    
    return 0; 
}