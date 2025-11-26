#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
  int size;
  vector<vector<int>> adj_matrix;
  vector<char> nodes;

public:
  Graph(int n = 0) : size(n), adj_matrix(n, vector<int>(n, 0)), nodes(n, ' ') {}

  void addEdge(int u, int v)
  {
    if (u >= 0 && u < size && v >= 0 && v < size)
    {
      adj_matrix[u][v] = 1;
      adj_matrix[v][u] = 1;
    }
  }

  void addNode(int vertex, char data)
  {
    if (vertex >= 0 and vertex < size)
    {
      nodes[vertex] = data;
    }
  }

  void display()
  {
    for (size_t i = 0; i < size; i++)
    {
      cout << nodes[i] << ": ";
      for (size_t j = 0; j < size; j++)
      {
        if (adj_matrix[i][j])
        {
          cout << nodes[j] << " ";
        }
      }
      cout << endl;
    }
  }
};

int main()
{

  Graph g(4);

  g.addNode(0, 'A');
  g.addNode(1, 'B');
  g.addNode(2, 'C');
  g.addNode(3, 'D');

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 2);

  g.display();

  return 0;
}