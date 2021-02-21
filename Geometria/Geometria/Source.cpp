#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "TriangleEqual.h"
#include "TriangleRight.h"

using namespace std;
#define TAB "------------------------------\n"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
//	#define shapecheck
	#ifdef shapecheck
	Square square;
	cout << "������� - " << square.getarea() << ", �������� - "<< square.getperimetr () << endl;
	square.draw();
	cout << TAB;
	Rect rect;
	cout << "������� - " << rect.getarea() << ", �������� - " << rect.getperimetr () << endl;
	rect.draw();
	cout << TAB;
	Circle circle;
	cout << "������� - " << circle.getarea() << ", �������� - " << circle.getperimetr () << endl;
	circle.draw();
	cout << TAB;

	#endif shapecheck

#define circlecheck
#ifdef circlecheck
	Circle circle7(Color::red, 7);
	circle7.draw();
	
#endif circlecheck
	
//#define triangleAnycheck
#ifdef triangleAnycheck
	Triangle triangle1(Color::blue, 6, 8, 14);
	cout << "������� - " << triangle1.getarea() << ", �������� - " << triangle1.getperimetr() << endl;
	triangle1.draw();
	cout << TAB;
	Triangle triangle;
	cout << "������� - " << triangle.getarea() << ", �������� - " << triangle.getperimetr() << endl;
	triangle.draw();
	cout << TAB;
		
#endif triangleAnycheck

//#define triangleRightcheck
#ifdef triangleRightcheck
	TriangleRight triangleR1(Color::blue, 9, 6);
	cout << "������� - " << triangleR1.getarea() << ", �������� - " << triangleR1.getperimetr() << endl;
	triangleR1.draw();
	cout << TAB;
	TriangleRight triangleR;
	cout << "������� - " << triangleR.getarea() << ", �������� - " << triangleR.getperimetr() << endl;
	triangleR.draw();
	cout << TAB;

#endif triangleRightcheck
	
//#define triangleEqualcheck
#ifdef triangleEqualcheck
	TriangleEqual triangleE1(Color::red, 7);
	cout << "������� - " << triangleE1.getarea() << ", �������� - " << triangleE1.getperimetr() << endl;
	triangleE1.draw();
	cout << TAB;
	TriangleEqual triangleE;
	cout << "������� - " << triangleE.getarea() << ", �������� - " << triangleE.getperimetr() << endl;
	triangleE.draw();
	cout << TAB;

#endif triangleEqualcheck



	return 0;
}