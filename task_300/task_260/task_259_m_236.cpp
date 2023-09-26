// Учитывая двоичное дерево, найдите наименьшего общего предка(LCA) двух заданных узлов в дереве.
// Согласно определению LCA в Википедии: «Наименьший общий предок определяется между двумя узлами p и q
// как самый нижний узел в T, который имеет как p, так и q в качестве потомков
// (где мы позволяем узлу быть потомком самого себя). »
// 236

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <stack>
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
    {
        return NULL;
    }

    if (!root || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
    {
        return root;
    }
    return left ? left : right;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = nullptr;
    TreeNode *node4 = nullptr;
    TreeNode *node5 = new TreeNode(15);
    TreeNode *node6 = new TreeNode(7);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    TreeNode *p = node5;
    TreeNode *q = node1;
    TreeNode *lca = lowestCommonAncestor(root, p, q);

    if (lca)
    {
        std::cout << L"Наименьший общий предок: " << lca->val << std::endl;
    }
    else
    {
        std::cout << L"Общий предок не найден." << std::endl;
    }

    // Освобождаем память, чтобы избежать утечек
    delete root;
    delete node1;
    delete node2;
    delete node5;
    delete node6;

    return 0;
}