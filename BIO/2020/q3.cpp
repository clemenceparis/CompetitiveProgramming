#include<iostream>
#include<map>
using namespace std;

int p, q, r; long long n, cur = 0; string s; bool b = false;
map<pair<int, int>, long long> m;

void search(int idx, int l) {
    if(l > q || b) return;
    if(idx == r) {
        cur++;
        if(cur == n) {
            cout << s; b = true; return;
        }
    } else {
        auto key = make_pair(idx, l);
        if(m.count(key) && cur + m[key] < n) {
            cur+=m[key];
            return;
        }
        long long oldCur = cur;
        for(int i=0; i<p; i++) {
            s[idx] = 'A' + i;
            search(idx+1, ((idx == 0 || s[idx] == s[idx-1]) ? l+1 : 1));
        }
        long long count = cur - oldCur;
        m[key] = count;
    }
}

int main() {
    cin >> p >> q >> r >> n;
    string c(r, ' '); s = c;
    search(0, 0);
    return 0;
}

