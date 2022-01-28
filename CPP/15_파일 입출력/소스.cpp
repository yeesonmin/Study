#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string name = "ȫ�浿";
	int age = 18;

	//���� ����
	ofstream fout("C:\\Users\\yeeso\\\Desktop\\Study\\CPP\\15_���� �����\\test01.txt");//������ ������ ���� ������.
	if (!fout) {
		cout << "����!" << endl;
		return 0;
	}

	//���� ����
	fout<< name << endl;
	fout << age << endl;

	//���� �ݱ�
	fout.close();


	/////////////////////
	//�����б�
	string name2;
	int age2;

	//���� ����
	ifstream fin("C:\\Users\\yeeso\\\Desktop\\Study\\CPP\\15_���� �����\\test01.txt");
	if (!fin) {
		cout << "����!" << endl;
		return 0;
	}

	//���� �б�
	fin >> name2;
	fin >> age2;

	cout << name2 << endl;
	cout << age2 << endl;

	//���� �ݱ�
	fin.close();

	/////////////////////
	//�����б�2
	int cnt = 0;
	int c = 0;
	ifstream fin2("C:\\Users\\yeeso\\\Desktop\\Study\\CPP\\15_���� �����\\test01.txt");
	if (!fin2) {
		cout << "����!" << endl;
		return 0;
	}

	//���� �б�
	while ((c= fin2.get()) != EOF)//EOF ���� ������ �б�
	{
		cout << (char)c;
		cnt++;
	}

	cout << "����Ʈ �� : " << cnt << endl;

	//���� �ݱ�
	fin2.close();

	///////////////////
	//���� �����̱�
	
	fstream fout3("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\test03.txt", ios::out | ios::app);//���� ��� �� �� ���� ���ٿ� ����
	if (!fout3) {
		cout << "����!" << endl;
		return 0;
	}

	fstream fin3("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\test02.txt", ios::in);//�б� ���
	if (!fin3) {
		cout << "����!" << endl;
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
	//���� ���� ������ �б�

	fstream fin4("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\test03.txt");
	if (!fin4) {
		cout << "����!" << endl;
		return 0;
	}

	

	string buf4;
	while (getline(fin4,buf4))
	{
		cout << buf4 << endl;
	}

	fin4.close();

	///////////////////
	//�ܾ� �˻�
	int index = 0;
	vector<string> wordvector;
	ifstream fin5("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\test04.txt");
	if (!fin5) {
		cout << "����!" << endl;
		return 0;
	}


	string buf5;
	while (getline(fin5, buf5))
	{
		wordvector.push_back(buf5); //�� ���� �� ����
	}

	while (true)
	{
		cout << "�˻��� �ܾ� : ";
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
			cout << "����" << endl;
			cout << endl;
		}
	}
	fin4.close();


	///////////////////
	//���� ���� �� ������ ���� ��ŭ �б� => ���� �ӵ� ������.
	ifstream fsrc("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\rose.bmp", ios::in | ios::binary);
	if (!fsrc) {
		cout << "����!" << endl;
		return 0;
	}


	ofstream fdest("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\copyrose.bmp", ios::out | ios::binary);
	if (!fdest) {
		cout << "����!" << endl;
		return 0;
	}
	char s[1024];
	while (!fsrc.eof())
	{
		fsrc.read(s, 1024);//�ִ� �ش� ���� ��ŭ ����
		int n = fsrc.gcount();//���� ���� ����Ʈ ��
		fdest.write(s, n);
	}

	fsrc.close();
	fdest.close();

	///////////////////
	//�Ǽ� �� �Է�
	ofstream fout6("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\test05.dat", ios::out | ios::binary);
	if (!fout6) {
		cout << "����!" << endl;
		return 0;
	}


	int n6[] = { 1,2,3,4,5,6,7,8 };
	double d6 = 3.14;

	fout6.write((char*)n6, sizeof(n6));
	fout6.write((char*)&d6, sizeof(d6));

	fout6.close();

	ifstream fin6("C:\\Users\\yeeso\\Desktop\\Study\\CPP\\15_���� �����\\test05.dat", ios::in | ios::binary);
	if (!fin6) {
		cout << "����!" << endl;
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
