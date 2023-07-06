#include<iostream>
#include<queue>

using namespace std;

/* 
 *        60
 *      /    \
 *    20      80
 *   /  \     / \
 *  10  30   70  90
 *      / \
 *     25  50 
 */

struct Node {
    int val;
    int depth;  // optional
    Node *left, *right;

    Node(int v) {
        val = v;
        depth = 0;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(Node* node) {
    if (node == nullptr) return;

    cout << node->val << " ";
    dfs(node->left);
    dfs(node->right);
}

int dfsCount(Node* node) {
    if (node == nullptr) return 0;
    int count = 1;

    count += dfsCount(node->left);
    count += dfsCount(node->right);
    return count;
}

void dfsDepth(Node* node, int depth = 0) {
    if (node == nullptr) return;

    cout << "(" << node->val << ",";
    cout << depth << ") ";
    dfsDepth(node->left, depth + 1);
    dfsDepth(node->right, depth + 1);
}


void bfs(Node* node) {
    if (node == nullptr) return;

    queue<Node*> q;

    q.push(node);

    while(!q.empty()) {
        Node* current = q.front();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        cout << current->val << " ";
        q.pop();
    }
}

void bfsDepth(Node* node) {
    if (node == nullptr) return;

    queue<Node*> q;

    q.push(node);

    while(!q.empty()) {
        Node* current = q.front();
        if (current->left) {
            current->left->depth = current->depth + 1;
            q.push(current->left);
        }
        if (current->right) {
            current->right->depth = current->depth + 1;
            q.push(current->right);
        }
        cout << "(" << current->val << ", ";
        cout << current->depth << ") ";
        q.pop();
    }
}

void bfsLevel(Node* node) {
    if (node == nullptr) return;

    queue<Node*> q;
    q.push(node);
    q.push(nullptr);

    while(!q.empty()) {
        Node* current = q.front();
        if (current == nullptr) {
            cout << " | ";
            q.pop();
            if(!q.empty()) q.push(nullptr);
        } else {
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
            cout << current->val << " ";
            q.pop();
        }

    }
}

    
int main(int argc, char* argv[])
{
    // tree creation
    Node* root = new Node(60);
    root->left = new Node(20);
    root->right = new Node(80);
    root->right->left = new Node(70);
    root->right->right = new Node(90);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->left->right->left = new Node(25);
    root->left->right->right = new Node(50);

    cout << "DFS: ";
    dfs(root);
    cout << endl;

    cout << "DFS - Depth: ";
    dfsDepth(root);
    cout << endl;

    int count = 0;
    cout << "DFS - COUNT: ";
    // dfsCount(root, count);
    cout << dfsCount(root) << endl;

    cout << "BFS: ";
    bfs(root);
    cout << endl;

    cout << "BFS - Depth: ";
    bfsDepth(root);
    cout << endl;

    cout << "BFS - Delimeter: ";
    bfsLevel(root);
    cout << endl;
    

    // tree deletion
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}