#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> picture(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cin >> picture[r][c];
        }
    }

    int sum = 0;
    int cnt = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (!visited[r][c] && picture[r][c] == 1)
            {
                cnt++;
                int nowSum = 0;
                queue<pair<int, int>> q;
                q.push(make_pair(r, c));
                while(!q.empty())
                {
                    pair<int, int> nowPose = q.front();
                    q.pop();

                    if (visited[nowPose.first][nowPose.second])
                        continue;

                    visited[nowPose.first][nowPose.second] = true;
                    nowSum++;

                    for (int i = 0; i < 4; i++)
                    {
                        pair<int, int> checkPose(nowPose.first + Dir[i][0], nowPose.second + Dir[i][1]);

                        if ((0 <= checkPose.first && checkPose.first < n) && (0 <= checkPose.second && checkPose.second < m))
                        {
                            if (picture[checkPose.first][checkPose.second] == 1)
                            {
                                q.push(checkPose);
                            }
                        }
                    }
                }

                sum = max(sum, nowSum);
            }
        }
    }

    printf("%d\n%d", cnt, sum);
}