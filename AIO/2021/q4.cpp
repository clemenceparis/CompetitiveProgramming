#include <iostream>
#include <math.h>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ifstream ifs("distin.txt");
    long n, k;
    ifs >> n >> k;
    ofstream ofs("distout.txt");
    vector<int> v;
    long d = n;
    while(d--) {
        int a; ifs >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long count = v[0], ans = 1;
    for(int i=1; i<n; i++) {
        if((long)v[i]-count >= k) {
            ans++;
            count =v[i];
        }
    }
    ofs << ans;
    return 0;
}
