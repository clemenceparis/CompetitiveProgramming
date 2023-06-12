#include<bits/stdc++.h>
using namespace std;
#define int long long

int timeCookie, timeMuffin;
vector<tuple<int, int, int>> v;

bool check(int k) {
    int maxx=k, minx=0, maxy=k, miny=0;
    for(int i=0; i<v.size(); i++) {
        int a = get<0>(v[i]), b = get<1>(v[i]), c = get<2>(v[i]);
        int cal = timeCookie*a+timeMuffin*b-c;
        if(a > b) {
            int m = a-b, n = b*k;
            if(n > cal) continue;
            int curx = ((cal-n)%m == 0 ? (cal-n)/m : ((cal-n)/m)+1);
            int cury = k-curx;
            minx = max(minx, curx);
            maxy = min(maxy, cury);
        } else if(a < b) {
            int m = b-a, n = a*k;
            if(n > cal) continue;
            int cury = ((cal-n)%m == 0 ? (cal-n)/m : ((cal-n)/m)+1);
            int curx = k-cury;
            miny = max(miny, cury);
            maxx = min(maxx, curx);
        } else if(k*a < cal) return false;
        if(minx > maxx || miny > maxy || timeCookie-minx <= 0 ||timeMuffin-miny <= 0) return false;
    }
    return true;
}

int firstTrue(int lo, int hi) {
    hi++;
    while(lo < hi) {
        int mid = lo+(hi-lo)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        v.clear();
        int n; cin >> n >> timeCookie >> timeMuffin;
        for(int i=0; i<n; i++) {
            int a, b, c; cin >> a >> b >> c;
            v.push_back({a, b, c});
        }
        cout << firstTrue(0, timeCookie+timeMuffin-2) << '\n';
    }   
    return 0;
}
