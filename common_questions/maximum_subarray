#include<iostream>
#include<climits>
using namespace std;
 
int main() {
    int n; cin >> n;
    long max = 0, cur = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        if(i == 0) {
            cur = a; max = a;
        } else if(a > cur + a) cur = a;
        else cur += a;
        if(cur > max) max = cur;
    }
    cout << max;
    return 0;
}
