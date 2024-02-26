/**
* Title: Binary Search Trees
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 2
* Description : contains the BSTNode header
*/
#pragma once
class BST;

class BSTNode {
    
    public:
        BSTNode();
        BSTNode(BSTNode& node);
        BSTNode(const int item, int count, BSTNode* left = nullptr, BSTNode* right = nullptr);
        BSTNode* getLeft();
        BSTNode* getRight();
        void setLeft(BSTNode* node);
        void setRight(BSTNode* node);

        void setItem(int item);
        int getItem();
        int getCount();
        void addToCount(int i);
        void insert(int key);
        bool remove(int key);
        void removeHelper(BSTNode* node);
        int findLeftest(BSTNode* node);
        int getLength();
        int helperLength(BSTNode* node);
        void inorderTraversal(BSTNode* node, int &index, int* arr);
        BSTNode& operator=(const BSTNode& node);
    private:
        int value;
        int count;
        BSTNode* leftNode;
        BSTNode* rightNode;
        friend class BST;
};

//#include "BSTNode.cpp"
