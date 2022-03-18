#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void main() {

	//숫자 카드 게임
	int n, m;
	vector<vector<int>> arr;
	vector<int> N;
	int result = 0;
	cin >> n >> m;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			int temp = 0;
			cin >> temp;
			N.push_back(temp);
		}
		arr.push_back(N);
		N.clear();
	}

	for (size_t i = 0; i < n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
		
		if (result < arr[i][0]) {
			result = arr[i][0];
		}
	}

	cout << result;

}

