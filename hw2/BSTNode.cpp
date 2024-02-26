/**
* Title: Binary Search Trees
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 2
* Description : contains the BSTNode implementation
*/
#include "BSTNode.h"
#include <algorithm>

BSTNode::BSTNode() {
    this->value = 0; 
    this->count = 0;
    this->leftNode = nullptr;
    this->rightNode = nullptr;
}

BSTNode::BSTNode(BSTNode& node) {
    this->value = node.value;
    this->count = node.count;
    this->leftNode = node.leftNode;
    this->rightNode = node.rightNode;
}

BSTNode::BSTNode(const int item, int count, BSTNode* left, BSTNode* right) {
    this->value = item;
    this->count = count;
    this->leftNode = left;
    this->rightNode = right;
}

BSTNode* BSTNode::getLeft() {
    return this->leftNode;
}

BSTNode* BSTNode::getRight() {
    return this->rightNode;
}   

void BSTNode::setLeft(BSTNode* node) {
    this->leftNode = node;
}

void BSTNode::setRight(BSTNode* node) {
    this->rightNode = node;
}

void BSTNode::setItem(int item) {
    this->value = item;
}

int BSTNode::getItem() {
    return this->value;
}

int BSTNode::getCount() {
    return count;
}

void BSTNode::addToCount(int i) {
    this->count = this->count + i;
}

void BSTNode::insert(int key) {
    if(this->value == key) {
        this->count++;
    } else if(this->value < key) {
        if(this->rightNode != nullptr) {
            this->rightNode->insert(key);
        } else {
            this->rightNode = new BSTNode(key, 1);
        }
        
    } else {
        if(this->leftNode != nullptr) {
            this->leftNode->insert(key);
        } else {
            this->leftNode = new BSTNode(key, 1);
        }
    }
}

bool BSTNode::remove(int key) {
    if(this->value == key) {
        if(this->count > 1) {
            this->count--;
        } else {
            removeHelper(this);
        }
    } else if(this->value < key) {
        if(this->rightNode == nullptr) {
            return false;
        } else {
            this->rightNode->remove(key);
        }
    } else {
        if(this->leftNode == nullptr) {
            return false;
        } else {
            this->leftNode->remove(key);
        }
    }
    return true;
}

void BSTNode::removeHelper(BSTNode* node) {
    if(node->leftNode == nullptr && node->rightNode == nullptr) {
        delete node;
        node = nullptr;
    } else if(node->rightNode == nullptr) {
        BSTNode* tempNode = node;
        node = node->leftNode;
        tempNode->leftNode = nullptr;
        delete tempNode;
    } else if(node->leftNode == nullptr) {
        BSTNode* tempNode = node;
        node = node->rightNode;
        tempNode->rightNode = nullptr;
        delete tempNode;
    } else {
        int replace = findLeftest(node->rightNode);
        node->value = replace;
    }
}

int BSTNode::findLeftest(BSTNode* node) {
    if(node->leftNode == nullptr) {
        //BSTNode temp(node->value, node->count);
        int replace = node->value;

        BSTNode* del = node;
        node = node->rightNode;
        del->rightNode = nullptr;
        delete del; 
        
        return replace;
    } else {
        findLeftest(node->leftNode);
        return 0;
    }
}

int BSTNode::getLength() {
    return 1 + std::max(helperLength(this->leftNode), helperLength(this->rightNode));
}

int BSTNode::helperLength(BSTNode* node) {
    if(node == nullptr) {
        return 0;
    }
    return 1 + std::max(helperLength(this->leftNode), helperLength(this->rightNode));
}

void BSTNode::inorderTraversal(BSTNode* node, int &index, int* arr) {
    if(node != nullptr) {
        inorderTraversal(node->leftNode, index, arr);
        for(int i = 0; i < node->count; i++) {
            arr[index] = node->value;
            index++;
        }
        inorderTraversal(node->rightNode, index, arr);
    }
}

BSTNode& BSTNode::operator=(const BSTNode& node) {
    this->value = node.value;
    this->count = node.count;
    this->leftNode = node.leftNode;
    this->rightNode = node.rightNode;
    return *this;
}