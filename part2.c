#include <assert.h>

// Swap the values of the integer variables pointed to by p1 and
// p2.  After the function returns, the variable pointed to by p1
// should have the value once pointed to by p2, and vice-versa.
//
// You may use a temporary variable or do an XOR swap.
void
swap(int *p1, int *p2)
{
	assert(p1 != 0);
	assert(p2 != 0);

	// swapping two values 
	int temp = *p1;  //create a temporary place for p1
	*p1 = *p2;
	*p2 = temp;
	//assert(0);
}
