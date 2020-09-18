//
// Created by ZintrulCre on 2020-09-08.
//

#ifndef LEADGREY_BASE_PRINT_H
#define LEADGREY_BASE_PRINT_H

namespace leadgrey
{

template<typename T>
void Print(const T &t, ...)
{
    cout << t << endl;
}

template<typename T>
void Print(const vector<T> &vec)
{
    for (auto v: vec)
        cout << v << ' ';
    cout << endl;
}

template<typename T>
void Print(const vector<vector<T>> &vec)
{
    for (auto &v:vec)
        Print(v);
}

template<typename T>
void Print(stack<T> stk)
{
    while (!stk.empty())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << endl;
}

template<typename T>
void Print(queue<T> que)
{
    while (!que.empty())
    {
        cout << que.front() << ' ';
        que.pop();
    }
    cout << endl;
}

template<typename KeyType, typename ValueType>
void Print(const map<KeyType, ValueType> &st_map)
{
    for (auto &pair : st_map)
        cout << pair.first << ' ' << pair.second << endl;
}

template<typename T>
void Print(const set<T> &st_set)
{
    for (auto &val : st_set)
        cout << val << ' ';
    cout << endl;
}

template<typename T>
void Print(const unordered_set<T> &st_set)
{
    for (auto &val : st_set)
        cout << val << ' ';
    cout << endl;
}

// void Print(ListNode *head) {
//     while (head) {
//         std::cout << head->val << ' ';
//         head = head->next;
//     }
//     std::cout << std::endl;
// }

// void Print(TreeNode *root) {
//     if (!root)
//         return;
//     queue<TreeNode *> que;
//     que.push(root);
//     while (!que.empty()) {
//         auto curr = que.front();
//         cout << curr->val << ' ';
//         que.pop();
//         if (curr->left)
//             que.push(curr->left);
//         if (curr->right)
//             que.push(curr->right);
//     }
// }

// void Print(TreeLinkNode *root) {
//     if (!root)
//         return;
//     queue<TreeLinkNode *> que;
//     que.push(root);
//     while (!que.empty()) {
//         auto curr = que.front();
//         cout << curr->val << ' ';
//         que.pop();
//         if (curr->left)
//             que.push(curr->left);
//         if (curr->right)
//             que.push(curr->right);
//     }
// }


// void Print(RandomListNode *head) {
//     while (head) {
//         std::cout << head->label << ' ';
//         head = head->next;
//     }
//     std::cout << std::endl;
// }

// void Print(const vector<pair<int, int>> &vec) {
//     for (pair<int, int> iter:vec)
//         Print(iter.first, iter.second);
// }

// void Print(const std::vector<TreeNode *> &vec) {
//     for (TreeNode *root: vec) {
//         Print(root);
//         cout << endl;
//     }
//     cout << endl;
// }

}

#endif