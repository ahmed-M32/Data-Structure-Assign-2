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

  
        AVLNode* add(AVLNode* node, Item item);
        AVLNode* remove(AVLNode* node, Item item);
        void print_ascend_price(AVLNode* node);
        void print_ascend_name();
        void print_descend_price(AVLNode* node);
        void print_descend_name();

  

public:
        AVLNode* search(Item& item);
        AVLTree();
        void clear();
        bool isEmpty();

  
        void insert(Item item);
        void pop(Item item);
        void traverse_ascend_name();
        void traverse_descend_name();
        void traverse_ascend_price();
        void traverse_descend_price();

  

};


#endif //DATA_STRUCTURE_ASSIGN_2_AVLTREE_H
