#include <iostream>
#include <math.h>
#include<fstream>
#include <climits>
using namespace std;

int main() {
    ifstream ifs("artin.txt");
    int t;
    ifs >> t;
    ofstream ofs("artout.txt");
    int ly = 0, sy = INT_MAX, lx = 0, sx = INT_MAX;
    while(t--) {
        int x, y; ifs >> x >> y;
        if(x > lx) lx = x;
        if(x < sx) sx = x;
        if(y > ly) ly = y;
        if(y < sy) sy = y;
    }
    long ans = ly-sy;
    ans *= (lx-sx);
    ofs << ans;
    return 0;
}
