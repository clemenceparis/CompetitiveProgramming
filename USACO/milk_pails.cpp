#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs("pails.in"); ofstream ofs("pails.out");
    int x, y, m; ifs >> x >> y >> m;
    int ans = x - 1;
    
    for(int i=1; i<=m/x; i++) {
        int a = m - (x * i);
        if(a%y < ans) ans = a%y;
        if(ans == 0) break;
    }
    ofs << m-ans;
    return 0;
}
