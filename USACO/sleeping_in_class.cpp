#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, sum = 0; cin >> n;
        vector<int> cur(n);
        for(int i=0; i<n; i++) {
            cin >> cur[i]; sum += cur[i];
        }
        if(sum != 0) {
            for(int i=*max_element(cur.begin(), cur.end()); i<=sum; i++) {
                if(sum%i == 0) {
                    vector<int> v = cur; bool b = true; int ans = 0;
                    for(int j=n-1; j>0; j--) {
                        if(v[j] > i) {
                            b = false; break;
                        } else if(v[j] != i) {
                            v[j-1] += v[j]; v.erase(v.begin() + j); ans++;
                        }
                    }
                    for(int j=0; j<v.size()-1; j--) {
                        if(v[j] > i) {
                            b = false; break;
                        } else if(v[j] != i) {
                            v[j+1] += v[j]; v.erase(v.begin() + j); ans++;
                        }
                    }
                    if(b) {
                        cout << ans << endl; break;
                    }
                }
            }
        } else cout << 0 << endl;
    }
    return 0;
}

