#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

bool visited[1001];
int graph[1001][1001];
int n, m, v;

void DFS(int);
void BFS(int);

int main()
{
    cin >> n >> m >> v;
    
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    
    // DFS
    DFS(v);

    printf("\n");
    memset(visited, false, sizeof(visited));

    // BFS
    BFS(v);
}

void DFS(int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && graph[vertex][i] == 1)
            DFS(i);
    }
}

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();

        if (visited[vertex])
            continue;

        printf("%d ", vertex);
        visited[vertex] = true;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && graph[vertex][i] == 1)
                q.push(i);
        }
    }
}