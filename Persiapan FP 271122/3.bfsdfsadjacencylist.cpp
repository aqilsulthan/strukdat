#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; // No. of vertices
	vector<list<int>> adj;
	void printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index);
public:
	Graph(int V); // Constructor
    bool pathExist;
	map<int, bool> visited;
	void addEdge(int v, int w);
    void printAllPaths(int v1, int v2);
	void BFS(int s);
	void DFS(int v);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index) 
{ 
    // Mark the current node as visited and store it in path[] 
    visited[v1] = true;
    path[index]=v1;
    index++;
    // If current vertex is same as v2, then print 
	// current path[] 
    if(v1==v2){
        int i;
        if(!pathExist)
            cout<<"-Following are the paths between "<<path[0]<<" and "<<path[index-1]<<" (DFS)" << endl;
        pathExist=true;
        for(i=0;i<index-1;i++)
            cout<< "V" <<path[i]<<" ";
        cout<<path[i]<<endl;
    }
    else{ // If current vertex is not v2 
    // Recur for all the vertices adjacent 
    // to this vertex 
        list<int>::iterator i; 
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, v2, visited, path, index); 
    }
    // Remove current vertex from path[] and mark it as unvisited 
    index--;
    visited[v1]=false;
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive prinAllPathsUtil 
void Graph::printAllPaths(int v1, int v2) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
        
    // Create an array to store paths 
    int *path = new int[V];
    
    // Initialize path[] as empty 
    int index = 0;
    
    pathExist=false;
    
    // Call the recursive helper function to print all paths 
    printAllPathsUtil(v1,v2,visited,path,index);
    
   
} 

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V,false);

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << "V" << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << "V" << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main()
{
	Graph g(20);
    g.addEdge(0, 19);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 14);
    g.addEdge(7, 6);
    g.addEdge(7, 8);
    g.addEdge(8, 7);
    g.addEdge(8, 9);
    g.addEdge(9, 8);
    g.addEdge(9, 10);
    g.addEdge(10, 9);
    g.addEdge(10, 11);
    g.addEdge(11, 10);
    g.addEdge(11, 12);
    g.addEdge(12, 11);
    g.addEdge(12, 13);
    g.addEdge(13, 12);
    g.addEdge(13, 14);
    g.addEdge(14, 6);
    g.addEdge(14, 13);
    g.addEdge(14, 15);
    g.addEdge(15, 14);
    g.addEdge(15, 16);
    g.addEdge(16, 15);
    g.addEdge(16, 17);
    g.addEdge(17, 16);
    g.addEdge(17, 18);
    g.addEdge(18, 17);
    g.addEdge(18, 19);
    g.addEdge(19, 18);
    g.addEdge(19, 0);

	cout << "-Following is BFS Adjacency List"
		<< "(starting from vertex V0) \n";
	g.BFS(0);

	cout << "-Following is DFS Adjecency List"
            " (starting from vertex V0) \n";
    g.DFS(0);
    
    int v1=0, v2=6;
	g.printAllPaths(v1,v2);
	if(!g.pathExist){
	    cout<<"There is no path exist between "<<v1<<" and "<<v2;
	}

	return 0;
}

