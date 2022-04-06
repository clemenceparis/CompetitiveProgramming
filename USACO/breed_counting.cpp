#include<iostream>
#include<vector>
#include<tuple>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs("bcount.in"); ofstream ofs("bcount.out");
    int n, q; ifs >> n >> q;
    vector<tuple<int, int, int>> v(n+1);
    v[0] = {0,0,0};
    
    for(int i=0; i<n; i++) {
        int a; ifs >> a; v[i+1] = v[i];
        if(a == 1) get<0>(v[i+1])++;
        else if(a == 2) get<1>(v[i+1])++;
        else get<2>(v[i+1])++;
    }
    
    while(q--) {
        int a, b; ifs >> a >> b;
        ofs << get<0>(v[b]) - get<0>(v[a-1]) << ' ' << get<1>(v[b]) - get<1>(v[a-1]) << ' ' << get<2>(v[b]) - get<2>(v[a-1]) << '\n';
    }
    return 0;
}

