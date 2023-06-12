#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> v(n), cur(n), sum(n+1); sum[0] = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i]; cur[i] = v[i];
    }
    map<int, int> m;
    sort(cur.begin(), cur.end());
    int totalSum=0;
    for(int i=1; i<=n; i++) {
        totalSum += cur[i-1]*i;
        sum[i] = cur[i-1] + sum[i-1];
        m.insert({cur[i-1], i-1});
    }
    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b; a--;
        int c = v[a], ans = totalSum, it1 = m[c]; 
        auto it2 = upper_bound(cur.begin(), cur.end(), b);
        ans -= cur[it1]*(it1+1);
        ans -= sum[n]-sum[it1+1];
        ans += b*(it2-cur.begin()+(b > c ? 0 : 1));
        ans += sum[n]-sum[it2-cur.begin()]-(b > c ? 0 : c);
        cout << ans << '\n';
    }
}
