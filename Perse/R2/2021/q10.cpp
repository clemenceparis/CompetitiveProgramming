#include<iostream>
#include<map>
using namespace std;

map<char, int> m; string s; long long n;

long long calculate() {
    long long p = 1;
    for(int i=2; i<s.length(); i++) p*=i;
    for(auto x: m) if(x.second > 1) for(int i=2; i<=x.second; i++) p/=i;
    return p;
}

void solve() {
    if(s.empty()) return;
    int cur = 0;
    while(true) {
        m[s[cur]]--;
        long long f = calculate();
        if(f >= n) {
            cout << s[cur]; s.erase(s.begin() + cur); break;
        } else {
            m[s[cur]]++; n-=f;
        }
        for(int i=cur; i<s.length(); i++) {
            if(s[i] == s[i+1]) cur++;
            else break;
        }
        cur++;
    }
    solve();
}

int main() {
    cin >> s >> n;
    for(int i=0; i<s.length(); i++) m[s[i]]++;
    solve();
    return 0;
}

