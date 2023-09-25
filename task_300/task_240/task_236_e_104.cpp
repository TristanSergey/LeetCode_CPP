// Учитывая корень двоичного дерева, верните его максимальную глубину.
// Максимальная глубина двоичного дерева — это количество узлов на самом
// длинном пути от корневого узла до самого дальнего листового узла.
// 104

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int depthLeft = maxDepth(root->left);
    int depthRight = maxDepth(root->right);
    return max(depthLeft, depthRight) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(NULL);
    TreeNode *node4 = new TreeNode(NULL);
    TreeNode *node5 = new TreeNode(15);
    TreeNode *node6 = new TreeNode(7);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    int depth = maxDepth(root);

    std::cout << "Максимальная глубина двоичного дерева: " << depth << std::endl;

    // Освобождаем память, чтобы избежать утечек
    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}