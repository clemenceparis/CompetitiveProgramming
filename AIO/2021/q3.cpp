#include <iostream>
#include <math.h>
#include<fstream>
#include <unordered_map>
using namespace std;

int main() {
    ifstream ifs("melodyin.txt");
    int n, k;
    ifs >> n >> k;
    ofstream ofs("melodyout.txt");
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    unordered_map<int, int> m3;
    int z = n/3;
    while(z--) {
        int a, b, c; ifs >> a >> b >> c;
        m1[a]++;
        m2[b]++;
        m3[c]++;
    }
    int r1 = 0, r2 = 0, r3 = 0;
    for(auto x: m1) {
        if(x.second > r1) r1 = x.second;
    }
    for(auto x: m2) {
        if(x.second > r2) r2 = x.second;
    }
    for(auto x: m3) {
        if(x.second > r3) r3 = x.second;
    }
    int ans = n/3 - r1;
    ans += n/3 - r2;
    ans += n/3 - r3;
    ofs << ans;
    return 0;
}
