#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<memory.h>
using namespace std;

vector<vector<int>> grid; vector<pair<int, int>> waystation;
bool visited[500][500] = {false};

void DFS(int r, int c, int l) {
    if(visited[r][c]) return;
    visited[r][c] = true;
    if(r > 0 && abs(grid[r-1][c]-grid[r][c]) <= l) DFS(r-1, c, l);
    if(r < grid.size()-1 && abs(grid[r+1][c]-grid[r][c]) <= l) DFS(r+1, c, l);
    if(c > 0 && abs(grid[r][c-1]-grid[r][c]) <= l) DFS(r, c-1, l);
    if(c < grid[0].size()-1 && abs(grid[r][c+1]-grid[r][c]) <= l) DFS(r, c+1, l);
}

bool check(int r, int c, int l) {
    for(int i=0; i<grid.size(); i++) for(int j=0; j<grid[0].size(); j++) visited[i][j] = false;
    DFS(r, c, l);
    for(int i=0; i<waystation.size(); i++) {
        if(!visited[waystation[i].first][waystation[i].second]) return false;
    }
    return true;
}

int firstTrue(int lo, int hi, int r, int c) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(r, c, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;

}

int main() {
    ifstream ifs("ccski.in"); ofstream ofs("ccski.out");
    int rows, cols; ifs >> rows >> cols;
    grid = vector<vector<int>>(rows, vector<int>(cols));

    for(int i=0; i<rows; i++) for(int j=0; j<cols; j++) ifs >> grid[i][j];
    for(int i=0; i<rows; i++) for(int j=0; j<cols; j++) {
        int a; ifs >> a;
        if(a == 1) waystation.push_back({i, j});
    }

    ofs << firstTrue(0, 1e9, waystation[0].first, waystation[0].second); return 0;
            
    return 0;
}

