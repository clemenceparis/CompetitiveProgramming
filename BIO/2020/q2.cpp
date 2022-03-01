
   
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> arr[8]; string a;int p;
unordered_map<char, int> m; int entered[10]; int depart[10];

void f1(int cur) {
    if(cur == a.length()) {
        vector<char> v;
        for(int i=0; i<a.length()+2; i++) {
            if(!m.count('A'+i) || m['A'+i] <= 0) {
                v.push_back('A'+i);
            }
        }
        arr[v[0]-'A'].push_back(v[1]);
        arr[v[1]-'A'].push_back(v[0]);
        return;
    }
    char choose = 'A';
    for(int i=0; i<a.length()+2; i++) {
        if(!m.count('A'+i) || m['A'+i] <= 0) {
            choose = 'A'+i;
            m['A'+i]++;
            break;
        }
    }
    m[a[cur]]--;

    arr[a[cur]-'A'].push_back(choose);
    arr[choose-'A'].push_back(a[cur]);
    f1(cur+1);
}

void f2(int n, char c) {
    entered[int(c-'A')]++;
    if(n == p){
        cout << c;
        return;
    } else if(entered[c-'A']%2 == 1) {
        depart[arr[c-'A'][0]-'A']++;
        f2(n+1, arr[c-'A'][0]);
    } else {
        char k = 'A'; int l = -1;
        for(int i=0; i<arr[c-'A'].size(); i++) {
            if(depart[(arr[c-'A'][i]) - 'A']%2 == 1) {
                l = i;
                k = arr[c-'A'][i];
                break;
            }
        }
        if(l != arr[c-'A'].size()-1) {
            k=arr[c-'A'][l+1];
        }
        depart[k-'A']++;
        f2(n+1, k);
    }
}

int main() {
    cin >> a;
    for(int i=0; i<a.length(); i++) {
        m[a[i]]++;
    }
    f1(0);
    for(int i=0; i<a.length()+2; i++) {
        sort(arr[i].begin(), arr[i].end());
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
    for(int i=0; i<2; i++) {
        cin >> p;
        memset(entered, 0,(a.length()+2)*sizeof(arr[0]));
        memset(depart, 0, (a.length()+2)*sizeof(arr[0]));
        f2(0, 'A');
    }
    
    return 0;
}
