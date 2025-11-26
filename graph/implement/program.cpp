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

  void dfs_util(int index, vector<bool> &visited)
  {
    visited[index] = true;
    cout << nodes[index] << " ";

    for (size_t i = 0; i < size; i++)
    {
      if (adj_matrix[index][i] && !visited[i])
      {
        dfs_util(i, visited);
      }
    }
  }

  void dfs(int node_val)
  {
    vector<bool> visited(size, false);
    auto it = find(nodes.begin(), nodes.end(), node_val);
    int index = (it == nodes.end() ? -1 : it - nodes.begin());

    if (index != -1)
    {
      dfs_util(index, visited);
    }
  }
};

int main()
{

  Graph g(7);

  g.addNode(0, 'A');
  g.addNode(1, 'B');
  g.addNode(2, 'C');
  g.addNode(3, 'D');
  g.addNode(4, 'E');
  g.addNode(5, 'F');
  g.addNode(6, 'G');

  g.addEdge(3, 0); // D - A
  g.addEdge(0, 2); // A - C
  g.addEdge(0, 3); // A - D
  g.addEdge(0, 4); // A - E
  g.addEdge(4, 2); // E - C
  g.addEdge(2, 5); // C - F
  g.addEdge(2, 1); // C - B
  g.addEdge(2, 6); // C - G
  g.addEdge(1, 5); // B - F

  // g.display();

  g.dfs('D');

  return 0;
}