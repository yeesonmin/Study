#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void main() {
	vector<string> name;
	vector<string>::iterator nameit;

	nameit = name.begin();

	name.push_back("±è1");
	name.push_back("±è2");
	name.push_back("±è3");

	for (size_t i = 0; i < name.size(); i++)
	{
		cout << name[i] << endl;
	}

	cout << endl;
	for (nameit = name.begin(); nameit != name.end(); nameit++)
	{
		cout << *nameit << endl;
	}

	map<int, string> number;
	number.insert(make_pair(1, "±è"));
	number.insert(make_pair(2, "ÀÌ"));
	number.insert(make_pair(3, "È£"));

	map<string, int> number2;
	number2.insert(make_pair("±è", 1));
	number2.insert(make_pair("ÀÌ", 2));
	number2.insert(make_pair("È£", 3));

	for (size_t i = 0; i < number.size(); i++)
	{
		cout << number[i] << endl;
	}

	cout << endl;
	for (size_t i = 0; i < number.size(); i++)
	{
		cout << number.at(i) << endl;
	}

	cout << number2["±è"] << endl;
	cout << number2.at("ÀÌ") << endl;


	//Á¤·Ä ¾Ë°í¸®Áò
	int a[] = { 5,3,4,2,1,8,3,4,0,4,3,5,1,2,34,8 };
	cout << endl;
	for (size_t i = 0; i < sizeof(a)/ sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	sort(a, a + sizeof(a) / sizeof(a[0]));
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	//¶÷´Ù½Ä
	[](int x, int y) { cout << "ÇÕ : " << x + y; } (5,3);
}
