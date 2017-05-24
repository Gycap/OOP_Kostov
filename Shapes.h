#pragma once
#include "algorithm"
#include "iostream"
#include "math.h"
#include "Base.h"
#include "Container.h"

const double PI = 3.1415926535;

class Point : public Shape, public Named
{
public:
	double x, y;
	Point () : Named("Point")
	{
		x = 0;
		y = 0;
	}

	Point(const double &x1, const double &y1) : Named("Point")
	{
		x = x1;
		y = y1;
	}
	
	std::string Print() const
	{
		return "\n" + this->GetName() + ": (" + std::to_string(this->x) + "," + std::to_string(this->y) + ")\n";
	}
	friend std::ostream& operator<<(std::ostream& out, Point& p1)
	{
		return out << p1.Print();
	}
};

class Circle : public Shape, public Named
{
private:
	double x, y, rad, area;
public:
	Circle() : Named("Circle")
	{}

	Circle(const double &x1, const double &y1, const double &rad1) : Named("Circle")
	{
		x = x1;
		y = y1;
		rad = rad1;
		area = 2 * PI * rad * rad;
	}

	std::string Print() const
	{
		return "\n" + this->GetName() + ": Center: (" + std::to_string(this->x) + "," + std::to_string(this->y) + ") Radius:" + std::to_string(this->rad) + " Area: " + std::to_string(this->area) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& out, Circle& c1)
	{
		return out << c1.Print();
	}
};

class Rect : public Shape, public Named
{
private:
	Point p1, p2;
	double side1, side2, area;
public:
	Rect() : Named("Rectangle")
	{}

	Rect(const double &x1, const double &y1, const double &x2, const double &y2) : Named("Rectangle")
	{
		//First point is the upper one
		//if (x1 > x2 || y1 < y2) throw "Incorrect rectangle input";
		p1 = Point(x1, y1);
		p2 = Point(x2, y2);
		side1 = p1.x - p2.x;
		side2 = p1.y - p2.y;
		area = side1 * side2;
	}

	std::string Print() const
	{
		return "\n" + this->GetName() + ": First side: " + std::to_string(this->side1) + " Second side: " + std::to_string(this->side2) + " Area: " + std::to_string(this->area) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& out, Rect& r1)
	{
		return out << r1.Print();
	}
};

class Square : public Shape, public Named
{
private:
	Point p;
	double side, area;
public:
	Square() : Named("Square")
	{}

	Square(const double &x1, const double &y1, const double &side1) : Named("Square")
	{
		p = Point(x1, y1);
		side = side1;
		area = side1 * side1;
	}

	std::string Print() const
	{
		return "\n" + this->GetName() + ": Side:" + std::to_string(this->side) + " Area: " + std::to_string(this->area) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& out, Square& sq1)
	{
		return out << sq1.Print();
	}
};

class Polyline : public Shape, public Named
{
private:
	Container <Point> polyline1;
	double length;
public:
	Polyline() : Named("Polyline")
	{
		polyline1.AddBegin(Point());
		length = 0;
	}

	Polyline(Container<Point>& pl1, const int& size) : Named("Polyline")
	{
		length = 0;
		pl1.StartIteration();
		AddPoint(pl1.GetFirst());
		for (int i = 1; i < size; i++)
		{
			AddPoint(*pl1.Iteration());
		}
	}

	void AddPoint(const Point& p2)
	{
		if (this->polyline1.IsEmpty())
		{
			this->polyline1.AddEnd(p2);
			return;
		}
		else
		{
			double x_prev, y_prev;
			x_prev = this->polyline1.GetLast().x;
			y_prev = this->polyline1.GetLast().y;
			this->polyline1.AddEnd(p2);
			this->length += sqrt( (x_prev - p2.x) * (x_prev - p2.x) + (y_prev - p2.y) * (y_prev - p2.y) );
		}
	}

	std::string Print() const
	{
		return "\n" + this->GetName() + ": Length: " + std::to_string(this->length) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& out, Polyline& pl1)
	{
		return out << pl1.Print();
	}
};
/*
class Polygon : public Shape, public Named
{
private:
	Container<Point> polygon1;
	double perimeter;
public:
	Polygon() : Named("Polygon")
	{
		polygon1.AddBegin(Point());
		perimeter = 0;
	}
	

	std::string Print() const
	{
		return "\n" + this->GetName() + " Perimeter: " + std::to_string(this->perimeter) + "\n";
	}
	friend std::ostream& operator<<(std::ostream& out, Polygon& pol1)
	{
		return out << pol1.Print();
	}
};*/