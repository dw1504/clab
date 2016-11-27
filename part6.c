#include <stdio.h>
#include <assert.h>

//extract the 8-bit exponent field of single precision floating point number f 
//and return it as an unsigned byte
unsigned char
get_exponent_field(float f) 
{
	//return the exponent field of a flating point number
	unsigned int *temp = (unsigned int*)&f; //assign the address of f to temp
	*temp = *temp>>23; //push 23 position to the left so that the next 8 bits is the exponent part
	return *temp;
	//assert(0);
}

//clear the most significant b bits of unsigned integer number
//return the resulting value
//As an example, suppose unsigned int number = 0xffff0000; int b= 15
//then the correct return value is 65536
//if b = 30, then the return value is 0
//if b = 40, the return value should also be zero
unsigned int
clear_msb(unsigned int number, int b)
{
	unsigned int *temp = (unsigned int*)&number; //get the address of number 
	*temp = *temp <<b; //push to the right by b bits so these bits becomes 0
	*temp = *temp >>b; //pushes back so that the bits are in their original position 
	return *temp;
	//assert(0);
}

//given an array of bytes whose length is array_size (bytes), treat it as a bitmap (i.e. an array of bits),
//and return the bit value at index i (from the left) of the bitmap.
//As an example, suppose char array[3] = {0x00, 0x1f, 0x12}, the corresponding
//bitmap is 0x001f12, thus,
//the bit at index 0 is bitmap[0] = 0
//the bit at index 1 is bitmap[1] = 0
//...
//the bit at index 11 is bitmap[11] = 1
//the bit at index 12 is bitmap[12] = 1
//...
//the bit at index 16 is bitmap[16] = 0
//...
unsigned char
bit_at_index(unsigned char *array, int array_size, int i)
{
	int index = i/8; //find the index in the array 
	int position = i%8; //find the position of element
	unsigned char value = array[index]; //get the number in that index
	value = value <<(position); //push by the number of position to clear everything on the left 
	value = value >> 7; //push the element all the way to the right so that everything on the left is 0
	return value;
	//assert(0);
}
