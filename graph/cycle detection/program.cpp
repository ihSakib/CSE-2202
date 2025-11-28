// #include <bits/stdc++.h>
// using namespace std;

// class Graph
// {
// private:
//   int size;
//   vector<vector<int>> adj_matrix;
//   vector<char> nodes;

// public:
//   Graph(int n = 0) : size(n), adj_matrix(n, vector<int>(n, 0)), nodes(n, ' ') {}

//   void addEdge(int u, int v)
//   {
//     if (u >= 0 && u < size && v >= 0 && v < size)
//     {
//       adj_matrix[u][v] = 1;
//       // adj_matrix[v][u] = 1;
//     }
//   }

//   void addNode(int vertex, char data)
//   {
//     if (vertex >= 0 and vertex < size)
//     {
//       nodes[vertex] = data;
//     }
//   }


//   bool dfs_util(int index, vector<bool> &visited, int p)
//   {
//     visited[index] = true;

//     for (size_t i = 0; i < size; i++)
//     {
//       if (adj_matrix[index][i])
//       {
//         if (visited[i] && i != p)
//         {
//           return true;
//         }
//         else
//         {
//           dfs_util(i, visited, index);
//         }
//       }
//     }

//     return false;
//   }

//   bool isCyclic()
//   {
//     vector<bool> visited(size, false);

//     for (size_t i = 0; i < size; i++)
//     {
//       if (dfs_util(i, visited, -1))
//       {
//         return true;
//       }
//     }

//     return false;
//   }
// };

// int main()
// {
//   Graph g(5);

//   g.addNode(0, 'A');
//   g.addNode(1, 'B');
//   g.addNode(2, 'C');
//   g.addNode(3, 'D');
//   g.addNode(4, 'E');

//   g.addEdge(0, 3); // A > D
//   g.addEdge(0, 4); // A > E
//   g.addEdge(3, 4); // D > E
//   g.addEdge(1, 0); // B > A
//   g.addEdge(1, 2); // B > C
//   g.addEdge(1, 4); // B > E

//   g.display();
//   cout << g.isCyclic();

//   return 0;
// }