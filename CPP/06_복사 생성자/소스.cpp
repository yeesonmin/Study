#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring> 
using namespace std;

//일반 복사 생성자 => 얇은 복사
class Person { // Person 선언 
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person);//복사 생성자 추가 (classsname& )
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
Person::Person(const Person& person) {//복사 생성자 작성
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
}
Person:: ~Person() { 
	if (name) // 만일 name 동적 배열이 있으면 
		delete[] name; // 동적 할당 소멸
}
void Person::changeName(const char* name) { // 변경
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}
int main() {
	Person father(1, "Kitae");
	Person daughter(father);
	cout << "daughter 직후" << endl;

	father.show();
	daughter.show(); // (3) daughter #

	daughter.changeName("Grace"); // (4) daughter "Grace" 
	cout << "daughter 이름을 Grace 변경 -- " << endl;
	father.show(); // (5) father 객체 출력
	daughter.show();
	// 얇은 복사로 소멸시 오류 발생
	// 복사 생성자로 작성시 오류 발생 x => 깊은 복사가 됨.

}
