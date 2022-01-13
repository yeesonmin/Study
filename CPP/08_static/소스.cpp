#include <iostream> 
using namespace std;

class ArrayUtility2
{
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);

	ArrayUtility2();
	~ArrayUtility2();

private:

};

int* ArrayUtility2::concat(int s1[], int s2[], int size)
{
	int* result = new int[size];
	int cnt = 0;
	for (int i = 0; i < size/2; i++)
	{
		result[cnt] = s1[i];
		cnt++;
	}

	for (int i = 0; i < size / 2; i++)
	{
		result[cnt] = s2[i];
		cnt++;
	}

	return result;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize)
{
	int* result = new int[size];
	bool isInclude = false;
	for (int i = 0; i < size/2; i++)
	{
		isInclude = false;
		for (int j = 0; j < size/2; j++)
		{
			if (s1[i] == s2[j])
			{
				isInclude = true;
				break;
			}
		}

		if (!isInclude) {
			result[retSize++] = s1[i];
		}
	}
	if (retSize == 0) return NULL;
	return result;
}

ArrayUtility2::ArrayUtility2()
{
}

ArrayUtility2::~ArrayUtility2()
{
}

void main() {
	int s1[] = { 5,4,3,2,1 };
	int s2[] = { 3,2,1,0,-1 };
	int cnt = 0;
	int* result = ArrayUtility2::concat(s1, s2, (sizeof(s1) + sizeof(s2)) / sizeof(int));
	int* result2 = ArrayUtility2::remove(s1, s2, (sizeof(s1) + sizeof(s2)) / sizeof(int), cnt);

	for (int i = 0; i < (sizeof(s1) + sizeof(s2)) / sizeof(int); i++)
	{
		cout << *(result + i) << " ";
	}
	cout << endl;

	for (int i = 0; i < cnt; i++)
	{
		cout << *(result2 + i) << " ";
	}
}