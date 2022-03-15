//#include<iostream>
//
//using namespace std;
//
//int GCD(int a, int b);
//int GCD2(int a, int b);
//void main() {
//	cout << GCD(280, 30) << endl;
//	cout << GCD2(280, 30) << endl;
//}
//
//int GCD(int a, int b)
//{
//#if 0
//	if (a < b) {
//		GCD(b, a);
//}
//	else
//	{
//		if (a - b == 0) {
//			return b;
//		}
//		else
//		{
//			GCD(a - b, b);
//		}
//
//	}
//#endif // 0
//
//	int t;
//
//	while (a)
//	{
//		if (a < b) {
//			t = a;
//			a = b;
//			b = t;
//		}
//		else
//		{
//			a -= b;
//		}
//	}
//	return b;
//}
//
//int GCD2(int a, int b)
//{
//	int t;
//	while (b)
//	{
//		/*if (a < b) {
//			t = a;
//			a = b;
//			b = t;
//		}
//		a %= b;*/
//		t = a% b;
//		a = b;
//		b = t;
//	}
//	return a;
//}
