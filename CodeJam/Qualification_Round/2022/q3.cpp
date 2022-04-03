#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
        int n, ans = 0, num = 1; cin >> n;
        vector<int> v(n);
        for(int j=0; j<n; j++) cin >> v[j];
        sort(v.begin(), v.end());
        for(int j=0; j<n; j++) if(v[j] >= num) {
            ans++; num++;
        }
        cout << ans << endl;
    }
    return 0;
}
