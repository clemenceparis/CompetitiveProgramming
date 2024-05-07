#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int tar, n; cin >> tar >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int cur=0, ans=n;
    for(int i=0; i<n; i++) {
        if(cur+v[i] <= tar) cur+=v[i];
        else {
            ans=i; break;
        }
    }
    cout << ans;
}
