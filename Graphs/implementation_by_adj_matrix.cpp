#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int n;
    int m;
    vector<vector<int>> adj;

    graph(int nodes, int edges)
    {
        n = nodes;
        m = edges;
        vector<vector<int>> temp(n + 1, vector<int>(n + 1, 0));
        adj = temp;
    }

    void addNodeinGraph(int x, int y)
    {
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    void PrintedjMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n = 0, m = 0;
    cout << "enter number of nodes" << endl;
    cin >> n;
    cout << "enter number of edges" << endl;
    cin >> m;
    graph G(n, m);
    cout<<"enter edge connected pair wise "<<endl;
    for (int i = 0; i < m; i++)
    {   int x,y;
        cin>>x>>y;
        G.addNodeinGraph(x,y);
    }

    G.PrintedjMatrix();

    return 0;
}