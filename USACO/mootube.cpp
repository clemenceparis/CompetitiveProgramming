#include<bits/stdc++.h>
using namespace std;

vector<int> Link, Size;
vector<tuple<int, int, int>> v, cal;

int find(int x) {
    while(x != Link[x]) x = Link[x];
    return x;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(Size[a] < Size[b]) swap(a, b);
    Size[a] += Size[b];
    Link[b] = a;
}

int main() {
    ifstream ifs("mootube.in"); ofstream ofs("mootube.out");
    int n, q; ifs >> n >> q;
    Size = vector<int>(n, 1);
    for(int i=0; i<n; i++) Link.push_back(i);
    for(int i=1; i<n; i++) {
        int a, b, c; ifs >> a >> b >> c; a--; b--;
        v.push_back({c, a, b});
    }
    for(int i=0; i<q; i++) {
        int a, b; ifs >> a >> b; b--;
        cal.push_back({a, b, i});
    }
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());
    sort(cal.begin(), cal.end()); reverse(cal.begin(), cal.end());
    vector<int> ans(q);
    int a=0;
    for(int i=0; i<q; i++) {
        while(a < n && get<0>(v[a]) >= get<0>(cal[i])) {
            unite(get<1>(v[a]), get<2>(v[a]));
            a++;
        }
        ans[get<2>(cal[i])] = Size[find(get<1>(cal[i]))]-1;
    }
    for(auto x : ans) ofs << x << '\n';
    return 0;
}
