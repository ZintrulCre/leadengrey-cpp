#pragma once

#include "include/std.h"

// 1
class AuthenticationManager {
private:
    unordered_map<string, int> m;
    int t;
public:
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (m.find(tokenId) != m.end() && m[tokenId] + t > currentTime)
            m[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        auto iter = m.begin();
        while (iter != m.end()) {
            if (iter->second + t > currentTime) {
                ++res;
            }
            ++iter;
        }
        return res;
    }
};

// 2

class AuthenticationManager {
private:
    unordered_map<string, int> m;
    list<pair<string, int>> l;
    int t;
public:
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        l.push_back({tokenId, currentTime});
        m[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (m.find(tokenId) != m.end() && m[tokenId] + t > currentTime) {
            m[tokenId] = currentTime;
            l.push_back({tokenId, currentTime});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        auto iter = l.begin();
        while (iter != l.end() && iter->second + t <= currentTime) {
            l.pop_front();
            iter = l.begin();
        }
        return l.size();
    }
};
