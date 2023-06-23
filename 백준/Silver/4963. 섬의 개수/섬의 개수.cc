#include <iostream>
#include <queue>
using namespace std;
int land[51][51];
int x_move[8] = { -1, 1, 0, 0 , -1, 1, -1, 1 };
int y_move[8] = { 0, 0, -1, 1 , -1, 1, 1, -1 };
queue<pair<int, int>> q;

void DFS(int x, int y, int w, int h) {
	land[x][y] = 0;
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];

			if ((x_new >= 0 && x_new < h) && (y_new >= 0 && y_new < w)
				&& land[x_new][y_new] == 1) {
				land[x_new][y_new] = 0;
				q.push({ x_new, y_new });
			}
		}
	}
}
int main() {
	int w, h, num;
	while (cin >> w >> h) {
		if (w == 0 && h == 0) {
			break;
		}
		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> num;
				land[i][j] = num;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (land[i][j] == 1) {
					DFS(i, j, w, h);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}