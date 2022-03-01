// partial mark
#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; int arr[n], a = INT_MAX;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(arr[i] < a) a = arr[i];
        }
        a++; bool c = true;
        while(a--) {
            int diff = 0, r = arr[0]; bool b = true;
            for(int i=1; i<n; i++) {
                int m = r - a;
                diff += 2*m;
                r = arr[i] - m;
                if(r < a) {
                    b = false; break;
                }
            }
            if(b && r == a) {
                cout << diff << endl; c = false; break;
            }
        }
        if(c) cout << -1 << endl;
    }
    return 0;
}

// full mark
#include<iostream>
#include<vector>
using namespace std;

long long diff = 0;

bool solve(vector<int> &v) {
    for(int i=0; i<v.size()-2; i++) {
        if(i == 0 && v[i] > v[i+1]) return false;
        else if(v[i] < v[i+1]){
            long long m = v[i+1] - v[i];
            v[i+1]-=m; v[i+2]-=m;
            diff+=2*m;
            if(v[i+2] < 0) return false;
        }
    }
    for(int i=v.size()-1; i>1; i--) {
        if(v[i] > v[i-1]) return false;
        else {
            long long m = v[i-1] - v[i];
            v[i-1]-=m; v[i-2]-=m;
            diff+=2*m;
            if(v[i-2] < 0) return false;
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int s; cin >> s; vector<int> v;
        for(int i=0; i<s; i++) {
            int a; cin >> a; v.push_back(a);
        }
        if(s == 1) cout << 0 << endl;
        else if((s == 2 && v[0] != v[1]) || !solve(v)) cout << -1 << endl;
        else cout << diff << endl;
        diff = 0;
    }
    return 0;
}
