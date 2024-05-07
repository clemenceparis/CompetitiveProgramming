#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(k == 0) {
        for(auto x : v) cout << x << ' ';
    } else if(k%2 == 1) {
        vector<int> cur(n, 0);
        for(int i=0; i<n; i++){
            if(v[i] == 0) continue;
            if(v[i] > n) v[i]=n;
            cur[v[i]-1]++;
        }
        for(int i=n-2; i>=0; i--) cur[i]+=cur[i+1];
        for(auto x : cur) cout << x << ' ';
    } else {
        vector<int> cur(n, 0);
        for(int i=0; i<n; i++) {
            if(v[i] == 0) continue;
            if(v[i] > n) v[i]=n;
            cur[v[i]-1]++;
        }
        for(int i=n-2; i>=0; i--) cur[i]+=cur[i+1];
        v = cur;
        cur = vector<int>(n, 0);
        for(int i=0; i<n; i++) {
            if(v[i] == 0) continue;
            if(v[i] > n) v[i]=n;
            cur[v[i]-1]++;
        }
        for(int i=n-2; i>=0; i--) cur[i]+=cur[i+1];
        for(auto x : cur) cout << x << ' ';
    }
    return 0;
}