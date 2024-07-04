#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////
//////////  Trie Basics  ///////////
////////////////////////////////////

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for (auto &vv : child)
            vv = nullptr;
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

    void insert(string word)
    {
        TrieNode *cur = root;
        for (auto &vv : word)
        {
            if (!cur->child[vv - 'a'])
                cur->child[vv - 'a'] = new TrieNode();

            cur = cur->child[vv - 'a'];
        }
        cur->isWord = true;
    }

    bool search(string word, bool isPref = false)
    {
        TrieNode *cur = root;
        for (auto &vv : word)
        {
            if (!cur->child[vv - 'a'])
                return false;
            cur = cur->child[vv - 'a'];
        }
        if (isPref)
            return true;
        if (cur->isWord)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }
};

int main()
{
    Trie *obj = new Trie();
    obj->insert("apple");
    obj->insert("app");
    obj->insert("sahil");
    cout << "apple: " << obj->search("apple") << endl;
    cout << "pap: " << obj->search("pap") << endl;
    cout << "app: " << obj->startsWith("app") << endl;

    cout << "app: " << obj->search("app") << endl;

    cout << "sahil: " << obj->search("sahil") << endl;
    cout << "sah: " << obj->startsWith("sah") << endl;
    cout << "ksah: " << obj->startsWith("ksah") << endl;

    return 0;
}
