#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V; 
    vector<list<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }

    void removeEdge(int u, int v) {
        adjList[u].remove(v);
        adjList[v].remove(u); 
    }

    void addVertex() {
        adjList.push_back(list<int>()); 
        V++;
    }

    void removeVertex(int vertex) {
        for (int i = 0; i < V; i++) {
            adjList[i].remove(vertex); 
        }
        adjList.erase(adjList.begin() + vertex); 
        V--;
    }

    bool isAdjacent(int u, int v) {
        for (int neighbor : adjList[u]) {
            if (neighbor == v) {
                return true;
            }
        }
        return false;
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Simpul " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Graph awal:\n";
    g.printGraph();

    cout << "\nApakah simpul 1 dan 3 bertetangga? " << (g.isAdjacent(1, 3) ? "Ya" : "Tidak") << endl;

    g.addVertex();
    g.addEdge(5, 0);
    cout << "\nGraph setelah menambah simpul 5:\n";
    g.printGraph();

    g.removeEdge(1, 3);
    cout << "\nGraph setelah menghapus busur antara simpul 1 dan 3:\n";
    g.printGraph();

    g.removeVertex(4);
    cout << "\nGraph setelah menghapus simpul 4:\n";
    g.printGraph();

    return 0;
}
