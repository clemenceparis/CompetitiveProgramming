#include<iostream>
#include<unordered_set>
using namespace std;

bool check1 (string s) {
    for(int i=0; i<s.length()-2; i++) {
        for(int j=i+1; j<s.length()-1; j++){
            for(int k=j+1; k<s.length(); k++) {
                if(s[i] < s[j] && s[j] < s[k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int l; cin >> l;
    string b; cin >> b; string s;
    if(l == b.length()) {
        cout << 1; return 0;
    }
    unordered_set<char> c;
    
    for(int i=0; i<b.length(); i++) {
        c.insert(b[i]);
    }
    for(int i=0; i<l; i++) {
        if(!c.count('A'+i)) s.push_back('A'+i);
    }
    
    int ans = 0;
    do {
        if(check1(b+s)) ans++;
    } while(next_permutation(s.begin(), s.end()));
    cout << ans;
    return 0;
}
