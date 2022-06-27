#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ifstream ifs("haybales.in"); ofstream ofs("haybales.out");
    int n, q; ifs >> n >> q;
    vector<int> v(n);
    for(int i=0; i<n; i++) ifs >> v[i];
    sort(v.begin(), v.end());
    while(q--) {
        int a, b; ifs >> a >> b;
        auto it1 = lower_bound(v.begin(), v.end(), a), it2 = upper_bound(v.begin(), v.end(), b);
        ofs << it2-it1 << '\n';
    }
    return 0;
}

