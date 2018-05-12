#include <queue>

queue <int> toExpand;

cin >> neighborsOfNode;

toExpand.push_back(source);
dists.push_back(0);

int currNode, dist = 0;

while (!toExpand.empty()) {
    currNode = toExpand.front();
    toExpand.pop_front();

    currDist = dists.front();
    currDist.pop_front();

    if (currNode == dest) {
        cout << currDist;
        break;
    }

    n = neighborsOfNode[currNode].size();
    for (int i = 0; i < ; i++) {
        currNeighbor = neighborsOfNode[i];
        
        if (!visited[currNeighbor]) {
            toExpand.push_back(currNeighbor);
            dists.push_back(currDist + 1);

            visited[currNeighbor] = true;
        }
    }
}
