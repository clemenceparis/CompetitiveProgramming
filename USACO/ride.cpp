#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifs("ride.in");
    string a, b;
    ifs >> a >> b;
    ofstream ofs("ride.out");
    int p_a = 1, p_b = 1;
    for(int i=0; i<a.length(); i++) {
        p_a *= (a[i]-64);
    }
    for(int i=0; i<b.length(); i++) {
        p_b *= (b[i]-64);
    }
    if(p_a%47 == p_b%47) {
        ofs << "GO" << endl;
    } else {
        ofs << "STAY" << endl;
    }
}
