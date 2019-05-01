#ifndef KMAIN
#define KMAIN

/* Color definitions start here */
#define CLOR_BLACK			0			// Black 
#define CLOR_BLUE			1			// Blue
#define CLOR_GREEN			2			// Green
#define CLOR_CYAN			3			// Cyan
#define CLOR_RED			4			// Red
#define CLOR_MAGE			5			// Magenta
#define CLOR_BROWN			6			// Brown
#define CLOR_LGREY			7			// Light Grey
#define CLOR_DGREY			8			// Dark Grey
#define CLOR_LBLUE			9			// Light Blue
#define CLOR_LGREEN			10			// Light Green
#define CLOR_LCYAN			11			// Light Cyan
#define CLOR_LRED			12			// Light Red
#define CLOR_LMAGE			13			// Light Magenta
#define CLOR_LBROWN			14			// Light Brown
#define CLOR_WHITE			15			// Light white
/* Color definitions end here */

/* I/O ports start here */
#define FB_COMMAND_PORT			0x3D4
#define FB_DATA_PORT			0x3D5
/* I/O ports end here */

/* I/O port commands start here */
#define FB_HIGH_BYTE_COMMAND	14
#define FB_LOW_BYTE_COMMAND		15
/* I/O port commands ends here */
#endif
