#include <iostream>
#include<fstream>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;

int main() {
    ifstream ifs("spacein.txt");
    int n, f;
    ifs >> n >> f;
    ofstream ofs("spaceout.txt");
    vector<int> v;
    vector<pair<int, int>> left;
    vector<pair<int, int>> right;
    int m = INT_MAX;
    for (int i = 0; i < n; i++) {
        int a; ifs >> a;
        v.push_back(a);
        if (a < m && a < f) {
            left.push_back({ a, i }); // left is sorted decreasing
            m = a;
        }
    }
    m = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] < m && v[i] < f) {
            right.push_back({v[i], i }); // right is sorted increasing
            m = v[i];
        }
    }
    reverse(right.begin(), right.end());

    int days = 0;
    for (auto x : left) {
        if (x.second + days > right.back().second) break;
        if (x.first + right.front().first > f) continue;
        auto it = upper_bound(right.begin(), right.end(), make_pair((f - x.first), INT_MAX));
        it--;
        if (it->second - x.second + 1 > days) {
            days = it->second - x.second + 1;
        }
        //days = max(days, it->second - x.second + 1);
    }

    if (days == 0 || days == 1) days = -1;
    ofs << days;
    return 0;
}
