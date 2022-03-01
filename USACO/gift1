#include <iostream>
#include <fstream>
#include<unordered_map>
using namespace std;

int main() {
    ifstream ifs("gift1.in");
    int t; ifs >> t;
    ofstream ofs("gift1.out");
    string arr[t];
    unordered_map<string, int> m;
    for(int i=0; i<t; i++) {
        string a; ifs >> a;
        arr[i] = a;
        m[a] = 0;
    }
     for(int i=0; i<t; i++) {
        string a; int g, p; ifs >> a >> g >> p;
        if(g != 0 && p != 0) {
            int z = g/p;
            for(int j=0; j<p; j++) {
                string b; ifs >> b;
                m[b] += z;
            }
            m[a] -= z*p;
        }
    }
    for(int i=0; i<t; i++) {
        ofs << arr[i] << ' ' << m[arr[i]] << endl;
    }
}
