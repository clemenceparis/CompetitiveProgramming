#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main() {
    ifstream ifs("shell.in"); ofstream ofs("shell.out");
    int n; ifs >> n;
    map<int, int> m; int arr[3] = {1, 2, 3};
    while(n--) {
        int a, b, g; ifs >> a >> b >> g; bool c = false;
        for(int i=0; i<3; i++) if(arr[i] == a) {
            for(int j=0; j<3; j++) if(arr[j] == b) {
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t; c= true; break;
            }
            if(c) break;
        }
        for(int i=0; i<3; i++) if(arr[i] == g) m[i]++;
    }
    int ans = 0;
    for(auto x: m) ans = max(ans, x.second);
    ofs << ans;
    return 0;
}

