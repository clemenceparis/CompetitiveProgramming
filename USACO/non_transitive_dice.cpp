#include<iostream>
#include<vector>
using namespace std;


bool beat(vector<int> &a, vector<int> &b) {
    int win = 0, loses = 0;
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) {
        if(a[i] > b[j]) win++;
        else if(b[j] > a[i]) loses++;
    }
    return win > loses;
}

bool non_transitive(vector<int> &a, vector<int> &b) {
    for(int i=1; i<=10; i++) for(int j=1; j<=10; j++) for(int k=1; k<=10; k++) for(int l=1; l<=10; l++) {
        vector<int> c = {i, j, k, l};
        if((beat(a, b) && beat(b, c) && beat(c, a)) || (beat(b, a) && beat(c, b) && beat(a, c))) return true;
    }
    return false;
}

int main() {
    int t; cin >> t;
    while(t--) {
        vector<int> a; vector<int> b;
        for(int i=0; i<8; i++) {
            int n; cin >> n;
            if(i < 4) a.push_back(n);
            else  b.push_back(n);
        }
        cout << (non_transitive(a, b) ? "yes" : "no") << endl;
    }
    return 0;
}

