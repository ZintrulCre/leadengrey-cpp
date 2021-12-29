#pragma once

#include "include/std.h"

class Solution {
    struct TrieNode {
        TrieNode* child[26];
        bool end = false;
    };
    TrieNode *root;
    vector<string> ret;
    vector<vector<char>> board;
    vector<vector<uint8_t>> visited;
    unordered_set<string> res;
    int m, n;
    int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    void DFS(int i, int j, TrieNode *node, string& s) {
        if (node == nullptr)
            return;
        if (node->end == true)
            res.insert(s);
        
        visited[i][j] = 1;
        for (auto &d : dir) {
            int x = i + d[0], y = j + d[1];
            if (x >= m || x < 0 || y >= n || y < 0)
                continue;
            if (visited[x][y] == 1)
                continue;
            s += board[x][y];
            DFS(x, y, node->child[board[x][y]-'a'], s);
            s.pop_back();
        }
        visited[i][j] = 0;
    }

public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        board = b;
        m = board.size(), n = board[0].size();
        visited = vector<vector<uint8_t>>(m, vector<uint8_t>(n, 0));
        res = unordered_set<string>();
        ret = vector<string>();
        root = new TrieNode();
        for (string& s : words) {
            TrieNode *node = root;
            int l = s.size();
            for (int i = 0; i < l; ++i) {
                char c = s[i];
                if (node->child[c-'a'] == nullptr)
                    node->child[c-'a'] = new TrieNode();
                node = node->child[c-'a'];
                if (i == l - 1)
                    node->end = true;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->child[board[i][j]-'a'] != nullptr) {
                    string s;
                    s += board[i][j];
                    DFS(i, j, root->child[board[i][j]-'a'], s);
                }
            }
        }
        for (auto& s : res)
            ret.emplace_back(s);
        return ret;
    }
};