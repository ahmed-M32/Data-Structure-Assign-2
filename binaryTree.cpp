#include <bits/stdc++.h>
using namespace std;
#include "Item.h"

class binarytree {
private:
    binarytree* left;
    binarytree* right;
    binarytree* root;

public:
    Item data;

    binarytree(Item it) : left(nullptr), right(nullptr), data(it), root(nullptr) {}

    binarytree* add_item(Item it) {
        if (it < data) {
            if (!left)
                left = new binarytree(it);
            else
                left = left->add_item(it);
        } else if (it > data) {
            if (!right)
                right = new binarytree(it);
            else
                right = right->add_item(it);
        }
        return this;
    }

    void insert(Item it) {
        binarytree *new_root = add_item(it);
        root = new_root;
    }


    binarytree* delete_item( Item target, binarytree* node) {
        if (!node)
            return nullptr;

        if (target < node->data)
            node->left = delete_item(target, node->left);
        else if (target > node->data)
            node->right = delete_item(target, node->right);
        else {
            binarytree* tmp = node;

            if (!node->left && !node->right) {
                node = nullptr;
            } else if (!node->right) {
                node = node->left;
            } else if (!node->left) {
                node = node->right;
            } else {
                binarytree* cur = node->right;
                while (cur && cur->left)
                    cur = cur->left;

                node->data = cur->data;
                node->right = delete_item(cur->data, node->right);
                tmp = nullptr;
            }
            if (tmp)
                delete tmp;
        }
        return node;
    }

    void pop(Item item)
    {
        binarytree *new_root = delete_item(item, root);
        root = new_root;
    }


    void print_nameascending() {
//        sort(sorted.begin(), sorted.end(), [](const item& a, const item& b) {
//            return a.itemname < b.itemname;
//        });
//        for (const auto& it : sorted) {
//            cout << it << endl;
//        }
        if (root == nullptr)
            return;

        stack<binarytree*> s;
        vector<Item> result;
        binarytree* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left; 
            }
            current = s.top();
            s.pop();
            result.push_back(current->data);
            current = current->right;
        }
        sort(result.begin(), result.end(), [](const Item &a, const Item &b){return a.itemName < b.itemName;} );
        for( auto i: result)
            i.print();

    }

    void print_namedescending() {
//        sort(sorted.begin(), sorted.end(), [](const item& a, const item& b) {
//            return a.itemname > b.itemname;
//        });
//        for (const auto& it : sorted) {
//            cout << it << endl;
//        }

        if (root == nullptr)
            return;

        stack<binarytree*> s;
        vector<Item> result;
        binarytree* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->data);
            current = current->right;
        }
        sort(result.begin(), result.end(), [](const Item &a, const Item &b){return a.itemName > b.itemName;} );
        for( auto i: result)
            i.print();

    }

    void print_prices_ascending() {
        if (left)
            left->print_prices_ascending();
        data.print();
        if (right)
            right->print_prices_ascending();
    }

    void print_prices_descending()  {
        if (right)
            right->print_prices_descending();
        data.print();
        if (left)
            left->print_prices_descending();
    }
};
