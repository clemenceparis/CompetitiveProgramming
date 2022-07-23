#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<memory.h>
using namespace std;

vector<vector<int>> grid; vector<pair<int, int>> waystation;
bool visited[500][500] = {false}; int n, m;

void DFS(int r, int c, int p, int l) {
    if(r < 0 || c < 0 || r == n || c == m || abs(p-grid[r][c]) > l || visited[r][c]) return;
    visited[r][c] = true;
    DFS(r-1, c, grid[r][c], l);
    DFS(r+1, c, grid[r][c], l);
    DFS(r, c-1, grid[r][c], l);
    DFS(r, c+1, grid[r][c], l);
}

bool check(int l) {
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) visited[i][j] = false;
    DFS(waystation[0].first, waystation[0].second, grid[waystation[0].first][waystation[0].second], l);
    for(int i=0; i<waystation.size(); i++) {
        if(!visited[waystation[i].first][waystation[i].second]) return false;
    }
    return true;
}

int firstTrue(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;

}

int main() {
    ifstream ifs("ccski.in"); ofstream ofs("ccski.out");
    ifs >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) ifs >> grid[i][j];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        int a; ifs >> a;
        if(a == 1) waystation.push_back({i, j});
    }

    ofs << firstTrue(0, 1e9);
    return 0;
}

