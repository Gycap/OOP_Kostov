#include <iostream>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"
#include "ShapesFactory.h"
#include "conio.h"
#include <stdlib.h>
#include <time.h>

using namespace std;		//Открываем пр-во имён iostream.h

int main()
{
	std::srand((unsigned int)time(0));

	Container <Shape> ContShapes;
	for (int i = 0; i < 20; i++)
	{
		int VarShape = rand()%5 + 1;
		switch (VarShape)
		{
			case 1:ContShapes.AddEnd(ShapesFactory::CreatePoint()); break;
			case 2:ContShapes.AddEnd(ShapesFactory::CreateCircle()); break;
			case 3:ContShapes.AddEnd(ShapesFactory::CreateRectangle()); break;
			case 4:ContShapes.AddEnd(ShapesFactory::CreateSquare()); break;
			case 5:ContShapes.AddEnd(ShapesFactory::CreatePolyline()); break;
			//case 6:ContShapes.AddBegin(ShapesFactory::CreatePolygon()); break;
			default: break;
		}
	}
	cout << "\n" << "Shapes in Container: " << Shape::GetCount() << endl;
	for (int i = 0; i < 20; i++)
		ContShapes.DelFirst();
	cout << "\n" << "Shapes in Container after cleaning: " << Shape::GetCount() << endl;

	_getch();
	return 0;
}