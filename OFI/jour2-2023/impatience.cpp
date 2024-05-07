#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, c, t; cin >> n >> c >> t;
    vector<int> patience(n), cal(n, 0);
    for(int i=0; i<n; i++) {
        cin >> patience[i];
        if(patience[i] < t) {
            cal[i]=1;
            cal[min(i+t-patience[i], n-1)] = 2;
        }
    }
    int open=0;
    for(int i=0; i<n; i++) {
        if(cal[i] == 2) open--;
        else if(cal[i] == 1) open++;
        if(open > 0) cal[i] = 1;
    }
    int ttSaves=0;
    for(int i=0; i<n; i++) if(cal[i] == 0) ttSaves++;

    //vector<int> save(n);
    int ans=0;
    for(int i=0; i<n; i++) if(patience[i] <= t) {
        int nbSaves=0;
        for(int j=i+1; j<n; j++) {
            if(patience[j] > t) nbSaves++;
            else break;
        }
        ans = max(ans, nbSaves+ttSaves);
        //save[i]=nbSaves;
    }
    // for(auto x : save) cout << x << ' ';
    // cout << '\n';
    // sort(save.begin(), save.end()); reverse(save.begin(), save.end());
    // int ans=0;
    // for(int i=0; i<c; i++) ans+=save[i];
    cout << n-ans;
    return 0;
}