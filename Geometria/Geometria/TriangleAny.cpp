#include "TriangleAny.h"
/*
void TriangleAny::setside1(double side1)
{(side1 >= 0) ? this->side1 = side1 : this->side1 = 0;}

void TriangleAny::setside2(double side2)
{(side2 >= 0) ? this->side2 = side2 : this->side2 = 0;}

void TriangleAny::setside3(double side3)
{
	if (side3 < (side1 + side2))  this->side3 = side3;
	else
	{
		cout << "������ ������� ������������ ������ ���� ������ ����� ���� ������, ���������� ������ ������� " << endl;
		this->side3 = rand() % (int(side1) + int(side2) - 1 - abs(int(side1) - int(side2))) + abs(int(side1) - int(side2)) + 1;
	}
}

TriangleAny::TriangleAny() : TriangleAny(Color(rand() % (12 - 7 + 1) + 7), (rand() % (14 - 4 + 1) + 4),
	(rand() % (14 - 4 + 1) + 4), (rand() % (14 - 4 + 1) + 4)) {}

TriangleAny::TriangleAny(Color color, double side1, double side2, double side3): Triangle(color, side1)
{
	setside1(side1);
	setside2(side2);
	setside3(side3);
	cout << this << " - ������ ����������� �� ��������� " << this->side1 << ", " << this->side2 << ", " << this->side3 << endl;
}

double  TriangleAny::maxside()const
{
	double max = side1;
	if (side2 > max) max = side2;
	if (side3 > max) max = side3;
	cout << "����� ������� ������� " << max << endl;
	return max;
}

double  TriangleAny::height(double side)const
{
	double p = getperimetr() / 2;
	double H = 2 * sqrt(p * (p - side1) * (p - side2) * (p - side3)) / side;
	cout << "������, ����������� � ������� " << side << "=" << H << endl;
	return H;
}
double  TriangleAny::getarea()const
{
	//return (side1 * height(side1) / 2); //������� ����� ������
	return side1 / 2 * sqrt(abs(pow(side2, 2) - pow(side1, 2))); //������� ����� ����� ������
}
double  TriangleAny::getperimetr()const { return side1 + side2 + side3; }

void  TriangleAny::draw()const
{
	//��� ���������� ������������ ������� ������ � ����� ������� ��� ������� � �������, �� ������� ������ �� �����
	double sidemax1, sidemax2, sidemax3;
	sidemax1 = maxside();  //����� ������� �������
	double H = height(sidemax1); //������ �  ����� ������� �������
	//��������������� ������ � ����������� �� ������������
	if (side1 == sidemax1)
	{
		sidemax2 = side2;
		sidemax3 = side3;
	}
	else if (side2 == sidemax1)
	{
		sidemax2 = side1;
		sidemax3 = side3;
	}
	else
	{
		sidemax2 = side2;
		sidemax3 = side1;
	}
	// �������, �� ������� ������ ����� ����� ������� �������
	double sidemax12 = sqrt(pow(sidemax2 ,2) - pow(H ,2));
	double sidemax13 = sqrt(pow(sidemax3, 2) - pow(H, 2));
	cout << "������ ����� ������� " << sidemax1 << " �� - " << sidemax12 << " � " << sidemax13 << endl;
	//������ ����� ��������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, getcolor());

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < int(sidemax1); j++)
		{
			if (i == 0 || j == int(sidemax12)
				|| (i == int(H / 2) && (j == (int(sidemax12 / 2) || j == int(sidemax12 + sidemax13 / 2)))
					|| (i == int(H / 4) && (j == int(sidemax12 / 4) || j == int(sidemax12 + sidemax13 * 3 / 4)))
					|| (i == int(H * 3 / 4) && (j == int(sidemax12 * 3 / 4) || j == int(sidemax12 + sidemax13 / 4)))))
				cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, Color::defaultColor);

}*/