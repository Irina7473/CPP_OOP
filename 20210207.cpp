#include<iostream>
#include<Windows.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	HPEN red_pen = CreatePen(PS_SOLID, 5, RGB(200, 00, 0));
	HPEN green_pen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	HPEN blue_pen = CreatePen(PS_SOLID, 5, RGB(0, 00, 200));

	HBRUSH red_brush = CreateSolidBrush(RGB(200, 0, 0));
	HBRUSH green_brush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH blue_brush = CreateSolidBrush(RGB(0, 0, 200));

	SelectObject(hdc, green_pen);
	SelectObject(hdc, green_brush);
	Rectangle(hdc, 10, 10, 100, 100);

	SelectObject(hdc, red_pen);
	SelectObject(hdc, red_brush);
	POINT points[] =
	{
		{200, 100},
		{300, 10},
		{400, 100}
	};
	Polygon(hdc, points, sizeof(points) / sizeof(POINT));

	SelectObject(hdc, blue_pen);
	SelectObject(hdc, blue_brush);
	Ellipse(hdc, 500, 10, 600, 100);

	DeleteObject(blue_pen);
	DeleteObject(green_pen);
	DeleteObject(red_pen);
	ReleaseDC(hwnd, hdc);

	cout << "\n\n\n\n\n\n\n\n";
	cin.get();
}