#include <bits/stdc++.h>
using namespace std;

// utility function for printing
// the found path in graph
void printpath(vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		cout << path[i] << " ";
	cout << endl;
}

// utility function to check if current
// vertex is already present in path
int isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}

// utility function for finding paths in graph
// from source to destination
void findpaths(vector<vector<int> >& g, int src, int dst,
			int v)
{
	// create a queue which stores
	// the paths
	queue<vector<int> > q;

	// path vector to store the current path
	vector<int> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		// if last vertex is the desired destination
		// then print the path
		if (last == dst)
			printpath(path);

		// traverse to all the nodes connected to
		// current vertex and push new path to queue
		for (int i = 0; i < g[last].size(); i++) {
			if (isNotVisited(g[last][i], path)) {
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}

// driver program
int main()
{
	vector<vector<int> > g;
	// number of vertices
	int v = 20;
	g.resize(20);

	// construct a graph
	g[0].push_back(19);
	g[0].push_back(1);
	g[1].push_back(0);
	g[1].push_back(2);
	g[2].push_back(1);
	g[2].push_back(3);
	g[3].push_back(2);
	g[3].push_back(4);
	g[4].push_back(3);
	g[4].push_back(5);
	g[5].push_back(4);
	g[5].push_back(6);
	g[6].push_back(5);
	g[6].push_back(7);
	g[6].push_back(14);
	g[7].push_back(6);
	g[7].push_back(8);
	g[8].push_back(7);
	g[8].push_back(9);
	g[9].push_back(8);
	g[9].push_back(10);
	g[10].push_back(9);
	g[10].push_back(11);
	g[11].push_back(10);
	g[11].push_back(12);
	g[12].push_back(11);
	g[12].push_back(13);
	g[13].push_back(12);
	g[13].push_back(14);
	g[14].push_back(6);
	g[14].push_back(13);
	g[14].push_back(15);
	g[15].push_back(14);
	g[15].push_back(16);
	g[16].push_back(15);
	g[16].push_back(17);
	g[17].push_back(16);
	g[17].push_back(18);
	g[18].push_back(17);
	g[18].push_back(19);
	g[19].push_back(18);
	g[19].push_back(0);

	int src = 0, dst = 4;
	cout << "Path from src " << src << " to dst " << dst
		<< " are (BFS) \n";

	// function for finding the paths
	findpaths(g, src, dst, v);

	return 0;
}

