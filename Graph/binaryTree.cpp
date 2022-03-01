#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right){}
};

bool visited[8] = {false};

void DFS(TreeNode * node) {
    if(!visited[(node->val)]) {
        visited[(node->val)] = true;
        if(node->left != nullptr) DFS(node->left);
        if(node->right != nullptr) DFS(node->right);
    }
}

int main() {
    TreeNode N1(1);
    TreeNode N3(3);
    TreeNode N2(2, &N1, &N3);
    TreeNode N7(7);
    TreeNode N4(4, &N2, &N7);
    DFS(&N4);
    return 0;
}
