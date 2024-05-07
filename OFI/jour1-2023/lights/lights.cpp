#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m)), ps(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> grid[i][j];

    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) ps[i][j] = ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+grid[i-1][j-1];

    vector<vector<int>> pps(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) pps[i][j] = i*j-2*ps[i][j];

    int ans=1e9;
    for(int i=1; i<=n; i++) for(int p=i; p<=n; p++) {
        vector<int> sml1(m+1, 1e9), sml2(m+1, 1e9);
        for(int j=1; j<=m; j++) {
            sml1[j] = min(sml1[j-1], pps[i-1][j-1]-pps[p][j-1]);
            int q = m-j+1;
            sml2[j] = min(sml2[j-1], pps[p][q]-pps[i-1][q]);
        }
        for(int j=1; j<=m; j++) {
            int q = m-j+1;
            ans = min(ans, ps[n][m]+sml1[j]+sml2[q]);
        }
    }
    cout << ans;
}
