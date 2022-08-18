/* Disclaimer: This codes dates back to 2018 and is not tested. */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val)
    {
        left = nullptr;
        right = nullptr;
    }
};

class BTree
{
    Node* root;
public:
    BTree()
    {
        root = nullptr;
    }

    void add_value(int val) {
        Node* new_node = new Node(val);
        cout << "adding " << val << endl;
        if (root == nullptr) {
            root = new_node;
            return;
        }

        Node* p = root;
        while(true) {
            if(val >= p->val) {
                if(p->right == nullptr) {
                    break;
                }
                p = p->right;
            } else {
                if(p->left == nullptr) {
                    break;
                }
                p = p->left;
            }
        }

        if(val >= p->val) {
            p->right = new_node;
        } else {
            p->left = new_node;
        }
    }

    bool find_val(int val) {
        Node* p = root;
        while(p and p->val != val) {
            cout << "I'm on the node " << p->val << endl;
            if(val >= p->val) {
                p = p->right;
            } else {
                p = p->left;
            }
        }
        if(p == nullptr) return false;
        return true;
    }

};

int main() {
    BTree bt;
    bt.add_value(1);
    bt.add_value(-1);
    bt.add_value(3);
    bt.add_value(2);
    bt.add_value(10);
    bool ans = bt.find_val(123);
    cout << (ans ? "YES" : "NO") << endl;

    cout << "size of bool " << sizeof(bool) << endl;
}
