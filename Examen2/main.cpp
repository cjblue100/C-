#include "stack.h"
#include <conio.h>
int main()
{
	stack val;

	val.push(2, "carlo");
	val.push(3, "selvin");
	val.push(4, "muerie");


	val.pop();
	val.print();
	val.saveFile();

	_getch();
}