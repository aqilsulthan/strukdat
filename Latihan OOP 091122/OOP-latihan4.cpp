#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex {
    protected:
        list<int> adj;
    
    public:
        void addEdge(int x, int v){
            if(adj.empty()) adj.push_back(x);
            adj.push_back(v);
        }

        void showList(){
            list<int>::iterator it;
            for(it = adj.begin(); it != adj.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
};

class Graph {
    protected:
        int len;
        Vertex vertex[100];
        

    public:
        Graph(int _len) {
            len = _len;
        }

        AddEdgetoVertex(int x, int y){
            vertex[x].addEdge(x,y);
            vertex[y].addEdge(y,x);
        }

        showAllVertex(){
            for (int i = 0; i < len; i++)
            {
                vertex[i].showList();
            }
            
        }
};


int main(){
    Graph newGraph(5);

    newGraph.AddEdgetoVertex(0, 1);
    newGraph.AddEdgetoVertex(0, 4);
    newGraph.AddEdgetoVertex(1, 2);
    newGraph.AddEdgetoVertex(1, 3);
    newGraph.AddEdgetoVertex(1, 4);
    newGraph.AddEdgetoVertex(2, 3);
    newGraph.AddEdgetoVertex(3, 4);

    newGraph.showAllVertex();
}
