//
// Created by yousefbahr on 5/13/24.
//
#include "Item.h"
#ifndef DATA_STRUCTURE_ASSIGN_2_AVLTREE_H
#define DATA_STRUCTURE_ASSIGN_2_AVLTREE_H

class AVLNode{
    private:

    public:
    AVLNode *left, *right;
    Item data;

    AVLNode(Item data);

};

class AVLTree {
    private:
        AVLNode *root;
        int get_height(AVLNode* node);
        // Balance tree by single or double rotations
        void balance();
        AVLNode* left_rotate(AVLNode* node);
        AVLNode* right_rotate(AVLNode* node);
        AVLNode* add_by_price(AVLNode* node, Item item);
        AVLNode* add_by_category(AVLNode* node, Item item);
        AVLNode* remove(AVLNode* node, Item item);
        void print(AVLNode* node);

public:
        AVLNode* search(Item& item);
        AVLTree();
        void clear();
        bool isEmpty();
        void insert_by_price(Item item);
        void insert_by_category(Item item);
        void pop(Item item);
        void traverse();

};


#endif //DATA_STRUCTURE_ASSIGN_2_AVLTREE_H
