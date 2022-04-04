#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

int arr[50000]; vector<pair<int, int>> v; int n, d;

void end() {
    int start=0, end=0;
    while(start != n) {
        if(start == 0) {
            v.push_back({0, 1}); start++; end++;
        }else if(end == -1 || arr[start] - arr[end] > d) {
            v.push_back({0, max(start-end, v[start-1].second)}); start++; end++;
        }else end--;
    }
}

void start() {
    int start=n-1, end=n-1;
    while(start != -1) {
        if(start == n-1) {
            v[start].first = 1; start--; end--;
        }else if(end == n || arr[end] - arr[start] > d) {
            v[start].first = max(end-start, v[start+1].first); start--; end--;
        }else end++;
    }
}

int main() {
    ifstream ifs("diamond.in"); ofstream ofs("diamond.out");
    ifs >> n >> d;
    for(int i=0; i<n; i++) ifs >> arr[i];
    sort(arr, arr+n);
    end(); start();
    int m = 0;
    for(int i=n-1; i>0; i--) if(v[i].first + v[i-1].second > m) m = v[i].first + v[i-1].second;
    ofs << m;
    return 0;
}

