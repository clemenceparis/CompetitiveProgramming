#include<iostream>
using namespace std;

bool solve(int x, int y) {
    int s; cin >> s;
    int X[s], Y[s];
    for(int i=0; i<s; i++) cin >> X[i] >> Y[i];
    
    bool up = false, down = false;
    
    for(int i=0; i<s; i++) {
        if(y*X[i] == x*Y[i]) return true;
        else if(y*X[i] > x*Y[i]) up = true;
        else down = true;
        if(up && down) return true;
    }
    return false;
}

int main() {
    int x, y, t; cin >> x >> y >> t;
    for(int i=0; i<t; i++) {
        if(solve(x, y)) cout << i+1 << endl;
    }
    return 0;
}

