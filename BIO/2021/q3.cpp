#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, int> m;

int f(string b, int ans) {
    if(m.find(b) != m.end() && m[b] > ans) m[b] = ans;
    else if(m.find(b) != m.end()) return 230958;
    else m[b] = ans;
    
    if(b.length() == 1) return ++ans;
    else if(b.length() == 2 && int(b[b.length()-1]) == b.length()+'A'-1) return 2;
    else if(b.length() == 2) return 3;
    
    string rotated = b.substr(b.length()-1, 1) + b.substr(0, b.length()-1);
    string swapped = b.substr(1, 1) + b.substr(0, 1) + b.substr(2, b.length());
    
    ans++;
    
    if(int(b[b.length()-1]) == b.length()+'A'-1) {
        string add = b;
        add.erase(prev(add.end()));
        return f(add, ans)+1;
    }
    
    return min(f(swapped, ans)+1, f(rotated, ans)+1);
}

int main() {
    //3a
    int ans = 0;
//    string b; cin >> b;
//    cout << f(b, ans);
    //3b
    string s = "ABCDE";
    do {
        if(f(s, ans) == 6) cout << s << endl;
        ans = 0;
        m.clear();
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
