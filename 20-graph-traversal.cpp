#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/* 
 *     0
 *    /
 *   1 - 3    7
 *   | / | \ /
 *   2 - 4  5
 *           \
 *            6 - 8
 * 
 * BFS: 0 1 2 3 4 5 6 7 8
 * DFS: 0 1 2 3 4 5 6 8 7
 */

struct Node {
    int val;
    vector<Node*> neighbors;
    bool isVisited;
    int depth;
    Node(int v) {
        val = v;
        isVisited = false;
        depth = 0;
    }
};

typedef vector<Node*> Graph;

void bfs(Graph& g, int start) {
    queue<Node*> q;

    q.push(g[start]);

    while(!q.empty()){
        Node* front = q.front();
        cout << "(" << front->val << "," << front->depth << ") ";

        front->isVisited = true;

        for (size_t i = 0; i < front->neighbors.size(); i++){
            Node* neighbor = front->neighbors[i];
            if (!neighbor->isVisited) {
                neighbor->isVisited = true;
                neighbor->depth = front->depth + 1;
                q.push(neighbor);
            }
        }
        q.pop();
    }
}

void dfs(Graph& g, Node* node, int depth = 0) {
    if (node->isVisited) return;
    node->depth = depth;

    node->isVisited = true;
    cout << "(" << node->val << "," << node->depth << ") ";
    for (size_t i = 0; i < node->neighbors.size(); i++) {
        Node* neighbor = node->neighbors[i];
        if (!neighbor->isVisited) {
            dfs(g, neighbor, depth + 1);
        }

    }

    

}


int main(int argc, char* argv[])
{
    Graph graph;
    graph.push_back(new Node(0));
    graph.push_back(new Node(1));
    graph.push_back(new Node(2));
    graph.push_back(new Node(3));
    graph.push_back(new Node(4));
    graph.push_back(new Node(5));
    graph.push_back(new Node(6));
    graph.push_back(new Node(7));
    graph.push_back(new Node(8));

    graph[0]->neighbors.push_back(graph[1]);
    graph[1]->neighbors.push_back(graph[0]);
    graph[1]->neighbors.push_back(graph[2]);
    graph[1]->neighbors.push_back(graph[3]);
    graph[2]->neighbors.push_back(graph[1]);
    graph[2]->neighbors.push_back(graph[3]);
    graph[2]->neighbors.push_back(graph[4]);
    graph[3]->neighbors.push_back(graph[1]);
    graph[3]->neighbors.push_back(graph[2]);
    graph[3]->neighbors.push_back(graph[4]);
    graph[3]->neighbors.push_back(graph[5]);
    graph[4]->neighbors.push_back(graph[2]);
    graph[4]->neighbors.push_back(graph[3]);
    graph[5]->neighbors.push_back(graph[3]);
    graph[5]->neighbors.push_back(graph[6]);
    graph[5]->neighbors.push_back(graph[7]);
    graph[6]->neighbors.push_back(graph[5]);
    graph[6]->neighbors.push_back(graph[8]);
    graph[7]->neighbors.push_back(graph[5]);
    graph[8]->neighbors.push_back(graph[6]);

    for (size_t i = 0; i < graph.size(); i++) {
        graph[i]->depth = 0;
        graph[i]->isVisited = false;
    }

    cout << "BFS:";
    bfs(graph, 0);
    cout << endl;


    for (size_t i = 0; i < graph.size(); i++) {
        graph[i]->depth = 0;
        graph[i]->isVisited = false;
    }

    cout << "DFS:";
    dfs(graph, graph[0]);
    cout << endl;


    for (size_t i = 0; i < graph.size(); i++) {
        delete graph[i];
    }

    return 0;
}