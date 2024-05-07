#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> aa; aa.push_back(a[0]);
    for(int i=1; i<n; i++) if(a[i] != a[i-1]) aa.push_back(a[i]);

    map<int, int> m;
    for(int i=0; i<aa.size(); i++) {
        //split iles+1
        if(i != 0 && i != aa.size()-1 && aa[i] < aa[i+1] && aa[i] < aa[i-1]) m[aa[i]]++;
        // submerge iles-1
        if(i == 0 && aa[i] > aa[i+1]) m[aa[i]]--;
        else if(i == aa.size()-1 && aa[i] > aa[i-1]) m[aa[i]]--;
        else if(aa[i] > aa[i-1] && aa[i] > aa[i+1]) m[aa[i]]--;
    }
    //for(auto x : m) cout << x.first << ' ' << x.second << '\n';
    int ans=1, cur=1;
    for(auto x : m) {
        cur+=x.second;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}