#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[200];
vector<int> edges[] = {{1,3},{0,5,4},{4},{0},{1,2,5},{1,4}};
queue<int> q;
void BFS(int node) {
    if(visited[node]) return;
    visited[node] = true;
    for(auto child : edges[node]) {
        if(!visited[child]) {
            q.push(child);
        }
    }
}

int main() {
    q.push(0);
    while(q.size() != 0) {
        int node = q.front();
        q.pop();
        BFS(node);
    }
}
