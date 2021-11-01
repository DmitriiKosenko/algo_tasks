/*
Условие: Определить, является ли бинарное дерево деревом поиска
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include <cassert>

using namespace std;

typedef struct Node Node;
struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* init(vector<int> array) {
    
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();
    Node* node6 = new Node();
    Node* node7 = new Node();
    Node* node8 = new Node();
    Node* node9 = new Node();
    Node* node10 = new Node();
    
    node1->value = 20;
    node2->value = 15;
    node3->value = 7;
    node4->value = 17;
    node5->value = 5;
    node6->value = 10;
    node7->value = 16;
    node8->value = 18;
    node9->value = 9; // 2
    node10->value = 12;
    
    node1->left = node2;
    node2->left = node3;
    node2->right = node4;
    node3->left = node5;
    node3->right = node6;
    node5->left = node9;
    node6->right = node10;
    node4->left = node7;
    node4->right = node8;

    return node1;
}

void to_array(Node* node, vector<Node*>& v) {
    if (node->left != NULL) to_array(node->left, v);
    if (node->right != NULL) to_array(node->right, v);
    v.push_back(node);
}

bool is_search_tree(Node* node) {
    if (node->left == NULL && node->right == NULL) return true;
    
    if (node->left != NULL) {
        if (! is_search_tree(node->left)) return false;
        vector<Node*> v_left;
        to_array(node->left, v_left);
        for (unsigned int i = 0; i < v_left.size(); i++) {
            if (v_left[i]->value >= node->value) return false;
        }
    }
    if (node->right != NULL) {
        if (! is_search_tree(node->right)) return false;
        vector<Node*> v_right;
        to_array(node->right, v_right);
        for (unsigned int i = 0; i < v_right.size(); i++) {
            if (v_right[i]->value <= node->value) return false;
        }
    }
    
    return true;
}

bool get_and_check_tree_range(const Node *root, int *lo, int *hi) {
    assert(root != NULL && lo != NULL && hi != NULL);

    *lo = *hi = root->value;

    if (root->left != NULL) {
        int left_lo, left_hi;
        if (!get_and_check_tree_range(root->left, &left_lo, &left_hi)) return false;

        assert(left_lo <= left_hi);
        if (left_hi > root->value) return false;

        *lo = left_lo;
    }

    if (root->right != NULL) {
        int right_lo, right_hi;
        if (!get_and_check_tree_range(root->right, &right_lo, &right_hi)) return false;

        assert(right_lo <= right_hi);
        if (right_lo < root->value) return false;

        *hi = right_hi;
    }

    return true;
}

int main() {

    Node* root = init({});
    
    // cout << (is_search_tree(root) ? "true" : "false") << endl;
    int full_lo, full_hi;
    cout << (get_and_check_tree_range(root, &full_lo, &full_hi) ? "true" : "false") << endl;
    // cout << full_lo << " : " << full_hi << endl;

    return 0;
}