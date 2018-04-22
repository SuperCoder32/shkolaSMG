//Hackerrank: Kruskal

#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

const int MAXN = 3000;
Edge edges[5000000];
int tree[MAXN];

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}


int nodes, edgesCount;
int treeOf(int node) {
    if (tree[node] == node) {
        return node;
    }

    tree[node] = treeOf(tree[node]);
    return tree[node];
}

void mergeTrees(int nodeA, int nodeB) {
    int aRoot = treeOf(nodeA);
    int bRoot = treeOf(nodeB);

    if (aRoot > bRoot) {
        swap(aRoot, bRoot);
    }

    tree[aRoot] = bRoot;
}

int main() {
    cin >> nodes >> edgesCount;
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].from;
        cin >> edges[i].to;
        cin >> edges[i].weight;
    }

    sort(edges, edges + edgesCount, &comp);
    for (int i = 1; i <= nodes; i++) {
        tree[i] = i;
    }


    int pathWeight = 0;
    int from, to, weight;

    for (int minIndex = 0; minIndex < edgesCount; minIndex++) {
        from = edges[minIndex].from;
        to = edges[minIndex].to;
        weight = edges[minIndex].weight;

        if (treeOf(from) != treeOf(to)) {
            mergeTrees(from, to);
            pathWeight += weight;
        }
    }


    cout << pathWeight;

    return 0;
}
