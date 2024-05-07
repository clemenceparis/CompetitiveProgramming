#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> ini(n), obj(n);
    for(int i=0; i<n; i++) cin >> ini[i];
    for(int i=0; i<n; i++) cin >> obj[i];
    if(k <= 1) {
        int ans=0, cur=0;
        for(int i=0; i<n; i++) {
            if(ini[i] != obj[i]) cur++;
            if(ini[i] == obj[i] || i == n-1) {
                if(cur != 0) ans++;
                cur=0;
            }
        }
        cout << ans;
    } else {
        int ans=min(ini[n-1], k+1-ini[0]);
        for(int i=1; i<n; i++) {
            ans = min(ans, ini[i-1]+k+1-ini[i]);
        }
        cout << ans;
    }
    return 0;
}