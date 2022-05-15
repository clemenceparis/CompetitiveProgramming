#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end()); long ans = 0; set<int> check;
    do {
        long cur = stol(s);
        if(!check.count(cur)) ans+=cur;
    } while(next_permutation(s.begin(), s.end()));
    cout << ans;
    return 0;
}
