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
int treeId[MAXN];

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}

void printRebro(Edge a) {
    cout << a.from << " ";
    cout << a.to << " ";
    cout << a.weight << "\n";
}

int nodes, edgesCount;
void printNodeTrees() {
    for (int i = 1; i <= nodes; i++) {
        cout << treeId[i] << " ";
    }
    cout << "\n";
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
        treeId[i] = i;
    }

    //cout << "\n";
    //printNodeTrees();
    int pathWeight = 0;
    for (int minIndex = 0; minIndex < edgesCount; minIndex++) {
        if (treeId[edges[minIndex].to] != treeId[edges[minIndex].from]) {
            int originTree = treeId[edges[minIndex].to];

            for (int i = 1; i <= nodes; i++) {
                if (originTree == treeId[i]) {
                    treeId[i] = treeId[edges[minIndex].from];
                }
            }
            //printNodeTrees();

            //printRebro(edges[minIndex]);
            pathWeight += edges[minIndex].weight;
        }
    }
    cout << pathWeight;

    return 0;
}