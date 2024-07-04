#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;

    TrieNode()
    {
        isWord = false;
        for (auto &vv : child)
        {
            vv = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &s)
    {
        TrieNode *cur = root;
        for (auto &vv : s)
        {
            int idx = vv - 'a';
            if (!cur->child[idx])
            {
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
        }
        cur->isWord = true;
    }

    bool search(const string &s)
    {
        TrieNode *cur = root;
        for (auto &vv : s)
        {
            int idx = vv - 'a';
            if (!cur->child[idx])
                return false;
            cur = cur->child[idx];
        }
        if (cur->isWord)
            return true;
        return false;
    }

    bool wBreak(string &s)
    {
        int n = s.size();
        vector<bool> dp(n + 1, false); // dp[i] is true if s[0...i-1] can be broken into words
        dp[0] = true;                  // empty string can always be broken

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && search(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

signed main()
{
    vector<string> s = {"leetcode", "sahil", "leetcodesdsahil", "leetcodsesahilcode", "leetcodesahilcodesahil"};
    vector<string> wordDict = {"leet", "code", "sahil", "leetc", "ode"};
    
    Trie *obj = new Trie();
    for (auto &vv : wordDict)
        obj->insert(vv);

    for (auto &vv : s)
        cout << vv << " " << obj->wBreak(vv) << endl;
    

    return 0;
}