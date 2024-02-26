/**
* Title: Binary Search Trees
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 2
* Description : contains the BST implementation
*/
#include "BST.h"
#include <iostream>


BST::BST() {
    this->root = nullptr;
}

BST::~BST() {
    while(root != nullptr) {
        this->deleteItem(root->value);
    }
}

void BST::insertItem(int key) {
    if(this->root == nullptr) {
        this->root = new BSTNode(key, 1, nullptr, nullptr);
    } else {
        this->root->insert(key);
    }
}

void BST::deleteItem(int key) {
    this->remove(root, key);
}

int* BST::inorderTraversal(int& length) const{
    length = getNodeCount();
    int* arr = new int[length];
    int index = 0;
    inorderTraversalHelper(this->root, index, arr);
    return arr;
}

bool BST::hasSequence(int* seq, int length) const{
    int a = 0;
    std::cout << "Has sequence traversals: ";
    hasSequenceHelper(root, seq, length, a);
    std::cout << std::endl;
    return a == length;
}

int* BST::inorderTraversalHelper(BSTNode* node, int& index, int* arr) const{
    if(node != nullptr) {
        inorderTraversalHelper(node->leftNode, index, arr);
        for(int i = 0; i < node->count; i++) {
            arr[index] = node->value;
            index++;
        }
        inorderTraversalHelper(node->rightNode, index, arr);
    }
}

bool BST::hasSequenceHelper(BSTNode* node, int* seq, int length, int &index) const{
    if(node != nullptr && index < length) {
        if(node->value > seq[index]) {
            std::cout << node->value << ", ";
            hasSequenceHelper(node->leftNode, seq, length, index);
            if(index < length && node->value == seq[index]) {
                index++;
                std::cout << node->value << ", ";
                hasSequenceHelper2(node->rightNode, seq, length, index);
            } else if(index < length) {
                index = length + 1;
            }
        } else if(node->value == seq[index]) {
            index++;
            std::cout << node->value << ", ";
            hasSequenceHelper2(node->rightNode, seq, length, index);
        } else {
            std::cout << node->value << ", ";
            hasSequenceHelper(node->rightNode, seq, length, index);
        }
    }
}

void BST::hasSequenceHelper2(BSTNode* node, int* seq, int length, int &index) const {
    if(node != nullptr && index < length) {
        std::cout << node->value << ", ";
        hasSequenceHelper2(node->leftNode, seq, length, index);
        if(index < length && seq[index] == node->value) {
            index++;
            hasSequenceHelper2(node->rightNode, seq, length, index);
        } else if(index < length) {
            index = length + 1;
        }
    }
}

void BST::remove(BSTNode *&node, int key) {
    if(node->value == key) {
        if(node->count > 1) {
            node->count--;
        } else {
            this->removeItem(node);
        }
    } else if(node->value < key) {
        if(node->rightNode == nullptr) {
            return;
        } else {
            this->remove(node->rightNode, key);
        }
    } else {
        if(node->leftNode == nullptr) {
            return;
        } else {
            this->remove(node->leftNode, key);
        }
    }
}

void BST::removeItem(BSTNode *&node) {
    if(node->leftNode == nullptr && node->rightNode == nullptr) {
        delete node;
        node = nullptr;
    } else if(node->leftNode == nullptr) {
        BSTNode* temp = node;
        node = node->rightNode;
        temp->rightNode = nullptr;
        delete temp;
        temp = nullptr;
    } else if(node->rightNode == nullptr) {
        BSTNode* temp = node;
        node = node->leftNode;
        temp->leftNode = nullptr;
        delete temp;
        temp = nullptr;
    } else {
        int replace = findLeftest(node->rightNode);
        node->value = replace;
    }
}

int BST::findLeftest(BSTNode *&node) {
    if(node->leftNode == nullptr) {
        //BSTNode temp(node->value, node->count, node->leftNode, node->rightNode);
        int replace = node->value;

        BSTNode* del = node;
        node = node->rightNode;
        del->rightNode = nullptr;
        delete del; 
        del = nullptr;
        return replace;
    } else {
        return findLeftest(node->leftNode);
    }
}

void BST::setRootItem(int item) {

}

bool BST::isEmpty() const{
    if(root == nullptr) {
        return true;
    } else {
        return false;
    }
}

void BST::empty() {
    if(this->root == nullptr) {
        return;
    } else {
        helperEmpty(root->leftNode);
        helperEmpty(root->rightNode);
        delete root;
        root = nullptr;
    }
}

void BST::helperEmpty(BSTNode* node) {
    if(node == nullptr) {
        return;
    } else {
        helperEmpty(node->leftNode);
        helperEmpty(node->rightNode);
        delete node;
        node = nullptr;
    }
}

int BST::getNodeCount() const{
    if(this->isEmpty() == false) {
        int count = 0;
        nodeCountHelper(this->root, count);
        return count;
    }
    return 0;
}

void BST::nodeCountHelper(BSTNode* node, int& count) const {
    if(node == nullptr) { 
        return; 
    } else {
        count++;
        nodeCountHelper(node->leftNode, count);
        nodeCountHelper(node->rightNode, count);
    }
}