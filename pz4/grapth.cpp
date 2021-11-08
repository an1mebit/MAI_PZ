#include <iostream>

using namespace std;

class Graph
{
    bool** adjMatrix;
    int numVertices;
    bool** pathMatrix;

public:
    Graph(int numVertices);
    ~Graph();

    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    bool isEdge(int i, int j);
    void table();
    void tableDost();

};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjMatrix = new bool* [numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int i, int j)
{
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

void Graph::removeEdge(int i, int j)
{
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

bool Graph::isEdge(int i, int j)
{
    return adjMatrix[i][j];
}

void Graph::table()
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

void ::Graph::tableDost()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
            pathMatrix[i][j] = adjMatrix[i][j];
    }

    for (int k = 0; k < numVertices; k++)
    {
        for (int i = 0; i < numVertices; i++)
            if (pathMatrix[i][k] == 1)
                for (int j = 0; j < numVertices; j++)
                    pathMatrix[i][j] = (pathMatrix[i][j] || pathMatrix[k][j]);
    }
}

int main()
{
    cout << "Enter number of vertics n endges" << endl;
    int vert, edg;
    cin >> vert >> edg;

    Graph g(vert);

    cout << "Enter adjacent verics" << endl;

    for (int i = 0; i < edg; i++)
    {
        int ver1, ver2;
        cin >> ver1 >> ver2;
        g.addEdge(ver1, ver2);
    }

    g.table();
    g.tableDost();
}
