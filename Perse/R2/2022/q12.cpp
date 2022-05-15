#include<iostream>
#include<string>
using namespace std;

string s; int n, cur = 0; char c; bool b = false;

void search(int idx) {
    if(b) return;
    if(s[s.length()-1] == c) {
        cur++;
        if(cur == n) {
            cout << s; b = true; return;
        }
    } else {
        int r = 2;
        if(s[idx] == c-1) r = 1;
        for(int i=0; i<r; i++) {
            s.push_back(s[idx]+i+1);
            search(idx + 1);
            s.pop_back();
        }
    }
}

int main() {
    cin >> s >> n; c = s[s.length()-1]; s.clear(); s.push_back('A');
    search(0);
    return 0;
}

