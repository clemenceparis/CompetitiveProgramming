#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs("whereami.in"); ofstream ofs("whereami.out");
    int l; string s; ifs >> l >> s;
    for(int k=1; k<=l; k++) {
        bool b = true;
        for(int i=0; i<=l-k; i++) {
            string cur = "";
            for(int j=i; j<i+k; j++) cur.push_back(s[j]);
            for(int m=0; m<=l-k; m++) {
                if(i != m) {
                    string c;
                    for(int n=m; n<m+k; n++) c.push_back(s[n]);
                    if(c == cur) {
                        b = false; break;
                    }
                }
            }
            if(!b) break;
        }
        if(b) {
            ofs << k; return 0;
        }
    }
    return 0;
}

