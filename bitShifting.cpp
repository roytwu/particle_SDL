#include <iostream>
#include <iomanip> //setw, setfill
using std::cout;
using std::endl;
using std::hex;
using std::setw;
using std::setfill;

int main(){
	//oxFF123456
	//0 to 255 is equivalent to 00 to FF in hex
	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;

	unsigned int color = 0; //32 bit (4 byte) value
	/* put alpha, read, green, blue in 1 byte value, so
	in total, 4 bytes are required */


	color = color + alpha; // equivalent to color+=alpha
	color = color << 8;  //equivalent to color<<=8

	color += red;
	color <<= 8;

	color += green;
	color <<= 8; 

	color += blue;

	cout << setfill('0') << setw(8) << hex << color << endl;
	return 0;
}
