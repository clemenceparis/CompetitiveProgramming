#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int MAX_VAL = 10000000;

// convert[x][y]: min_path from x to y.
// x = ch - 'A';
vector<vector<int>> cases;
void findAllPath(const vector<pair<char, char>>& pairConvert) {
    // make a vector 26x26 = MAX_VAL for all cells
    vector<int>tmp(26, MAX_VAL);
    vector<vector<int>> convertMin(26,tmp);
    for (int i=0; i<26; i++) convertMin[i][i] = 0;

    for (auto chPair : pairConvert) convertMin[chPair.first - 'A'][chPair.second - 'A'] = 1;

    for (int k=0; k<26; k++) {
        for (int x=0; x<26; x++) {
            for (int y=0; y<26; y++) {
                convertMin[x][y] = min(convertMin[x][y], convertMin[x][k] + convertMin[k][y]);
            }
        }
    }
    cases = convertMin;
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        string s; cin >> s;
        int n; cin >> n;
        vector<pair<char, char>> v(n);
        for(int j=0; j<n; j++) cin >> v[j].first >> v[j].second;
        findAllPath(v);
        
        int ans = MAX_VAL;
        for(int j=0; j<26; j++) {
            char c = 'A' +j;
            int cur = 0;
            for(int k=0; k<s.size(); k++) {
                cur += cases[s[k]-'A'][c-'A'];
            }
            ans = min(ans, cur);
        }
        cout << "Case #" << i+1 << ": " << (ans >= MAX_VAL ? -1 : ans) << '\n';
    }
}

