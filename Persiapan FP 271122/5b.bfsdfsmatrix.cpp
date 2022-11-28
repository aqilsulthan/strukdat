#include<iostream>
#include <list>
using namespace std;
int *v, *adj, adj_count=0;

class Graph {

private:
      int counts;
public:
      int** matrix;
      Graph(int counts)
       {
          this->counts = counts;
          matrix = new int*[counts];
          for (int i = 0; i < counts; i++)
            {
                matrix[i] = new int[counts];
                for (int j = 0; j < counts; j++)
                    matrix[i][j] = 0;
            }
      }
      void addEdge(int i, int j)
      {
            if (i >= 0 && i < counts && j > 0 && j < counts) {
                  matrix[i][j] = 1;
                  matrix[j][i] = 1;
            }
      }
      void removeEdge(int i, int j)
      {
            if (i >= 0 && i < counts && j > 0 && j < counts) {
                  matrix[i][j] = 0;
                  matrix[j][i] = 0;
            }

      }
      bool isEdge(int i, int j) {
            if (i >= 0 && i < counts && j > 0 && j < counts)
                  return matrix[i][j];
            else
                  return false;
      }
      int getCounts()
      {
          return counts;
      }
};

void DFS(int i, Graph g)
{
    int counts;
    counts = g.getCounts();
    cout << "V" << i << " ";
    v[i] = 1;
    for(int j=0; j<counts;j++)
    {
        if(v[j]==0 && g.matrix[i][j]==1)
            DFS(j, g);
    }


}

void BFS(int start, Graph g)
{
    int counts;
    counts = g.getCounts();
    v[start] = 1;
    for(int j=0; j<counts;j++)
    {
        if(v[j]==0 && g.matrix[start][j]==1)
        {
            adj[adj_count++] = j;
            DFS(j, g);
        }
    }
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

    v=new int[g.getCounts()];
    for (int i=0; i<g.getCounts(); i++)
    {
        v[i]=0;
    }

    cout << "Following is DFS Adjacency Matrix"
		<< "(starting from vertex V0)"<<endl;
    DFS(0, g);

    adj = new int[100];
    for (int i=0; i<g.getCounts(); i++)
    {
        v[i]=0;
    }

    cout << "Following is BFS Adjacency Matrix"
		<< "(starting from vertex V0)"<<endl;
    BFS(0, g);
    for(int i=0; i<adj_count; i++)
    {
        cout << "V" << adj[i] << " " ;
    }
}
