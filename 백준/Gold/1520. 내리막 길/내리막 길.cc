#include <iostream>

using namespace std;

int land[501][501];
int visit[501][501];
int dp[501][501];

int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };

int DFS (int x, int y, int M, int N)
{
  if (x == M - 1 && y == N - 1) {
      return 1;
    }

  if (visit[x][y] == 1) {
      return dp[x][y];
    }

  visit[x][y] = 1;
  
  for (int i = 0; i < 4; i++) {
      int x_new = x + x_move[i];
      int y_new = y + y_move[i];
      
      if ((x_new >= 0 && x_new < M) && (y_new >= 0 && y_new < N)
	  && (land[x_new][y_new] < land[x][y])) {
	      dp[x][y] += DFS(x_new, y_new, M, N);
	  }
  }
  
  return dp[x][y];
}

int main() {
  int M, N, num;
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
	  cin >> num;
	  land[i][j] = num;
      }
    }
  cout << DFS (0, 0, M, N) << "\n";
}
