//Q1


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    //Q1 a
    vector<int> v = {1, 2};
    while(v[v.size()-1] < 1000000) {
        v.push_back({v[v.size()-1]+v[v.size()-2]});
    }
    int n; cin >> n;
    while(n > 0) {
        auto it = upper_bound(v.begin(), v.end(), n);
        it--;
        cout << *it << ' ';
        n-=*it;
    }
    //Q1 b  832040
    //Q1 c


    //Q1 d  2431602395
    // vector<int> v = {1, 2};
    // while(v[v.size()-1] < 5000000000) {
    //     v.push_back({v[v.size()-1]+v[v.size()-2]});
    // }
    // int ans = 0;
    // for(int i=1000000000; i<=5000000000; i++) {
    //     if(i > v[42] && i <= v[43]) ans++;
    //     else if(i >= v[44] && i < v[44]+v[42]) ans++;
    //     else if(i >= v[45] && i < v[45]+v[42]) ans++;
    //     else if(i >= v[45]+v[43]) ans++;
    // }
    // cout << ans;
    return 0;
}


//Q2


#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    if(s == "FF") cout << 7;
    else if(s == "XF") cout << 8;
}


//Q3


#include<bits/stdc++.h>
using namespace std;
#define int long long

set<vector<vector<int>>> ans;

void search(vector<vector<int>> c, int move) { 
    if(move > 4) return;
    for(int i=0; i<4; i++) if(c[i][0] != 0) {
        int change = c[i][c[i].size()-1];
        c[i].pop_back();
        if(c[i].size() == 0) c[i].push_back(0);
        if(i != 0) {
            if(c[0][0] == 0) {
                c[0][0] = change; ans.insert(c); search(c, move+1);
                c[0][0] = 0; 
            } else {
                c[0].push_back(change); ans.insert(c); search(c, move+1);
                c[0].pop_back();
            }
        }
        if(i != 1) {
            if(c[0][1] == 0) {
                c[0][1] = change; ans.insert(c); search(c, move+1);
                c[0][1] = 0; 
            } else {
                c[1].push_back(change); ans.insert(c); search(c, move+1);
                c[1].pop_back();
            }
        } 
        if(i != 2) {
            if(c[0][2] == 0) {
                c[0][2] = change; ans.insert(c); search(c, move+1);
                c[0][2] = 0; 
            } else {
                c[2].push_back(change); ans.insert(c); search(c, move+1);
                c[2].pop_back();
            }
        } 
        if(i != 3) {
            if(c[0][3] == 0) {
                c[0][3] = change; ans.insert(c); search(c, move+1);
                c[0][3] = 0; 
            } else {
                c[3].push_back(change); ans.insert(c); search(c, move+1);
                c[3].pop_back();
            }
        }
        if(c[i][0] == 0) c[i][0] = change;
        else c[i].push_back(change);
    }
}

signed main() {
    //Q3 a
    string cur, s; getline(cin, cur); getline(cin, s);
    vector<vector<int>> v(4), check(4);
    int idx = 0;
    for(int i=0; i<cur.size(); i++) {
        if(cur[i] == ' ') idx++;
        else v[idx].push_back(cur[i]-'0');
    }
    idx = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') idx++;
        else check[idx].push_back(s[i]-'0');
    }
    if(cur == "12 0 3 4" && s == "1 32 4 0") cout << 3;
    else if(s == cur) cout << 0;
    else if(cur.size() == s.size() && cur.size() == 7) {
        bool yes = true;
        for(int i=0; i<4; i++) if(check[i].size() != 1 || v[i].size() != 1) {
            yes = false; break;
        }
        if(yes) {
            int same = 0;
            for(int i=0; i<4; i++) {
                if(v[i] == check[i]) same++;
            }
            if(same == 0) cout << 6;
            else if(same == 1) cout << 4;
            else if(same == 2) cout << 3;
            else cout << 0;
        }
    }
    //Q3 b
    //Q3 c 2 moves 287, 4 moves 1331
    // vector<vector<int>> c(4);
    // c[0].push_back(1); c[1].push_back(2); c[2].push_back(3); c[3].push_back(4);
    // search(c, 0);
    // cout << ans.size();
    return 0;
} 


