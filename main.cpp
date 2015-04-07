#include "ISet.h"

int main(void)
{
	MySet < int > set1;

	int y = 5;

	set1.add(y);
	set1.remove(y);
	cout << set1.contains(y) << endl;

	cout << set1.size() << endl;
}