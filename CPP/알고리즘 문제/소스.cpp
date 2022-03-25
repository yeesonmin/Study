#include <iostream>
#include <vector>
using namespace std;


vector<int> graph[8];
bool visited[8] = { false };

void DFS(int i) {
	cout << i+1 << " ";
	visited[i] = true;

	for (int j : graph[i])
	{
		if (!visited[j-1]) {
			DFS(j-1);
		}
	}
}
void main() {
	//DFS
	

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

	DFS(0);

}