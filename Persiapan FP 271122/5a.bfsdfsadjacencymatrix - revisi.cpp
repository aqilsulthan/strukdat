#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void addEdge(int x,int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void bfs(int start)
{
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);

	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		cout <<"(V" << vis <<") "<< endl;
		q.erase(q.begin());

		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push_back(i);

				// Set
				visited[i] = true;
			}
		}
	}
}

// function to perform DFS on the graph
void dfs(int start, vector<bool>& visited)
{
 
    // Print the current node
    cout << start << " ";
 
    // Set current node as visited
    visited[start] = true;
 
    // For every node of the graph
    for (int i = 0; i < adj[start].size(); i++) {
 
        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i])) {
            dfs(i, visited);
        }
    }
}

// Driver code
int main()
{
// number of vertices
int v = 20;

// number of edges
	int e = 40;

// adjacency matrix
adj= vector<vector<int>>(v,vector<int>(v,0));

    addEdge(0, 19);
    addEdge(0, 1);
    addEdge(1, 0);
    addEdge(1, 2);
    addEdge(2, 1);
    addEdge(2, 3);
    addEdge(3, 2);
    addEdge(3, 4);
    addEdge(4, 3);
    addEdge(4, 5);
    addEdge(5, 4);
    addEdge(5, 6);
    addEdge(6, 5);
    addEdge(6, 7);
    addEdge(6, 14);
    addEdge(7, 6);
    addEdge(7, 8);
    addEdge(8, 7);
    addEdge(8, 9);
    addEdge(9, 8);
    addEdge(9, 10);
    addEdge(10, 9);
    addEdge(10, 11);
    addEdge(11, 10);
    addEdge(11, 12);
    addEdge(12, 11);
    addEdge(12, 13);
    addEdge(13, 12);
    addEdge(13, 14);
    addEdge(14, 6);
    addEdge(14, 13);
    addEdge(14, 15);
    addEdge(15, 14);
    addEdge(15, 16);
    addEdge(16, 15);
    addEdge(16, 17);
    addEdge(17, 16);
    addEdge(17, 18);
    addEdge(18, 17);
    addEdge(18, 19);
    addEdge(19, 18);
    addEdge(19, 0);
    cout << "Following is BFS Adjacency Matrix "
		<< "(starting from vertex V0) \n";
// perform bfs on the graph
	bfs(0);
	
	vector<bool> visited(v, false);
 
    // Perform DFS
    dfs(0, visited);
}

