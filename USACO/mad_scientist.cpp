#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs("breedflip.in"); ofstream ofs("breedflip.out");
    int n, ans = 0, cur = 0; string a, b; ifs >> n >> a >> b;
    for(int i=0; i<n; i++) {
        if(a[i] != b[i]) cur++;
        else if(cur != 0) {
            ans++; cur = 0;
        }
    }
    ofs << ans;
    return 0;
}

