#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string name = "홍길동";
	int age = 18;

	//파일 열기
	ofstream fout("C:\\Users\\yeeso\\\Desktop\\Study\\CPP\\15_파일 입출력\\test01.txt");//파일이 없으면 파일 생성됨.
	if (!fout) {
		cout << "오류!" << endl;
		return 0;
	}

	//파일 쓰기
	fout<< name << endl;
	fout << age << endl;

	//파일 닫기
	fout.close();


	/////////////////////
	//파일읽기
	string name2;
	int age2;

	//파일 열기
	ifstream fin("C:\\Users\\yeeso\\\Desktop\\Study\\CPP\\15_파일 입출력\\test01.txt");
	if (!fin) {
		cout << "오류!" << endl;
		return 0;
	}

	//파일 읽기
	fin >> name2;
	fin >> age2;

	cout << name2 << endl;
	cout << age2 << endl;

	//파일 닫기
	fin.close();

	/////////////////////
	//파일읽기2
	int cnt = 0;
	int c = 0;
	ifstream fin2("C:\\Users\\yeeso\\\Desktop\\Study\\CPP\\15_파일 입출력\\test01.txt");
	if (!fin2) {
		cout << "오류!" << endl;
		return 0;
	}

	//파일 읽기
	while ((c= fin2.get()) != EOF)//EOF 만날 때까지 읽기
	{
		cout << (char)c;
		cnt++;
	}

	cout << "바이트 수 : " << cnt << endl;

	//파일 닫기
	fin2.close();

	///////////////////
	//파일 덧붙이기
	
	fstream fout3("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\test03.txt", ios::out | ios::app);//쓰기 모드 및 맨 끝에 덧붙여 쓰기
	if (!fout3) {
		cout << "오류!" << endl;
		return 0;
	}

	fstream fin3("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\test02.txt", ios::in);//읽기 모드
	if (!fin3) {
		cout << "오류!" << endl;
		return 0;
	}

	int c3;
	while ((c=fin3.get()) != EOF)
	{
		fout3.put(c);
	}

	fin3.close();
	fout3.close();
	cout <<  endl;

	///////////////////
	//파일 라인 단위로 읽기

	fstream fin4("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\test03.txt");
	if (!fin4) {
		cout << "오류!" << endl;
		return 0;
	}

	

	string buf4;
	while (getline(fin4,buf4))
	{
		cout << buf4 << endl;
	}

	fin4.close();

	///////////////////
	//단어 검색
	int index = 0;
	vector<string> wordvector;
	ifstream fin5("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\test04.txt");
	if (!fin5) {
		cout << "오류!" << endl;
		return 0;
	}


	string buf5;
	while (getline(fin5, buf5))
	{
		wordvector.push_back(buf5); //한 라인 씩 저장
	}

	while (true)
	{
		cout << "검색할 단어 : ";
		string tempword;
		getline(cin, tempword);
		if (tempword == "exit") {
			break;
		}

		for (size_t i = 0; i < wordvector.size(); i++)
		{
			index = wordvector[i].find(tempword);
			if (index != -1) {
				cout << wordvector[i] << endl;
				break;
			}
		}

		if (index == -1) {
			cout << endl;
			cout << "없다" << endl;
			cout << endl;
		}
	}
	fin4.close();


	///////////////////
	//파일 복사 및 지정된 단위 만큼 읽기 => 실행 속도 빨라짐.
	ifstream fsrc("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\rose.bmp", ios::in | ios::binary);
	if (!fsrc) {
		cout << "오류!" << endl;
		return 0;
	}


	ofstream fdest("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\copyrose.bmp", ios::out | ios::binary);
	if (!fdest) {
		cout << "오류!" << endl;
		return 0;
	}
	char s[1024];
	while (!fsrc.eof())
	{
		fsrc.read(s, 1024);//최대 해당 단위 만큼 저장
		int n = fsrc.gcount();//실제 읽은 바이트 수
		fdest.write(s, n);
	}

	fsrc.close();
	fdest.close();

	///////////////////
	//실수 값 입력
	ofstream fout6("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\test05.dat", ios::out | ios::binary);
	if (!fout6) {
		cout << "오류!" << endl;
		return 0;
	}


	int n6[] = { 1,2,3,4,5,6,7,8 };
	double d6 = 3.14;

	fout6.write((char*)n6, sizeof(n6));
	fout6.write((char*)&d6, sizeof(d6));

	fout6.close();

	ifstream fin6("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_파일 입출력\\test05.dat", ios::in | ios::binary);
	if (!fin6) {
		cout << "오류!" << endl;
		return 0;
	}

	int n6_c[8] = {0,0,0,0,0,0,0,0};
	double d6_c;
	fin6.read((char*)n6_c, sizeof(n6_c));
	fin6.read((char*)&d6_c, sizeof(d6_c));

	cout  << endl;
	for (size_t i = 0; i < 8; i++)
	{
		cout << n6_c[i] << endl;
	}
	cout << d6_c << endl;
	fin6.close();
}
