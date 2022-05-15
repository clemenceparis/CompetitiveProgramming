#include<iostream>
#include<vector>
using namespace std;

int main() {
    int d, n, m = 0; cin >> d >> n;
    vector<pair<int, int>> v = {{0, 0}}, p(n);
    for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
    
    while(true) {
        vector<pair<int, int>> cur;
        for(int i=p.size()-1; i>=0; i--) {
            for(int j=0; j<v.size(); j++) {
                long long diff1 = v[j].first - p[i].first, diff2 = v[j].second - p[i].second;
                if((diff1*diff1)+(diff2*diff2) <= (long long)d*d) {
                    cur.push_back({p[i].first, p[i].second}); p.erase(p.begin() + i); m++; break;
                }
            }
        }
        v = cur;
        if(v.empty()) break;
        cout << m << endl;
    }
    return 0;
}

