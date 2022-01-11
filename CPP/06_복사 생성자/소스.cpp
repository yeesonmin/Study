#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring> 
using namespace std;

//�Ϲ� ���� ������ => ���� ����
class Person { // Person ���� 
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person);//���� ������ �߰� (classsname& )
	~Person(); 
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; };
};
Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Person::Person(const Person& person) {//���� ������ �ۼ�
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
}
Person:: ~Person() { 
	if (name) // ���� name ���� �迭�� ������ 
		delete[] name; // ���� �Ҵ� �Ҹ�
}
void Person::changeName(const char* name) { // ����
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}
int main() {
	Person father(1, "Kitae");
	Person daughter(father);
	cout << "daughter ����" << endl;

	father.show();
	daughter.show(); // (3) daughter #

	daughter.changeName("Grace"); // (4) daughter "Grace" 
	cout << "daughter �̸��� Grace ���� -- " << endl;
	father.show(); // (5) father ��ü ���
	daughter.show();
	// ���� ����� �Ҹ�� ���� �߻�
	// ���� �����ڷ� �ۼ��� ���� �߻� x => ���� ���簡 ��.

}
