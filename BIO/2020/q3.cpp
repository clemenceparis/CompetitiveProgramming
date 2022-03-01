#include<iostream>
using namespace std;

int p, q, r; unsigned long long int n, ans = 0;
string s;

void search(int idx) {
    if(idx == r) {
        int cur = 1; bool c = true;
        for(int i=1; i<r; i++) {
            if(s[i-1] == s[i])cur++;
            else if(s[i-1]!=s[i] && cur > q) {
                c = false; break;
            } else cur = 1;
        }
        if(c && cur <= q) ans++;
        if(ans == n) {
            cout << s;
            p = -1;
            return;
        }
    } else {
        for(int i=0; i<p; i++) {
            s[idx] = 'A' + i;
            search(idx+1);
        }
    }
}

int main() {
    cin >> p >> q >> r >> n;
    string cur(r, ' ');
    s = cur;
    search(0);
    return 0;
}
