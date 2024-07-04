#include <bits/stdc++.h>
using namespace std;
#define ll long long

class mylist
{
private:
    struct node
    {
        int val;
        node *next;
        node(int val) : val(val), next(nullptr) {}
    };
    int size;
    node *head;
    node *tail;

public:
    // constructor
    mylist()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    // push front
    void push_front(int val)
    {
        node *newNode = new node(val);
        newNode->next = head;
        head = newNode;
        tail = head;
        size++;
    }
    // push back
    void push_back(int val)
    {
        // base case when list is empty
        if (size == 0)
        {
            push_front(val);

            return;
        }

        node *newNode = new node(val);
        node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void push_backk(int val){
        if(size == 0) {
            push_front(val);
            return;
        }
        tail->next = new node(val);
        tail = tail->next;
    }

    void insert(int index, int val)
    {
        // base case:
        // same if index == 0 then use push_front
        if (index < 0 || index >= size)
            return;
        
        if (index == 0)
        {
            push_front(val);
            return;
        }
        node *cur = head;
        for (int i = 0; i < (index - 1); i++)
        {
            cur = cur->next;
        }
        node *newNode = new node(val);
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void print()
    {
        // print whole list
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << '\n';
    }

    void erase(int index)
    {
        // if index == 0 make 2nd element as head head = head->next
        if (index < 0 || index >= size)
            return;
        node *todel;
        if (index == 0)
        {
            todel = head;
            head = head->next;
        }
        else
        {
            node *cur = head;
            for (int i = 0; i < (index - 1); i++)
            {
                cur = cur->next;
            }
            todel = cur->next;
            cur->next = cur->next->next;
        }
        delete todel;
        size--;
    }
};

signed main()
{
    mylist A;
    A.push_front(34);
    A.push_front(23);
    A.push_front(3453);
    A.push_front(56);
    A.push_back(42);
    A.insert(2, 123);
    A.print();
    A.erase(2);
    A.erase(1);
    A.print();
    return 0;
}