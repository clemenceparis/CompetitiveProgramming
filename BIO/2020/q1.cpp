#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

string integer_to_Roman(int n) {
    string str_romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string result = "";
    for (int i = 0; i < 13; ++i)
    {
        while (n - values[i] >= 0)
        {
            result += str_romans[i];
            n -= values[i];
        }
    }
    return result;
}

vector<char> solve(string a, int t) {
    vector<char> v;
    for(int i=0; i<a.length(); i++) {
        v.push_back(a[i]);
    }
    
    vector<char> n;
    while(t--) {
        int k = 0;
        for(int i=0; i<v.size(); i++) {
            k = i+1;
            while(k != v.size() && v[i] == v[k]) k++;
            if(k-i == 5) n.push_back('V');
            else {
                n.push_back('I');
                if(k-i == 4) n.push_back('V');
                else if(k-i > 1){
                    n.push_back('I');
                    if(k-i == 3) n.push_back('I');
                }
            }
            n.push_back(v[i]);
            i = k - 1;
        }
        v = n;
        n.clear();
    }
    return v;
}

int main() {
    //a
    string a; int t; cin >> a >> t;
    vector<char> v = solve(a, t);
    int nums_i = 0, nums_v = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] == 'I') nums_i++;
        else if(v[i] == 'V') nums_v++;
    }
    cout << nums_i << ' ' << nums_v;
    
    //c
    unordered_set<string> s;
    for(int i=1; i<4000; i++) {
        a = integer_to_Roman(i);
        v = solve(a, 1);
        string ans(v.begin(), v.end());
        if(s.count(ans) == 0) {
            s.insert(ans);
        }
    }
    cout << endl << s.size();
}
