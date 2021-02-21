#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius;
public:
	double getradius()const { return radius; }
	void setradius(double radius) {(radius >= 0)? this->radius = radius : radius = 0;}

	Circle() : Circle(Color(rand() % (12 - 7 + 1) + 7), (rand() % (8 - 2 + 1) + 2))
	{cout << "Создан круг радиусом " << radius << endl;}
	Circle(Color color, double radius) : Shape(color) {setradius(radius);}
	~Circle() {}

	double getarea()const { return (radius* radius*3.14); }
	double getperimetr()const { return (radius*2*3.14); }

	void draw()const 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, getcolor());
		PAINTSTRUCT ps;

		HWND hWnd = GetConsoleWindow(); //static_cast<HWND>(Handle.ToPointer());
		HDC hdc = GetDC(hWnd);//BeginPaint(hWnd, &ps);
		//HPEN hPen = CreatePen(PS_DASHDOTDOT, 2, NULL);
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0,0,255));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 200, 200, 400, 400);
			
		DeleteObject(hBrush);
		DeleteObject(hPen);
		//EndPaint(hWnd, &ps);
		ReleaseDC(hWnd, hdc);
		SetConsoleTextAttribute(hConsole, Color::defaultColor);
	}

};

/*
for (int i = -radius; i <= radius; i++)
		{
			for (int j = -radius; j <= radius; j++)
			{
				if (sqrt(i*i+j*j)<=radius*1,05) cout << "*";
				else cout << " ";
			}
			cout << endl;
		}



for (int i = 0; i < radius*2; i++)
		{
			for (int j = 0; j < (radius * 4 - 3); j++)
			{
				if (((i == 0 || i == radius * 2 - 1) && j > (radius) && j < (radius * 3 - 4))
					|| (i < radius && j >= (radius - i - 1) && j < (radius * 3 - 2 + i))
					|| (i >= radius && j >= abs((radius - i)) && j < (radius * 4 - i)))
					cout << "*";
				else cout << " ";
			}
			cout << endl;
		}
*/