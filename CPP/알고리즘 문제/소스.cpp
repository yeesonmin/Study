#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(int i , int j) {
	return j < i;
}

void main() {

	//큰수의 법칙
	int n = 0, m = 0, k = 0;
	vector<int> arr;
	int result = 0;
	
	//입력
	cin >> n >> m >> k;
	for (size_t i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end(), compare);


	//가장 큰수와 그 다음 큰수를 구한다.
	int first = arr[0], second = arr[1];

	//방법1
	int i = 0;
	while (i < m)
	{
		for (size_t j = 0; j < k && i < m; j++)
		{
			result += first;
			i++;
		}

		if (i < m) {
			result += second;
			i++;
		}
	}

	
	cout << result;

	//방법2
	//가장 큰 수가 더해지는 횟수
	result = 0;
	int cnt = m / (k + 1)*k + m % (k + 1);
	result = cnt * first;


	result += (m - cnt) * second;//두번째 큰수가 더해지는 횟수
	cout << result;
}

