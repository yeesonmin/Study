#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(int i , int j) {
	return j < i;
}

void main() {

	//ū���� ��Ģ
	int n = 0, m = 0, k = 0;
	vector<int> arr;
	int result = 0;
	
	//�Է�
	cin >> n >> m >> k;
	for (size_t i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end(), compare);


	//���� ū���� �� ���� ū���� ���Ѵ�.
	int first = arr[0], second = arr[1];

	//���1
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

	//���2
	//���� ū ���� �������� Ƚ��
	result = 0;
	int cnt = m / (k + 1)*k + m % (k + 1);
	result = cnt * first;


	result += (m - cnt) * second;//�ι�° ū���� �������� Ƚ��
	cout << result;
}

