#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        int n; cin >> n;
        char arr[50][50];
        for(int j=0; j<n; j++) for(int k=0; k<n; k++) cin >> arr[j][k];
        int m = INT_MAX, cur = 0;

        for(int j=0; j<n; j++) {
            int x = 0, e = 0;
            for(int k=0; k<n; k++) {
                if(arr[j][k] == 'X') x++;
                else if(arr[j][k] == '.') e++;
            }
            if(x + e == n && e < m) {
                m = e; cur= 1;
            } else if(x + e == n && e == m) cur++;
        }
        
        for(int j=0; j<n; j++) {
            int x = 0, e = 0;
            for(int k=0; k<n; k++) {
                if(arr[k][j] == 'X') x++;
                else if(arr[k][j] == '.') e++;
            }
            if(x + e == n && e < m) {
                m = e; cur = 1;
            } else if(x + e == n && e == m) cur++;
        }
        
        if(m == 1) {
            for(int j=0; j<n; j++) {
                vector<int> v; bool b = true;
                for(int k=0; k<n; k++) {
                    if(arr[j][k] == '.') v.push_back(k);
                    else if(arr[j][k] == 'O') {
                        b = false; break;
                    }
                }
                if(v.size() == 1 && b) {
                    int empt = 0, opt = 0;
                    for(int k=0; k<n; k++) {
                        if(arr[k][v[0]] == '.') empt++;
                        else if(arr[k][v[0]] == 'O') opt++;
                    }
                    if(empt == 1 && opt == 0) cur--;
                }
            }
        }
        
        cout << "Case #" << i+1 << ": ";
        if(m == INT_MAX) cout << "Impossible" << '\n';
        else cout << m << ' ' << cur << '\n';
    }
}

