#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

using namespace std;

int main() {
	testAll();
    cout << "Short tests end" << endl;
    testAllExtended();

	cout << "Test end" << endl;
	system("pause");
}
