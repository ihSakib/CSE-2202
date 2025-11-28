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

  void addEdge(int u, int v)
  {
    if (u >= 0 and u < size and v >= 0 and v < size)
    {
      adj_matrix[u][v] = 1;
      adj_matrix[v][u] = 1;
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

  void dfs_util(int i, vector<bool> &tracker)
  {
    tracker[i] = true;
    cout << nodes[i] << " -> ";

    for (size_t j = 0; j < size; j++)
    {
      if (adj_matrix[i][j] and !tracker[j])
      {
        dfs_util(j, tracker);
      }
    }
  }

  void dfs(char start)
  {
    auto it = find(nodes.begin(), nodes.end(), start);
    int i = it != nodes.end() ? it - nodes.begin() : -1;

    if (i != -1)
    {
      vector<bool> tracker(size, false);
      dfs_util(i, tracker);
    }
  }

  void bfs_util(int i, vector<bool> &tracker)
  {
    queue<int> q;
    q.push(i);
    tracker[i] = true;

    while (!q.empty())
    {
      int curr_index = q.front();
      q.pop();
      cout << nodes[curr_index] << " -> ";

      for (size_t i = 0; i < size; i++)
      {
        if (adj_matrix[curr_index][i] and !tracker[i])
        {
          q.push(i);
          tracker[i] = true;
        }
      }
    }
  }

  void bfs(char start)
  {
    auto it = find(nodes.begin(), nodes.end(), start);
    int i = it != nodes.end() ? it - nodes.begin() : -1;

    if (i != -1)
    {
      vector<bool> tracker(size, false);
      bfs_util(i, tracker);
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

  // g.dfs('A');
  g.bfs('D');

  return 0;
}