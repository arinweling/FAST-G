#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>
using namespace std;

struct Edge {
    int to;
    int capacity;
    int flow;
};
int V;


bool bfs(vector<vector<Edge>>& adjList, int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const Edge& edge : adjList[u]) {
            int v = edge.to;
            if (!visited[v] && edge.capacity > edge.flow) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<Edge>>& adjList, int s, int t) {
    vector<vector<Edge>> residualGraph = adjList;
    int parent[V];
    int maxFlow = 0;

    while (bfs(residualGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            for (Edge& edge : residualGraph[u]) {
                if (edge.to == v) {
                    pathFlow = min(pathFlow, edge.capacity - edge.flow);
                    break;
                }
            }
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            for (Edge& edge : residualGraph[u]) {
                if (edge.to == v) {
                    edge.flow += pathFlow;
                    for (Edge& revEdge : residualGraph[v]) {
                        if (revEdge.to == u) {
                            revEdge.flow -= pathFlow;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    cout<<"Enter number of vertices: ";
    
    cin>>V;
    vector<vector<Edge>> adjList(V);
    
    string answer="Y";
    while(answer=="Y"){
        
        
        cout<<"Enter vertex1,vertex2 and flow capacity\n";
        int vertex1,vertex2,flow_capacity;
        cin>>vertex1;
        cin>>vertex2;
        cin>>flow_capacity;
        adjList[vertex1].push_back({vertex2,flow_capacity,0});
        cout<<"Enter new edge?(Y/N)";
        cin>>answer;
        

    }
    cout<<"Enter source and sink: ";
    int source,sink;
    cin>>source;
    cin>>sink;
    int maxFlowValue = fordFulkerson(adjList, source, sink);

    cout << "Max Flow: " << maxFlowValue << endl;

    return 0;
}
