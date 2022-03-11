#include<iostream>
#include<fstream>
#include<map>
#include<climits>
using namespace std;

int main() {
    ifstream ifs("notlast.in"); ofstream ofs("notlast.out");
    int n, small = INT_MAX, cur = INT_MAX, t = 0; ifs >> n; string s = "";
    map<string, int> m = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    for(int i=0; i<n; i++) {
        string a; int b; ifs >> a >> b; m[a]+=b;
    }
    
    for(auto x: m) if(x.second < small) small = x.second;
    for(auto x: m) {
        if(x.second > small && x.second < cur) {
            cur = x.second; s = x.first; t = 0;
        } else if(x.second == cur) t++;
    }
    ofs << ((!s.empty() && t == 0) ? s : "Tie");
}

