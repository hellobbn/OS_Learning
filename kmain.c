#include "kmain.h"
#include "io.h"

/** fb_write_cell:
 *  Writes a character with the given foreground and 
 *  background to position in the framebuffer.
 *
 *  @param i:	The location in the framebuffer
 *  @param c:	The character
 *  @param fg:	Foreground color
 *  @param bg:	Background color
 *
 *  Note: char in 32-bit system has only 1 byte, so we
 *        need 2 chars to form a character
 */
char* fb = (char*) 0x000B8000;
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg) {
	fb[2 * i] = c;
	fb[2 * i + 1] = ((fg & 0x0F) << 4 | (bg & 0x0F));
}

/** sum_of_three:
 *  Test function, which is used to test the call 
 *  from loader works properly.
 */
int sum_of_three(int arg1, int arg2, int arg3) {
	return arg1 + arg2 + arg3;
}

/** kmain:
 *  main kernel function
 */
void kmain(void) {
	fb_write_cell(1, 'A', CLOR_GREEN, CLOR_DGREY);
}

/** fb_move_cursor:
 *  Moves the cursor of the framebuffer to the given 
 *  position.
 *
 *  @param pos: The new position of the cursor
 */
void fb_move_cursor(unsigned short pos) {
		outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
		outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
		outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
		outb(FB_DATA_PORT, (pos & 0x00FF));
}
