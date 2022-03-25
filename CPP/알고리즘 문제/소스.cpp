#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> graph[8];
bool visited[8] = { false };

void BFS(int i) {
	queue<int> q;
	q.push(i);
	visited[i] = true;

	while (!q.empty())
	{
		int j = q.front();
		q.pop();
		cout << j + 1 << " ";

		for (int k : graph[j])
		{
			if (!visited[k - 1]) {
				q.push(k - 1);
				visited[k - 1] = true;
			}
		}
	}

}
void main() {
	//BFS
	

	graph[0].push_back(2);
	graph[0].push_back(3);
	graph[0].push_back(8);

	graph[1].push_back(1);
	graph[1].push_back(7);

	graph[2].push_back(1);
	graph[2].push_back(4);
	graph[2].push_back(5);

	graph[3].push_back(3);
	graph[3].push_back(5);

	graph[4].push_back(3);
	graph[4].push_back(4);

	graph[5].push_back(7);

	graph[6].push_back(2);
	graph[6].push_back(6);
	graph[6].push_back(8);

	graph[7].push_back(1);
	graph[7].push_back(7);

	BFS(0);

}