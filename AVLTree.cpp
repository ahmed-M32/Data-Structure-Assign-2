//
// Created by yousefbahr on 5/13/24.
//
#include "AVLTree.h"
#include "Item.h"

AVLNode::AVLNode(Item data) : data(data) {
    this->right = left = nullptr;
}


AVLTree::AVLTree() {
    this->root = nullptr;
}


void AVLTree::clear() {
    this-> root = nullptr;
}

bool AVLTree::isEmpty() {
    return this->root == nullptr;
}


AVLNode* AVLTree::search(Item& item) {
    // If item exists return it
    // else return node before it
    AVLNode* node = root;
    while(node != nullptr)
    {   //if leaf or the searched for item , break
        if( (node->left == nullptr and node->right == nullptr)
            or node->data == item )
            break;

        else if(node->data < item )
            node = node->right;

        else
            node = node->left;
    }
    return node;
}
int AVLTree::get_height(AVLNode *node) {
    // assuming 'node' exists in the tree
    if(node == nullptr)
        return 0;

    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    return max(left_height, right_height) + 1;
}

AVLNode* AVLTree::right_rotate(AVLNode* node)
{
    AVLNode* y = node->left;
    AVLNode* b = y->right;

    y->right = node;
    node->left = b;

    return y;

}

AVLNode* AVLTree::left_rotate(AVLNode* node)
{
    AVLNode* y = node->right;
    AVLNode* b = y->left;

    y->left = node;
    node->right = b;

    return y;

}

AVLNode* AVLTree::add_by_price(AVLNode* node, Item item){
    // parameter 'node' is the root of the tree
    // function returns the new root of the tree
    if (node == nullptr)
    {
        AVLNode* new_node = new AVLNode(item);
        return new_node;
    }
    if (item < node->data )
        node->left = add_by_price(node->left, item);
    else
        node->right = add_by_price(node->right, item);


    // get balance factor
    int balance_factor = get_height(node->left) - get_height(node->right);

    // Left Left Case
    if (balance_factor > 1 and item < node->left->data)
        return right_rotate(node);

    // Right Right Case
    if (balance_factor < -1 and  item > node->right->data)
        return left_rotate(node);

    // Left Right Case
    if (balance_factor > 1 and item > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance_factor < -1 and item < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void AVLTree::insert_by_price(Item item) {
    AVLNode* new_root = add_by_price(root, item);
    root = new_root;
}

AVLNode* AVLTree::add_by_category(AVLNode* node, Item item){
    // parameter 'node' is the root of the tree
    // function returns the new root of the tree
    if (node == nullptr)
    {
        AVLNode* new_node = new AVLNode(item);
        return new_node;
    }
    if (item < node->data.Category )
        node->left = add_by_category(node->left, item);
    else
        node->right = add_by_category(node->right, item);


    // get balance factor
    int balance_factor = get_height(node->left) - get_height(node->right);

    // Left Left Case
    if (balance_factor > 1 and item < node->left->data.Category)
        return right_rotate(node);

    // Right Right Case
    if (balance_factor < -1 and  item > node->right->data.Category)
        return left_rotate(node);

    // Left Right Case
    if (balance_factor > 1 and item > node->left->data.Category)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance_factor < -1 and item < node->right->data.Category)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void AVLTree::insert_by_category(Item item) {
    AVLNode* new_root = add_by_category(root, item);
    root = new_root;
}

AVLNode* AVLTree::remove(AVLNode* node, Item item){
    // parameter 'node' is the root of the tree
    // 'item' is a leaf
    // function returns the new root of the tree
    // assuming 'item' is already in tree
    if (node->data == item)
    {
        delete node;
        return nullptr;
    }
    else if (item < node->data )
        node->left = remove(node->left, item);
    else
        node->right = remove(node->right, item);


    // get balance factor
    int balance_factor = get_height(node->left) - get_height(node->right);

    // Left Left Case
    if (balance_factor > 1 and item < node->left->data)
        return right_rotate(node);

    // Right Right Case
    if (balance_factor < -1 and  item > node->right->data)
        return left_rotate(node);

    // Left Right Case
    if (balance_factor > 1 and item > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance_factor < -1 and item < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void AVLTree::pop(Item item) {
    AVLNode* new_root = remove(root, item);
    root = new_root;
}

void AVLTree::print(AVLNode* node) {
    if(node == nullptr)
        return;
    print(node->left);
    node->data.print();
    cout << " ";
    print(node->right);
}

void AVLTree::traverse() {
    print(this->root);
}


int main()
{
    AVLTree tree;

}