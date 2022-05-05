// Implement distance vector routing algorithm
// Sample Input for Graph:
/**
 * 0 4 -1 -1
 * 4 0 1 5
 * -1 1 0 2
 * -1 5 2 0
**/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/* Vertex names */
vector<char> ch = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
int fieldWidth = 10;
int inf = INT32_MAX;

int main()
{
  int V;
  cout << "\nEnter Number of Nodes: ";
  cin >> V;
  vector<vector<int>> graph(V, vector<int>(V, -1));
  vector<vector<int>> via(V, vector<int>(V, -1));

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

  for (int i = 0; i < V; i++)
    via[i][i] = i;

  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j] != inf)
        via[i][j] = i;
    }
  }

  vector<vector<int>> dist = graph;
  for (int k = 0; k < V; k++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (dist[i][k] != inf and dist[k][j] != inf and dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          via[i][j] = via[i][k] == i ? k : via[i][k];
        }
      }
    }
  }

  cout << "\n\nAfter update, Routing tables are:";
  for (int i = 0; i < V; i++)
  {
    cout << "\nRouting table for " << ch[i] << ":\n";
    cout << setw(fieldWidth) << "To" << setw(fieldWidth) << "Dist" << setw(fieldWidth) << "Via" << endl;

    for (int j = 0; j < V; j++)
    {
      cout << setw(fieldWidth) << ch[j] << setw(fieldWidth) << dist[i][j];

      if (i == via[i][j])
        cout << setw(fieldWidth) << "-" << endl;
      else
        cout << setw(fieldWidth) << ch[via[i][j]] << endl;
    }
  }
}