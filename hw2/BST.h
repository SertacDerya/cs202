/**
* Title: Binary Search Trees
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 2
* Description : contains the BST header
*/
#pragma once
#include "BSTNode.h"

class BST {
    
    public:
        BST();
        BST(const BST& tree);//copy const
        ~BST();

        void insertItem(int key);
        void deleteItem(int key);
        int* inorderTraversal(int& length) const;
        bool hasSequence(int* seq, int length) const;

        void setRootItem(int item);
        bool isEmpty() const;
        void empty();
        int getNodeCount() const;

    private:
        int* inorderTraversalHelper(BSTNode* root, int& index, int* arr) const;
        bool hasSequenceHelper(BSTNode* node, int* seq, int length, int &index) const;
        void remove(BSTNode *&node, int key);
        void removeItem(BSTNode *&node);
        int findLeftest(BSTNode *&node);
        void helperEmpty(BSTNode* node);
        void nodeCountHelper(BSTNode* node, int& count) const;

        void hasSequenceHelper2(BSTNode* node, int* seq, int length, int &index) const;

        BSTNode* root;
        friend class BSTNode;
};

//#include "BST.cpp"
