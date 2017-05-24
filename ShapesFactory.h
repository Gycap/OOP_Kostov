#pragma once
#include "Shapes.h"
#include <stdio.h>
#include "iostream"

using namespace std;

class ShapesFactory
{
public:
	static Point CreatePoint()
	{
		Point p1(rand(), rand());
		cout << p1 << endl;
		return p1;
	}
	static Circle CreateCircle()
	{
		Circle c1(rand(), rand(), rand());
		cout << c1 << endl;
		return c1;
	}
	static Rect CreateRectangle()
	{
		Rect r1(rand(), rand(), rand(), rand());
		cout << r1 << endl;
		return r1;
	}
	static Square CreateSquare()
	{
		Square sq1(rand(), rand(), rand());
		cout << sq1 << endl;
		return sq1;
	}
	static const Polyline& CreatePolyline()
	{
		int points_num = rand() % 20 + 1;
		Container <Point> line;
		for (int i = 0; i < points_num; i++)
		{
			line.AddEnd(ShapesFactory::CreatePoint());
		}
		Polyline line_out(line, points_num);
		cout << line_out << endl;
		return line_out;
	}
	/*static const Polygon& CreatePolygon()
	{
		int points_num = rand() % 20 + 1;
		Container <Point> line;
		
	}*/
};
