// Implement Link state routing algorithm
// Sample Input for Graph:
/**
 * 0 4 -1 -1
 * 4 0 1 5
 * -1 1 0 2
 * -1 5 2 0
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/* Vertex names */
vector<char> ch = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
int fieldWidth = 10;
int inf = INT32_MAX;

void printSPT(vector<int> &dist, vector<int> &parent)
{
  int V = dist.size();
  for (int i = 0; i < V; i++)
  {
    vector<int> path;
    for (int u = i; u != -1; u = parent[u])
      path.push_back(u);
    reverse(path.begin(), path.end());
    cout << "Path for Node " << ch[i] << ": ";
    for (int p = 0; p < path.size() - 1; p++)
      cout << ch[path[p]] << "->";
    cout << ch[path[path.size() - 1]] << "\n";
  }
}

pair<vector<int>, vector<int>> dijkstra(vector<vector<int>> &graph, int src)
{
  int V = graph.size();
  vector<int> dist(V, inf);
  vector<int> parent(V, src);
  vector<bool> flag(V, false); // if flag[i] is true, then the node i is included in the spt otherwise not.

  dist[src] = 0;
  parent[src] = -1;

  for (int c = 0; c < V - 1; c++)
  {
    int minVal = inf, minIndex;
    for (int i = 0; i < V; i++)
    {
      if (flag[i] == false and dist[i] < minVal)
      {
        minIndex = i;
        minVal = dist[i];
      }
    }
    int u = minIndex;
    flag[u] = true;

    for (int v = 0; v < V; v++)
    {
      if (!flag[v] and graph[u][v] != inf and dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }
  cout << "\nSPT for router " << ch[src] << ":\n";
  printSPT(dist, parent);
  return {parent, dist};
}

vector<vector<int>> inputGraph()
{
  int V;
  cout << "\nEnter the no of nodes: ";
  cin >> V;
  vector<vector<int>> graph(V, vector<int>(V, -1));

  cout << "Enter distances in the form of matrix\n (-1 if nodes are not connected):\n";
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      cin >> graph[i][j];
      if (graph[i][j] < 0)
        graph[i][j] = inf;
    }
  }
  return graph;
}

void buildRoutingTable(vector<int> &parent, vector<int> &dist, int src)
{
  int V = dist.size();
  cout << "\nRouting table for " << ch[src] << ":\n";
  cout << setw(fieldWidth) << "To" << setw(fieldWidth) << "Dist" << setw(fieldWidth) << "Via" << endl;

  for (int i = 0; i < V; i++)
  {
    int memo = i;
    for (int u = i; parent[u] != -1; u = parent[u])
      memo = u;

    cout << setw(fieldWidth) << ch[i] << setw(fieldWidth) << dist[i];
    if (memo == i)
      cout << setw(fieldWidth) << "-" << endl;
    else
      cout << setw(fieldWidth) << ch[memo] << endl;
  }
}

int main()
{
  vector<vector<int>> graph = inputGraph();
  int V = graph.size();
  for (int src = 0; src < V; src++)
  {
    auto p = dijkstra(graph, src);
    vector<int> parent = p.first;
    vector<int> dist = p.second;
    buildRoutingTable(parent, dist, src);
  }
}