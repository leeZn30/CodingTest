#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
/*
    주의)
    정점만 있고 간선이 안 이어질 경우도 있음
    두 정점 사이에 간선이 여러개일 수 있음
*/ 
vector<int> visited;

// 메모리 초과 발생
void DFS(map<int, vector<int>> &graph, int vertex)
{
    if (find(visited.begin(), visited.end(), vertex) != visited.end())
        return;

    printf("%d ", vertex);
    visited.push_back(vertex);

    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (find(visited.begin(), visited.end(), graph[vertex][i]) == visited.end())  
            DFS(graph, graph[vertex][i]);
    }
}

void BFS(map<int, vector<int>> &graph, int v)
{
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();

        if (find(visited.begin(), visited.end(), vertex) != visited.end())
            continue;

        printf("%d ", vertex);
        visited.push_back(vertex);

        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (find(visited.begin(), visited.end(), vertex) != visited.end())
                q.push(graph[vertex][i]);
        }
    }
}
int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    map<int, vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        // v1 넣기
        if (graph.find(v1) != graph.end())
        {
            // 간선이 여러개일수 있어서 하나만 넣어야함
            if (find(graph[v1].begin(), graph[v1].end(), v2) == graph[v1].end())
                graph[v1].push_back(v2);
        }
        else
        {
            graph[v1] = vector<int>(1, v2);
        }

        // v2 넣기
        if (graph.find(v1) != graph.end())
        {
            // 간선이 여러개일수 있어서 하나만 넣어야함
            if (find(graph[v2].begin(), graph[v2].end(), v1) == graph[v2].end())
                graph[v2].push_back(v1);
            graph[v2].push_back(v1);
        }
        else
        {
            graph[v2] = vector<int>(1, v1);
        }
    }

    /*
        STL 주의
    */
    // 정렬
    for (auto iter = graph.begin(); iter != graph.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
    }

    // DFS
    DFS(graph, v);

    printf("\n");
    visited.clear();

    // BFS
    BFS(graph, v);
}
