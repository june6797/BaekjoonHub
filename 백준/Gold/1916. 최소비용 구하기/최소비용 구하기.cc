#include <iostream>

using namespace std;

#define INF 1000000000
int adj[1001][1001];
int dist[1001];
int visited[1001];

int get_small_node(int N) {
	int min = INF + 1;
	int min_idx = 0;

	for (int j = 1; j <= N; j++)
	{
		if (visited[j] == 0 && dist[j] < min)
		{
			min = dist[j];
			min_idx = j;
		}
	}
	return min_idx;
}

void dijkstra(int start, int N) {
	visited[start] = 1;
	dist[start] = 0;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = adj[start][i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		int min_node = get_small_node(N);

		visited[min_node] = 1;
		for (int k = 1; k <= N; k++)
		{
			if (visited[k] == 0)
			{
				if (dist[k] > (dist[min_node] + adj[min_node][k]))
				{
					dist[k] = (dist[min_node] + adj[min_node][k]);
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			if (i == j)
			{
				adj[i][j] = 0;
			}
			else
			{
				adj[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < 1001; i++)
	{
		dist[i] = INF;
	}

	int N, M, s, d, w, start, end;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> d >> w; //s 시작도시 d 도착도시 w 비용
		
		if (w < adj[s][d]) {
			adj[s][d] = w;
		}
	}
	cin >> start >> end;
	
	dijkstra(start, N);

	cout << dist[end];
	
}