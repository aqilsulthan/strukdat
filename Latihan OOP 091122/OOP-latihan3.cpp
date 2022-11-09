#include <iostream>
using namespace std;

struct adjNode {
    int val, weight;
    adjNode* next;
};

struct graphEdge {
    int start_vertex, end_vertex, weight;
};
class DiaGraph{
    
    adjNode* getAdjListNode(int value, int weight, adjNode* head)   {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->weight = weight;
         
        newNode->next = head;  
        return newNode;
    }
    int N; 
public:
    adjNode **head;                
    DiaGraph(graphEdge edges[], int n, int N)  {
        
        head = new adjNode*[N]();
        this->N = N;
        
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        
        for (unsigned i = 0; i < n; i++)  {
            int start_vertex = edges[i].start_vertex;
            int end_vertex = edges[i].end_vertex;
            int weight = edges[i].weight;
            
            adjNode* newNode = getAdjListNode(end_vertex, weight, head[start_vertex]);
            head[start_vertex] = newNode;
             }
    }
    DiaGraph() {
	    for (int i = 0; i < N; i++)
	        delete[] head[i];
	        delete[] head;
	     }
};

void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->weight << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    graphEdge edges[] = {
        // (x, y, w) -> start_vertex, end_vertex, weight
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    
    int N = 6;      
    int n = sizeof(edges)/sizeof(edges[0]);
    DiaGraph diagraph(edges, n, N);
    
    cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
    for (int i = 0; i < N; i++)
    {
        display_AdjList(diagraph.head[i], i);
    }
    return 0;
}
