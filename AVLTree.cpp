//
// Created by yousefbahr on 5/13/24.
//
#include "AVLTree.h"
#include "Item.h"

AVLNode::AVLNode(Item data) : data(data)
{
    this->right = left = nullptr;
}

AVLTree::AVLTree()
{
    this->root = nullptr;
}

void AVLTree::clear()
{
    this->root = nullptr;
}

bool AVLTree::isEmpty()
{
    return this->root == nullptr;
}

AVLNode *AVLTree::search(Item &item)
{
    // If item exists return it
    // else return node before it
    AVLNode *node = root;
    while (node != nullptr)
    { // if leaf or the searched for item , break
        if ((node->left == nullptr and node->right == nullptr) or node->data == item)
            break;

        else if (node->data < item)
            node = node->right;

        else
            node = node->left;
    }
    return node;
}
int AVLTree::get_height(AVLNode *node)
{
    // assuming 'node' exists in the tree
    if (node == nullptr)
        return 0;

    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    return max(left_height, right_height) + 1;
}

AVLNode *AVLTree::right_rotate(AVLNode *node)
{
    AVLNode *y = node->left;
    AVLNode *b = y->right;

    y->right = node;
    node->left = b;

    return y;
}

AVLNode *AVLTree::left_rotate(AVLNode *node)
{
    AVLNode *y = node->right;
    AVLNode *b = y->left;

    y->left = node;
    node->right = b;

    return y;
}

AVLNode *AVLTree::add(AVLNode *node, Item item)
{
    // parameter 'node' is the root of the tree
    // function returns the new root of the tree
    if (node == nullptr)
    {
        AVLNode *new_node = new AVLNode(item);
        return new_node;
    }
    if (item < node->data)
        node->left = add(node->left, item);
    else
        node->right = add(node->right, item);

    // get balance factor
    int balance_factor = get_height(node->left) - get_height(node->right);

    // Left Left Case
    if (balance_factor > 1 and item < node->left->data)
        return right_rotate(node);

    // Right Right Case
    if (balance_factor < -1 and item > node->right->data)
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

void AVLTree::insert(Item item)
{
    AVLNode *new_root = add(root, item);
    root = new_root;
}


AVLNode* AVLTree::add_by_name(AVLNode* node, Item item){
    // parameter 'node' is the root of the tree
    // function returns the new root of the tree
    if (node == nullptr)
    {
        AVLNode *new_node = new AVLNode(item);
        return new_node;
    }
    if (item < node->data.itemName)
        node->left = add_by_name(node->left, item);
    else
        node->right = add_by_name(node->right, item);
    if (item < node->data.itemName )
        node->left = add_by_name(node->left, item);
    else
        node->right = add_by_name(node->right, item);


    // get balance factor
    int balance_factor = get_height(node->left) - get_height(node->right);

    // Left Left Case
    if (balance_factor > 1 and item < node->left->data.itemName)
        return right_rotate(node);

    // Right Right Case
    if (balance_factor < -1 and  item > node->right->data.itemName)
        return left_rotate(node);

    // Left Right Case
    if (balance_factor > 1 and item > node->left->data.itemName)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance_factor < -1 and item < node->right->data.itemName)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void AVLTree::insert_by_name(Item item)
{
    AVLNode *new_root = add_by_name(root, item);
    root = new_root;
}


AVLNode *AVLTree::remove(AVLNode *node, Item item)
{
    // parameter 'node' is the root of the tree
    // 'item' is a leaf
    // function returns the new root of the tree
    // assuming 'item' is already in tree
    if (node->data == item)
    {
        delete node;
        return nullptr;
    }
    else if (item < node->data)
        node->left = remove(node->left, item);
    else
        node->right = remove(node->right, item);

    // get balance factor
    int balance_factor = get_height(node->left) - get_height(node->right);

    // Left Left Case
    if (balance_factor > 1 and item < node->left->data)
        return right_rotate(node);

    // Right Right Case
    if (balance_factor < -1 and item > node->right->data)
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

//AVLNode *AVLTree::remove_by_name(AVLNode *node, Item item)
//{
//    // parameter 'node' is the root of the tree
//    // 'item' is a leaf
//    // function returns the new root of the tree
//    // assuming 'item' is already in tree
//    if (node->data == item)
//    {
//        delete node;
//        return nullptr;
//    }
//    else if (item < node->data.itemName)
//        node->left = remove_by_name(node->left, item);
//    else
//        node->right = remove_by_name(node->right, item);
//
//    // get balance factor
//    int balance_factor = get_height(node->left) - get_height(node->right);
//
//    // Left Left Case
//    if (balance_factor > 1 and item < node->left->data.itemName)
//        return right_rotate(node);
//
//    // Right Right Case
//    if (balance_factor < -1 and item > node->right->data.itemName)
//        return left_rotate(node);
//
//    // Left Right Case
//    if (balance_factor > 1 and item > node->left->data.itemName)
//    {
//        node->left = left_rotate(node->left);
//        return right_rotate(node);
//    }
//
//    // Right Left Case
//    if (balance_factor < -1 and item < node->right->data.itemName)
//    {
//        node->right = right_rotate(node->right);
//        return left_rotate(node);
//    }
//
//    return node;
//}

void AVLTree::pop(Item item)
{
    AVLNode *new_root = remove(root, item);
    root = new_root;
}

//void AVLTree::pop_by_name(Item item)
//{
//    AVLNode *new_root = remove_by_name(root, item);
//    root = new_root;
//}
void AVLTree::print_ascend_price(AVLNode *node)
{
    if (node == nullptr)
        return;
    print_ascend_price(node->left);
    node->data.print();
    cout << " ";
    print_ascend_price(node->right);
}

void AVLTree::print_ascend_name()
{
    if (root == nullptr)
        return;

    stack<AVLNode*> s;
    vector<Item> result;
    AVLNode* current = root;

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

void AVLTree::print_descend_name()
{
    if (root == nullptr)
        return;

    stack<AVLNode*> s;
    vector<Item> result;
    AVLNode* current = root;

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

void AVLTree::traverse_ascend_price()
{
    print_ascend_price(this->root);
}

void AVLTree::traverse_ascend_name()
{
     print_ascend_name();
}


void AVLTree::print_descend_price(AVLNode *node)
{
    if (node == nullptr)
        return;
    print_descend_price(node->right);
    node->data.print();
    cout << " ";
    print_descend_price(node->left);
}

void AVLTree::traverse_descend_price()
{
    print_descend_price(this->root);
}

void AVLTree::traverse_descend_name()
{
    print_descend_name();
}

void AVLTree::print_ascend(AVLNode *node)
{
    if (node == nullptr)
        return;
    print_ascend(node->left);
    node->data.print();
    cout << " ";
    print_ascend(node->right);
}

void AVLTree::traverse_ascend()
{
    print_ascend(this->root);
}

void AVLTree::print_descend(AVLNode *node)
{
    if (node == nullptr)
        return;
    print_ascend(node->right);
    node->data.print();
    cout << " ";
    print_ascend(node->left);
}

void AVLTree::traverse_descend()
{
    print_descend(this->root);
}




