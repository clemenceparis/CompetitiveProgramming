#include<iostream>
#include<climits>
using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
        int c = INT_MAX, m = INT_MAX, y = INT_MAX, k = INT_MAX;
        for(int i=0; i<3; i++) {
            int c1, c2, c3, c4; cin >> c1 >> c2 >> c3 >> c4;
            c = min(c, c1); m = min(m, c2); y = min(y, c3); k = min(k, c4);
        }
        if(c+m+y+k < 1000000) cout << "IMPOSSIBLE";
        else {
            int diff = c+m+y+k - 1000000;
            
            if(diff != 0) {
                int o = diff; diff -= min(diff, c); c -= min(o, c);
            }
            if(diff != 0) {
                int o = diff; diff -= min(diff, m);m -= min(o, m);
            }
            if(diff != 0) {
                int o = diff; diff -= min(diff, y); y -= min(o, y);
            }
            if(diff != 0) {
                int o = diff; diff -= min(diff, k); k -= min(o, k);
            }
            cout << c << ' ' << m << ' ' << y << ' ' << k;
        }
        cout << endl;
    }
    return 0;
}
