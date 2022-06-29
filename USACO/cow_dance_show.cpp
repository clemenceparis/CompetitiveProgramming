#include<iostream>
#include<fstream>
#include<vector>
#include<set>
using namespace std;

int n, t; vector<int> v;

bool check(int c) {
    multiset<int> s;
    for(int i=0; i<c; i++) s.insert(v[i]);
    for(int i=c; i<n; i++) {
        if(*s.begin()+v[i] > t) return false;
        s.insert(*s.begin()+v[i]); s.erase(s.begin());
    }
    return true;
}
int firstTrue(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ifstream ifs("cowdance.in"); ofstream ofs("cowdance.out");
    ifs >> n >> t;
    for(int i=0; i<n; i++) {
        int a; ifs >> a; v.push_back(a);
    }
    ofs << firstTrue(0, n);
    return 0;
}

