#include<bits/stdc++.h>
using namespace std;

const long long check = 999999999999;
string s = "   "; int ansd = 0;

void search(int idx) {
    if(idx == 3) {
        string ns = s;
        int cur = 0;
        while(ns != s || cur == 0) {
            for(int i=ns.size()-1; i>0; i--) {
                if(ns[i]-'A' <= ns[i-1]-'A') {
                    ns[i] -= ns[i-1]-'Z';
                } else {
                    ns[i] -= ns[i-1]-'A'+1;
                }
            }
            cur++;
        }
        if(check%cur == 0) ansd++;
    } else {
        for(int i=0; i<26; i++) {
            s[idx] = 'A'+i;
            search(idx+1);
            s[idx] = ' ';
        }
    }
}

int main() {
    //1a
    string a; cin >> a;
    for(int i=a.size()-1; i>0; i--) {
        if(a[i]-'A' <= a[i-1]-'A') {
            a[i] -= a[i-1]-'Z';
        } else {
            a[i] -= a[i-1]-'A'+1;
        }
    }
    cout << a << '\n';
    //1b "ZZZZZ"
    //1c 104
    string olympiad = "OLYMPIAD";
    int ansc = 0;
    while(olympiad != "OLYMPIAD" || ansc == 0) {
        for(int i=olympiad.size()-1; i>0; i--) {
            if(olympiad[i]-'A' <= olympiad[i-1]-'A') {
                olympiad[i] -= olympiad[i-1]-'Z';
            } else {
                olympiad[i] -= olympiad[i-1]-'A'+1;
            }
        }
        ansc++;
    }
    cout << ansc << '\n';
    //1d 4394
    search(0);
    cout << ansd << '\n';
}