#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ifstream ifs("speeding.in"); ofstream ofs("speeding.out");
    int n, m, ans = 0; ifs >> n >> m;
    vector<int> road, drives;
    
    for(int i=0; i<n; i++) {
        int a, b; ifs >> a >> b;
        for(int i=0; i<a; i++) road.push_back(b);
    }
    for(int i=0; i<m; i++) {
        int a, b; ifs >> a >> b;
        for(int i=0; i<a; i++) drives.push_back(b);
    }
    for(int i=0; i<100; i++) ans = max(ans, drives[i]-road[i]);
    
    ofs << ans;
}
