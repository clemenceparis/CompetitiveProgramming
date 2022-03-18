//prefix sum
//You are given a non-negative integer sequence A = (a_0, a_1, ... , a_{N-1})A=(a0,a1,…,aN−1) with the length N.
//Process the following Q queries in order:
//You are given integers li and ri. Print sum from a_li to a_ri-1;


#include<iostream>
using namespace std;

int main() {
    int n, q; long long cur = 0; cin >> n >> q;
    long long arr[500000];
    for(int i=0; i<n; i++) {
        int a; cin >> a; cur += a;
        arr[i] = cur;
    }
    while(q--) {
        int l, r; cin >> l >> r;
        if(l == 0) cout << arr[r-1] << endl;
        else cout << arr[r-1] - arr[l-1] << endl;
    }
    return 0;
}

