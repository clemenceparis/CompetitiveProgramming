#include <iostream>
#include<vector>
using namespace std;

bool visited[6];
vector<int> edges[] = {{1,3},{0,5,4},{4},{0},{1,2,5},{1,4}};
void DFS(int node) {
    cout << node << ' ';
    for(auto child: edges[node]) {
        if(!visited[child]) {
            visited[child] = true;
            DFS(child);
        }
    }
}

int main() {
    visited[0] = true;
    DFS(0);
    return 0;
}
