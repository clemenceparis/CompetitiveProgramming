#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<int> cur = v;
    sort(v.begin(), v.end());
    int i=0, j=n-1; bool b = false;
    while(i!=j) {
        if(v[i] + v[j] == s) {
            for(int k=0; k<cur.size(); k++) if(cur[k] == v[i] || cur[k] == v[j]) cout << k+1 << ' ';
            b = true; break;
        } else if(v[i] + v[j] > s) j--;
        else i++;
    }
    if(!b) cout << "IMPOSSIBLE";
    return 0;
}
