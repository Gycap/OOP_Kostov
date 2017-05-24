#pragma once
#include "string"

class Printable
{
public:
	Printable()
	{}
	
	virtual std::string Print() const = 0;

	~Printable()
	{}
};

class Named : public Printable
{
public:
	std::string name;
	Named(const std::string &name1)
	{
		name = name1;
	};

	std::string Print() const
	{
		return name;
	}

	virtual std::string GetName() const
	{
		return this->name;
	}
};

class Shape : public Printable
{
public:
	static int count;
	Shape()
	{
		++count;
	}

	Shape(const Shape& shape1)
	{
		++count;
	}

	static int GetCount() 
	{
		return count;
	}

	std::string Print() const
	{
		return "Shape";
	}

	~Shape()
	{
		--count;
	}
};
int Shape::count = 0;