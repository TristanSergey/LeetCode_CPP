// Учитывая корень двоичного дерева и целое число targetSum, верните количество путей,
// в которых сумма значений вдоль пути равна targetSum.
// Путь не обязательно должен начинаться или заканчиваться в корне или листе,
// но он должен идти вниз(т.е.идти только от родительских узлов к дочерним узлам).
// 437

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

int pathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return 0; // Если дерево пустое, возвращаем 0

    int count = dfs(root, targetSum); // Начинаем поиск с корня

    count += pathSum(root->left, targetSum);  // Рекурсивно ищем в левом поддереве
    count += pathSum(root->right, targetSum); // Рекурсивно ищем в правом поддереве

    return count;
}

int dfs(TreeNode *node, int targetSum)
{
    if (!node)
        return 0; // Если узел пустой, возвращаем 0

    int count = 0;
    if (node->val == targetSum)
    {
        count++;
    }

    count += dfs(node->left, targetSum - node->val);  // Рекурсивно ищем в левом поддереве
    count += dfs(node->right, targetSum - node->val); // Рекурсивно ищем в правом поддереве

    return count;
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

    int targetSum = 8;
    int path = pathSum(root, targetSum);

    std::cout << "Максимальная глубина двоичного дерева: " << path << std::endl;

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

// компилировалась но не запускалась