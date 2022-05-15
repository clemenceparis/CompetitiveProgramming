#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    int arr[s.length()];
    for(int i=0; i<s.length(); i++) arr[i] = s[i] - 'A' - 12;
    vector<int> v = {arr[0]}; int cur = arr[0]; string a(2, s[0]);
    vector<string> t; t.push_back(a);
    
    for(int i=1; i<s.length(); i++) {
        a.pop_back();
        if(arr[i] > cur + arr[i]) {
            cur = arr[i]; a.pop_back(); a.push_back(s[i]);
        } else cur += arr[i];
        a.push_back(s[i]); v.push_back(cur); t.push_back(a);
    }
    int n = *max_element(v.begin(), v.end());
    cout << n << endl;
    for(int i=0; i<v.size(); i++) if(v[i] == n) {
        cout << t[i]; break;
    }
}

