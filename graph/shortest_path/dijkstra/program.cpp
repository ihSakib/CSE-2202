#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
  int size;
  vector<char> nodes;
  vector<vector<int>> adj_matrix;

public:
  Graph(int n) : size(n), nodes(n, ' '), adj_matrix(n, vector<int>(n, 0)) {}

  void addNode(int i, char val)
  {
    if (i >= 0 and i < size)
    {
      nodes[i] = val;
    }
  }

  void addEdge(int u, int v, int w)
  {
    if (u >= 0 and u < size and v >= 0 and v < size)
    {
      adj_matrix[u][v] = w;
      adj_matrix[v][u] = w;
    }
  }

  int getSize()
  {
    return size;
  }

  char getNodeVal(int i)
  {
    return nodes[i];
  }

  vector<int> dijkstra(char start)
  {
    auto it = find(nodes.begin(), nodes.end(), start);
    int start_vertex = it != nodes.end() ? it - nodes.begin() : -1;

    vector<int> distances(size, INT_MAX);
    distances[start_vertex] = 0;
    vector<bool> tracker(size, false);

    for (auto _ : nodes)
    {
      int min_distance = INT_MAX;
      int u = -1;

      for (size_t i = 0; i < size; i++)
      {
        if (!tracker[i] and distances[i] < min_distance)
        {
          min_distance = distances[i];
          u = i;
        }
      }

      if (u == -1)
      {
        break;
      }

      tracker[u] = true;

      for (size_t i = 0; i < size; i++)
      {
        if (adj_matrix[u][i] and !tracker[i])
        {
          if (distances[u] + adj_matrix[u][i] < distances[i])
          {
            distances[i] = distances[u] + adj_matrix[u][i];
          }
        }
      }
    }

    return distances;
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

  g.addEdge(3, 0, 4); // D - A, weight 4
  g.addEdge(3, 4, 2); // D - E, weight 2
  g.addEdge(0, 2, 3); // A - C, weight 3
  g.addEdge(0, 4, 4); // A - E, weight 4
  g.addEdge(4, 2, 4); // E - C, weight 4
  g.addEdge(4, 6, 5); // E - G, weight 5
  g.addEdge(2, 5, 5); // C - F, weight 5
  g.addEdge(2, 1, 2); // C - B, weight 2
  g.addEdge(1, 5, 2); // B - F, weight 2
  g.addEdge(6, 5, 5); // G - F, weight 5

  vector<int> distances = g.dijkstra('D');

  for (size_t i = 0; i < g.getSize(); i++)
  {
    cout << "Shortest distance from D to " << g.getNodeVal(i) << ": " << distances[i] << endl;
  }

  return 0;
}