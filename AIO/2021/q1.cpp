#include <iostream>
#include <math.h>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs("robotin.txt");
    long t;
    ifs >> t;
    ofstream ofs("robotout.txt");
    long n = 0, e = 0, s = 0, w = 0, ans = 0;
    while(t--) {
        char a; ifs >> a;
        if(a == 'N') n++;
        else if(a == 'E') e++;
        else if(a == 'S') s++;
        else if(a == 'W') w++;
    }
    ans += abs(n-s);
    ans += abs(e-w);
    ofs << ans;
    return 0; 
}
