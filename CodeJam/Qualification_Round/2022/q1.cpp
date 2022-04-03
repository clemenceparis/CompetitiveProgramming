#include<iostream>
using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        int y, x; cin >> y >> x;
        cout << "Case #" << i+1 << ":" << endl;
        
        for(int j=0; j<x; j++) {
            if(j == 0) cout << "..+";
            else cout << "-+";
        }
        cout << endl;
        
        for(int j=0; j<y; j++) {
            if(j != 0) cout << '|';
            for(int k=0; k<x; k++) {
                if(k == 0 && j == 0) cout << "..|";
                else cout << ".|";
            }
            cout << endl << '+';
            for(int k=0; k<x; k++) cout << "-+";
            cout << endl;
        }
    }
    return 0;
}
