#include <iostream> 
using namespace std;

class Printer
{
public:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
	void Print(int pages);
	Printer(string model, string manufacturer, int availableCount);
	Printer();
	~Printer();

private:

};

void Printer::Print(int pages)
{
	if (availableCount - pages > 0)
	{
		availableCount -= pages;
		printedCount += pages;
		cout << "����Ʈ �߽��ϴ�." << endl;
	}
	else
	{
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	
}

Printer::Printer(string model, string manufacturer, int availableCount)
{
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
}

Printer::Printer()
{
}

Printer::~Printer()
{
}

class InkPrinter : Printer
{
public:
	int availableInk;
	void PrintInkJet(int pages);
	void InkInfo();
	InkPrinter(string model, string manufacturer, int availableCount,int availableInk);
	InkPrinter();
	~InkPrinter();

private:

};

void InkPrinter::PrintInkJet(int pages)
{
	if (availableCount - pages > 0)
	{
		availableCount -= pages;
		availableInk -= pages;
		printedCount += pages;
		cout << "����Ʈ �߽��ϴ�." << endl;
	}
	else
	{
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	
}

void InkPrinter::InkInfo()
{
	cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "�� , ���� ��ũ " << availableInk << endl;
}

InkPrinter::InkPrinter(string model, string manufacturer, int availableCount, int availableInk)
{
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableInk = availableInk;
	
}

InkPrinter::InkPrinter()
{
}

InkPrinter::~InkPrinter()
{
}

class LazerPrinter : Printer
{
public:
	int availableToner;
	void PrintLaser(int pages);
	void LaserInfo();
	LazerPrinter(string model, string manufacturer, int availableCount, int availableToner);
	LazerPrinter();
	~LazerPrinter();

private:

};

void LazerPrinter::PrintLaser(int pages)
{
	if (availableCount - pages > 0)
	{
		availableCount -= pages;
		availableToner -= pages;
		printedCount += pages;
		cout << "����Ʈ �߽��ϴ�." << endl;
	}
	else
	{
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
}

void LazerPrinter::LaserInfo()
{
	cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "�� , ���� ��� " << availableToner << endl;
}

LazerPrinter::LazerPrinter(string model, string manufacturer, int availableCount, int availableToner)
{
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableToner = availableToner;
}

LazerPrinter::LazerPrinter()
{
}

LazerPrinter::~LazerPrinter()
{
}

void main() {
	InkPrinter a("officejet", "hp", 5, 10);
	LazerPrinter b("scx", "sam", 3, 20);
	char go;
	
	a.InkInfo();
	b.LaserInfo();

	while (true)
	{
		
		int sel = 0, count = 0;
		cout << "������(1:��ũ, 2:������)�� �ż� �Է�" << endl;
		cin >> sel >> count;

		if (sel == 1) {
			a.PrintInkJet(count);
		}
		else
		{
			b.PrintLaser(count);
		}
		a.InkInfo();
		b.LaserInfo();

		cout << "��� ����Ʈ? (y/n)" << endl;
		cin >> go;

		if (go != 'y') {
			break;
		}
		
	}
	

}
