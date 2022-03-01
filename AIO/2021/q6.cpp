#include <iostream>
#include <math.h>
#include<algorithm>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs("laserin.txt");
    long n;
    ifs >> n;
    ofstream ofs("laserout.txt");
    long ans = 0;
    string a, b; ifs >> a >> b;
    long ra = 0, da= n, rb = 0, db = n;
    for(int i=0; i<2*n; i++) {
        if(a[i] == 'R') ra++;
        else da--;
        if(b[i] == 'R') rb++;
        else db--;
        if(min(abs(ra-rb), abs(da-db)) > ans) ans = min(abs(ra-rb), abs(da-db));
    }
    if(ans == 0) ans = 1;
    ofs << ans;
    return 0;
}
