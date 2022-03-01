
   
#include<iostream>
using namespace std;

void HanoiTower(int t, int a, int b, int c) {
    if(t == 1) {
        cout << a << " -> " << c << endl;
        return;
    }
    HanoiTower(t-1, a, c, b);
    HanoiTower(1, a, b, c);
    HanoiTower(t-1, b, a, c);
}

int main() {
    int t; cin >> t;
    HanoiTower(t, 1, 2, 3);
    return 0;
}
