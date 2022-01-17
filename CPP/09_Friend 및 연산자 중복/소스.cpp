#include <iostream> 
using namespace std;

class Power
{
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	friend Power operator* (Power op1, Power op2);//������ �Լ� ����
	Power operator+ (Power op2);
	bool operator== (Power op2);
	Power operator+= (Power op2);

	Power& operator<<(int a);//���� ����
	void show();


private:

};

Power Power::operator+(Power op2)//������ �ߺ��Լ�
{
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2)
{
	if (kick == op2.kick && punch == op2.punch) return true;
	else
	{
		return false;
	}
	
}

Power Power::operator+=(Power op2)
{
	kick += op2.kick;
	punch += op2.punch;
	return *this;
}

Power& Power::operator<<(int a)
{
	kick += a;
	punch += a;

	return *this;
}

void Power::show()
{
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power operator*(Power op1, Power op2)//������ �Լ� ����
{
	Power tmp;
	tmp.kick = op1.kick * op2.kick;
	tmp.punch = op1.punch * op2.punch;
	return tmp;
}

void main() {
	Power a(3, 4), b(1, 2), c, d;
	c = a + b;
	
	a.show();
	b.show();
	c.show();
	
	c += a;
	c.show();

	d = a * b;
	d.show();

	a << 5;
	a.show();
	if (a == b) cout << "a �� b�� ����." << endl;
	else cout << "a �� b�� �ٸ���." << endl;
}


