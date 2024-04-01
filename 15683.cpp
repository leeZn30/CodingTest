#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pipi pair<int, pair<int, int>>
using namespace std;

vector<vector<int>> DIR = 
{
    {-1, 0}, // 위
    {0, 1},  // 오른쪽
    {1, 0},  // 아래
    {0, -1}  // 왼쪽
};

struct comparer
{
    bool operator()(pipi a, pipi b)
    {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    priority_queue<pipi, vector<pipi>, comparer> q;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cin >> map[r][c];

            if (map[r][c] > 0 && map[r][c] < 6)
            {
                q.push(make_pair(map[r][c], make_pair(r, c)));
            }
        }
    }

    while(!q.empty())
    {
        pipi pi = q.top();
        q.pop();

        int CCTV = pi.first;
        /*
        5: DIR (0,1,2,3) -> 한번에 4개
        4: DIR (0, 1, 3), (0, 1, 2), (1, 2, 3) (0, 2, 3) > 하나 빼면서
        3: DIR(0,1) (1,2) (2,3) (3, 0)
        2: (0, 3) (1,2) -> 합이 3인 조합
        1: ((0), (1), (2), (3))
        */
        for (int i = 0; i < DIR.size(); i++)
        {

        }
    }

}