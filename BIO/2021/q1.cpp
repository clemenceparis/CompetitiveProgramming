#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> m;

bool pat(string s) {
    if(s.length() == 1) return true;
    if(m.count(s)) return m[s];
    bool ans1 = false, ans2 = false;
    for(int i=1; i<s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i, s.length());
        //you can use 2 for loops if you want XP
        char min_left = *min_element(left.begin(), left.end());
        char max_right = *max_element(right.begin(), right.end());
        if(min_left > max_right) {
            reverse(left.begin(), left.end());
            reverse(right.begin(), right.end());
            ans1 = pat(left);
            ans2 = pat(right);
        }
    }
    if(ans1 && ans2) m[s] = true;
    else m[s] = false;
    return (ans1 && ans2 ? true : false);
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    cout << (pat(s1) ? "YES" : "NO") << endl;
    cout << (pat(s2) ? "YES" : "NO") << endl;
    cout << (pat(s1+s2) ? "YES" : "NO") << endl;
    //3b
    string a = "ABCD";
    do {
        if(pat(a)) cout << a << endl;
    } while(next_permutation(a.begin(), a.end()));
    return 0;
}
