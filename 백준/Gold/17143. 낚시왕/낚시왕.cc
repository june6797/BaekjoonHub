#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
#include <string>
typedef long long int ll;
using namespace std;

int r, c, m, ans;

struct Shark
{
    int speed;
    int way;
    int big;
};

Shark arr[101][101];
bool visit[101][101];

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
void fishing(int idx) {
    for (int i = 1; i <= r; i++)
    {
        if (visit[i][idx] == 1)
        {
            ans += arr[i][idx].big;
            visit[i][idx] = 0;
            arr[i][idx].big = 0;
            arr[i][idx].way = 0;
            arr[i][idx].speed = 0;
            break;
        }
    }
}

pair<pair<int, int>, int> cal(int x, int y, int l, int d) {
    while (l != 0)
    {
        int go = d % 4;
        if (go == 0)
        {
            if (y - 1 >= l)
            {
                y -= l;
                l = 0;
            }
            else
            {
                l -= (y - 1);
                y = 1;
                d = 3;
            }
        }
        else if (go == 1)
        {
            if (x - 1 >= l)
            {
                x -= l;
                l = 0;
            }
            else
            {
                l -= (x - 1);
                x = 1;
                d = 2;
            }
        }
        else if (go == 2)
        {
            if (r - x >= l)
            {
                x += l;
                l = 0;
            }
            else
            {
                l -= (r - x);
                x = r;
                d = 1;
            }
        }
        else if (go == 3)
        {
            if (c - y >= l)
            {
                y += l;
                l = 0;
            }
            else
            {
                l -= (c - y);
                y = c;
                d = 0;
            }
        }
    }
    return { {x, y }, d };
}
void sharkmove() {
    Shark temp[101][101] = {};
    bool tempvisit[101][101] = {};
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (visit[i][j] == 1)
            {
                pair<pair<int, int>, int> p = cal(i, j, arr[i][j].speed, arr[i][j].way);
                if (tempvisit[p.first.first][p.first.second] == 0)
                {
                    temp[p.first.first][p.first.second] = arr[i][j];
                    temp[p.first.first][p.first.second].way = p.second;
                    tempvisit[p.first.first][p.first.second] = 1;
                }
                else
                {
                    if (temp[p.first.first][p.first.second].big < arr[i][j].big)
                    {
                        temp[p.first.first][p.first.second] = arr[i][j];
                        temp[p.first.first][p.first.second].way = p.second;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            arr[i][j] = temp[i][j];
            visit[i][j] = tempvisit[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        arr[x][y].speed = s;
        arr[x][y].way = d;
        arr[x][y].big = z;
        visit[x][y] = 1;
    }
    int person = 1;
    while (person != c + 1)
    {
        fishing(person);
        sharkmove();
        person++;
    }
    cout << ans;
}