#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n;
vector<int> tree;
 
int sum(int k) {
    int s=0;
    while(k >= 1) {
        s+=tree[k];
        k-=k&-k;
    }
    return s;
}
 
void add(int k, int x) {
    while(k <= n) {
        tree[k]+=x;
        k+=k&-k;
    }
}
 
signed main() {
    int nn; cin >> nn; n = nn*2;
    vector<int> v(nn, 0);
    tree = vector<int>(n+1, 0);
    int ans = nn;
    for(int i=0; i<2*nn; i++) {
        int a; cin >> a; a--;
        if(v[a] == 0) {
            v[a] = i+1;
            add(i+1, 1);
        } else {
            add(v[a], -1);
            ans += (sum(i+1)-sum(v[a]-1));
        }
    }
    cout << ans;
    return 0;
}
