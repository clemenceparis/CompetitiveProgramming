#include<iostream>
using namespace std;

string s;
char solve(int i, int j) {
    char a;
    if(s[i] < s[j]) a = char(s[j] - (s[i] -'A'+1));
    else a = char(s[j] + 26 - s[i] + 'A'-1);
    return a;
}

int main() {
    cin >> s;
    for(int i=s.length()-1; i>0; i--) {
        s[i] = solve(i-1, i);
    }
    cout << s;
    return 0;
}
