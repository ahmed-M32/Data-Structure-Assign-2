#include <bits/stdc++.h>
using namespace std;

struct item {
    string itemname;
    string category;
    int price;

    item(const string& itemname, const string& category, int price)
        : itemname(itemname), category(category), price(price) {}
};

ostream& operator<<(ostream& os, const item& it) {
    os << "Item Name: " << it.itemname << ", Category: " << it.category << ", Price: " << it.price;
    return os;
}

class binarytree {
private:
    binarytree* left;
    binarytree* right;
    item data;
    vector<item> sorted;

public:
    binarytree(const item& it) : left(nullptr), right(nullptr), data(it) {}

    binarytree* add_item(const item& it) {
        sorted.push_back(it);
        if (it.price < data.price) {
            if (!left)
                left = new binarytree(it);
            else
                left = left->add_item(it);
        } else if (it.price > data.price) {
            if (!right)
                right = new binarytree(it);
            else
                right = right->add_item(it);
        }
        return this;
    }

    void print_normal() const {
        for (const auto& it : sorted) {
            cout << it << endl;
        }
    }

    binarytree* delete_item(const item& target, binarytree* node) {
        if (!node)
            return nullptr;

        if (target.price < node->data.price)
            node->left = delete_item(target, node->left);
        else if (target.price > node->data.price)
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

    void print_nameascending() {
        sort(sorted.begin(), sorted.end(), [](const item& a, const item& b) {
            return a.itemname < b.itemname;
        });
        for (const auto& it : sorted) {
            cout << it << endl;
        }
    }

    void print_namedescending() {
        sort(sorted.begin(), sorted.end(), [](const item& a, const item& b) {
            return a.itemname > b.itemname;
        });
        for (const auto& it : sorted) {
            cout << it << endl;
        }
    }

    void print_prices_ascending() {
        if (left)
            left->print_prices_ascending();
        cout << data << endl;
        if (right)
            right->print_prices_ascending();
    }

    void print_prices_descending() {
        if (right)
            right->print_prices_descending();
        cout << data << endl;
        if (left)
            left->print_prices_descending();
    }
};

int main() {
    binarytree* tree = new binarytree(item("Item1", "CategoryA", 10));
    tree->add_item(item("Item2", "CategoryB", 5));
    tree->add_item(item("Item3", "CategoryA", 15));
    tree->add_item(item("Item4", "CategoryB", 7));
    tree->add_item(item("Item5", "CategoryC", 20));

    cout << "Normal Order:" << endl;
    tree->print_normal();

    cout << "\nItems in Ascending Order of Names:" << endl;
    tree->print_nameascending();

    cout << "\nItems in Descending Order of Names:" << endl;
    tree->print_namedescending();

    cout << "\nItems in Ascending Order of Prices:" << endl;
    tree->print_prices_ascending();

    cout << "\nItems in Descending Order of Prices:" << endl;
    tree->print_prices_descending();

    tree = tree->delete_item(item("Item4", "CategoryB", 7), tree);

    cout << "\nAfter Deleting Item4 (Price 7):" << endl;
    cout << "Items in Ascending Order of Prices:" << endl;
    tree->print_prices_ascending();
    delete tree;

    return 0;
}
