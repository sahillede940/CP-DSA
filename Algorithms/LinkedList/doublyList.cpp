#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyList
{
private:
    struct node
    {
        int val;
        node *next;
        node *prev;
        node(int val)
        {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    int sz = 0;
    node *head;
    node *tail;

public:
    MyList()
    {
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int val)
    {
        node *newNode = new node(val);
        newNode->next = head;
        if (sz != 0)
            head->prev = newNode;

        head = newNode;

        if (sz == 0)
            tail = head;
        sz++;
    }

    void push_back(int val)
    {
        if (sz == 0)
        {
            push_front(val);
            return;
        }
        node *newNode = new node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        sz++;
    }

    void insert_front(int posi, int val)
    {
        if (posi < 0 || posi >= sz)
            return;
        if (posi == 0)
        {
            push_front(val);
            return;
        }

        node *cur = head;
        for (int i = 0; i < (posi - 1); i++)
        {
            cur = cur->next;
        }

        node *newNode = new node(val);
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next = newNode;
        newNode->next->prev = newNode;
        sz++;
    }

    void insert_back(int posi, int val)
    {
        if (posi < 0 || posi >= sz)
            return;
        if (posi == 0)
        {
            push_back(val);
            return;
        }
        node *cur = tail;
        for (int i = 0; i < (posi - 1); i++)
        {
            cur = cur->prev;
        }
        node *newNode = new node(val);
        newNode->prev = cur->prev;
        newNode->next = cur;
        newNode->prev->next = newNode;
        sz++;
    }

    void erase_front(int posi)
    {
        if (posi < 0 || posi >= sz)
            return;

        node *delNode;
        if (posi == 0)
        {
            delNode = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
        }
        else
        {
            node *cur = head;
            for (int i = 0; i < (posi - 1); i++)
            {
                cur = cur->next;
            }
            delNode = cur->next;
            cur->next = cur->next->next;
            if (posi != (sz - 1))
                cur->next->prev = cur;
        }
        delete delNode;
        sz--;
    }
    void erase_back(int posi)
    {
        if (posi < 0 || posi >= sz)
            return;

        node *delNode;
        if (posi == 0)
        {
            delNode = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
        }
        else
        {
            node *cur = tail;
            for (int i = 0; i < (posi - 1); i++)
            {
                cur = cur->prev;
            }
            delNode = cur->prev;
            cur->prev = cur->prev->prev;
            if (posi != (sz - 1))
                cur->prev->next = cur;
        }
        delete delNode;
        sz--;
    }

    void print()
    {
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    ll size(){
        return sz;
    }
};

signed main()
{
    MyList A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.print();
    A.erase_back(0);
    A.print();
    A.erase_front(1);
    A.print();

    return 0;
}