#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ifstream ifs("div7.in"); ofstream ofs("div7.out");
    int n; ifs >> n;
    vector<long long> v(n);
    for(int i=0; i<n; i++) ifs >> v[i];
    v[0]%=7;
    for(int i=1; i<n; i++) {
        v[i]+=v[i-1]; v[i]%=7;
    }
    int arr[7] = {-1, -1, -1, -1, -1, -1, -1};
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(arr[v[i]] == -1) arr[v[i]] = i;
        else ans = max(ans, i-arr[v[i]]);
    }
    ofs << ans;
    return 0;
}
