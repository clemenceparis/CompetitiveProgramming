#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        int n; cin >> n;
        vector<int> v(n);
        for(int j=0; j<n; j++) cin >> v[j];
        sort(v.begin(), v.end());
        int sum = 1, cur = 1;
        for(int j=1; j<n; j++) {
            if(v[j] != v[j-1]) cur++;
            sum += cur;
        }
        cout << "Case #" << i+1 << ": " << sum << endl;
    }
    return 0;
}

