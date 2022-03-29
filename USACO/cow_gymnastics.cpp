#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ifstream ifs("gymnastics.in"); ofstream ofs ("gymnastics.out");
    int k, n, ans = 0; ifs >> k >> n;
    vector<vector<int>> v(n);
    while(k--) for(int i=0; i<n; i++) {
        int a; ifs >> a; v[a-1].push_back(i);
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(i != j) {
        bool b = false;
        for(int k=0; k<v[i].size(); k++) if(v[i][k] > v[j][k]) {
            b = true; break;
        }
        ans += (!b ? 1 : 0);
    }
    ofs << ans;
    return 0;
}

