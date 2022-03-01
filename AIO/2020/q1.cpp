#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream ifs("baublesin.txt");
    long long ro, bo, s, rp, bp;
    ifs >> ro >> bo >> s >> rp >> bp;
    ofstream ofs("baublesout.txt");
    long long smallest = LONG_LONG_MAX;

    if(bo+s < bp || ro+s < rp || ro+bo+s < rp+bp) smallest = 0;
    else if (rp == 0) {
        smallest = bo + s - bp + 1;
    }
    else if (bp == 0) {
        smallest = ro + s - rp + 1;
    } else {
        smallest = min(ro+s-rp, min(bo+s-bp, ro+bo+s-rp-bp)) +1;

        if(ro == 0 && rp == 0 && s == 0) {
            smallest = bo - bp +1;
        } else if (bo == 0 && bp == 0 && s == 0) {
            smallest = ro - rp +1;
        }
    }

    if(smallest < 0) smallest = 0;

    ofs << smallest;
    return 0;
}
