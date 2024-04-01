/*
문제
종운이는 운영하던 게임에 랭킹전 기능을 추가하려고 한다.
플레이어 간의 실력차이가 있을 수 있기 때문에 입장을 신청하면 자신과 비슷한 레벨의 플레이어들을 매칭하여 게임을 시작하게 하려고 한다.

플레이어 간 매칭을 해주는 시스템은 다음과 같다.

플레이어가 입장을 신청하였을 때 매칭이 가능한 방이 없다면 새로운 방을 생성하고 입장시킨다. 
이떄 해당 방에는 처음 입장한 플레이어의 레벨을 기준으로 -10부터 +10까지 입장 가능하다.
입장 가능한 방이 있다면 입장시킨 후 방의 정원이 모두 찰 때까지 대기시킨다.
이때 입장이 가능한 방이 여러 개라면 먼저 생성된 방에 입장한다.
방의 정원이 모두 차면 게임을 시작시킨다.
플레이어의 수 p, 플레이어의 닉네임 n, 플레이어의 레벨 l, 방 한개의 정원 m이 주어졌을 때 위와 같은 방법으로 매칭해주고 최종적으로 만들어진 방의 상태와 입장 플레이어들을 출력하는 프로그램을 작성하자.

입력
첫 번째 줄에는 플레이어의 수 p(1 ≤ p ≤ 300)와 방의 정원 m(1 ≤ m ≤ 300)가 주어진다.

두 번째 줄부터 p개의 줄에는 플레이어의 레벨 l (1 ≤ l ≤ 500)과 닉네임 n이 공백을 두고 주어진다.

입력된 순서대로 게임을 시작한다.

닉네임은 중복되지 않으며 공백을 포함하지 않는 알파벳 소문자로 되어있으며 닉네임의 길이는 16을 넘지 않는다.

출력
모든 생성된 방에 대해서 게임의 시작 유무와 방에 들어있는 플레이어들의 레벨과 아이디를 출력한다. 시작 유무와 플레이어의 정보들은 줄 바꿈으로 구분되며 레벨과 아이디는 한 줄에서 공백으로 구분된다.

방은 생성된 순서대로 출력한다.

방에 있는 플레이어들의 정보는 닉네임이 사전순으로 앞서는 플레이어부터 출력한다.

방이 시작되었으면 Started!를 대기 중이면 Waiting!을 출력시킨다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparer(pair<int, string> a, pair<int, string> b)
{
    return a.second < b.second;
}

int main()
{
    int p, m;
    cin >> p >> m;

    vector<pair<int, string>> players(p);
    for (int i = 0; i < p; i++)
    {
        int l;
        string n;
        cin >> l >> n;
        players[i] = make_pair(l, n);
    }

    vector<vector<pair<int, string>>> rooms;
    for (int i = 0; i < p; i++)
    {
        if (!rooms.empty())
        {
            bool isFound = false;

            // 한번 더 돌리기
            for (int j = 0; j < rooms.size(); j++)
            {
                // 정원이 다 차지 않았으며, 레벨이 맞을 경우
                int level = rooms[j][0].first;
                if (rooms[j].size() < m && (players[i].first <= level + 10 && level - 10 <= players[i].first))
                {
                    rooms[j].push_back(players[i]);
                    isFound = true;
                    break;
                }
            }

            if (!isFound)
            {
                vector<pair<int, string>> v;
                v.push_back(players[i]);
                rooms.push_back(v);
            }
        }
        else
        {
            vector<pair<int, string>> v;
            v.push_back(players[i]);
            rooms.push_back(v);
        }
    }


    // 출력(플레이어 이름 사전순)
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].size() == m)
        {
            printf("Started!\n");
        }
        else
        {
            printf("Waiting!\n");
        }

        sort(rooms[i].begin(), rooms[i].end(), comparer);

        for (int j = 0; j < rooms[i].size(); j++)
        {
            printf("%d %s\n", rooms[i][j].first, rooms[i][j].second.c_str());
        }
    }
}