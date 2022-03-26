#include<iostream>
#include<vector>
using namespace std;

int solve() {
    int n; cin >> n;
    int tr = 0, tl = 0, br = 0, bl = 0;
    for(int i=0; i<2*n; i++) for(int j=0; j<2*n; j++) {
        char c; cin >> c;
        if(i<n && j<n && c == 'I') tr++;
        else if(i<n && j>=n && c == 'I') tl++;
        else if(i>=n && j<n && c == 'I') br++;
        else if(c == 'I') bl++;
    }
    int diff1 = tr+tl-br-bl, diff2 = tr+br-tl-bl;
    if(diff1 < 0) diff1 = -diff1;
    if(diff2 < 0) diff2 = -diff2;
    return max(diff1, diff2);
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) cout << "Case #" << i+1 << ": " << solve() << endl;
    return 0;
}

