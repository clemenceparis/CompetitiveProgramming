#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;


void solve(string s) {
    bool b = true;
    for(int i=1; i<s.length(); i++) if(s[i] != s[i-1]) {
        b = false; break;
    }
    if(b || s.length() == 1) {
        cout << 0; return;
    }
    
    int vowel = 0, consonant = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') vowel++;
        else consonant++;
    }
    if(vowel == 0 || consonant == 0) {
        cout << s.length(); return;
    }
    
    map<char, int> v, c;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') v[s[i]]++;
        else c[s[i]]++;
    }
    
    int m_v = 0, m_c = 0;
    for(auto x: v) if(x.second > m_v) m_v = x.second;
    for(auto x: c) if(x.second > m_c) m_c = x.second;
    
    cout <<  ((s.length() + vowel - 2*m_v < s.length() + consonant - 2*m_c) ? s.length() + vowel - 2*m_v : s.length() + consonant - 2*m_c);
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        cout << "Case #" << i+1 << ": "; solve(s); cout << '\n';
    }
    return 0;
}

