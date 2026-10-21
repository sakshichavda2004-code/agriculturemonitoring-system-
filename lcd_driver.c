#include "header.h"

void lcd_init()
{
IODIR1 = 0xFE << 16; // Configure P1.16 - P1.23 as output
IOCLR1 = 1 << 19; // Ensure EN = 0 initially
lcd_cmd(0x02); // Return home / Reset LCD in 4-bit mode
lcd_cmd(0x28); // 4-bit, 2-line display, 5x7 dots format
lcd_cmd(0x0E); // Display ON, cursor ON
lcd_cmd(0x01); // Clear LCD display
}
void lcd_cmd(unsigned int cmd)
{
unsigned int temp;
IOCLR1 = 0xFE << 16; // Clear data pins and control pins
temp = (cmd & 0xF0) << 16; // Mask upper nibble & shift to P1.20-P1.23
IOSET1 = temp; // Output upper nibble first
IOCLR1 = 1 << 17; // RS = 0 -> Command register
IOCLR1 = 1 << 18; // RW = 0 -> Write operation
IOSET1 = 1 << 19; // EN = 1 -> Generate latch pulse
delay_ms(2);
IOCLR1 = 1 << 19; // EN = 0
// --------- Send Lower Nibble -------------
IOCLR1 = 0xFE << 16; // Clear pins
IOSET1 = (cmd & 0x0F) << 20; // Send lower nibble
IOCLR1 = 1 << 17; // RS = 0
IOCLR1 = 1 << 18; // RW = 0
IOSET1 = 1 << 19; // EN = 1
delay_ms(2);
IOCLR1 = 1 << 19; // EN = 0
}
void lcd_data(unsigned char data)
{
unsigned int temp;
IOCLR1 = 0xFE << 16; // Clear P1.16 to P1.22 (LCD data and control pins)
temp = (data & 0xF0) << 16; // Mask upper nibble & shift to P1.20-P1.23
IOSET1 = temp; // Send upper nibble to LCD
IOSET1 = 1 << 17; // RS = 1 -> Select data register
IOCLR1 = 1 << 18; // RW = 0 -> Write mode
IOSET1 = 1 << 19; // EN = 1 -> Enable pulse HIGH
delay_ms(2); // Short delay
IOCLR1 = 1 << 19; // EN = 0 -> Latch data
// --------- Send Lower Nibble -------------
IOCLR1 = 0xFE << 16; // Clear LCD data and control pins
IOSET1 = (data & 0x0F) << 20; // Mask lower nibble & send to P1.20-P1.23
IOSET1 = 1 << 17; // RS = 1 (data)
IOCLR1 = 1 << 18; // RW = 0 (write)
IOSET1 = 1 << 19; // EN = 1 (Enable pulse)
delay_ms(2);
IOCLR1 = 1 << 19; // EN = 0
}
void lcd_string(char *ptr)
{
        while(*ptr!=0)
        {
        lcd_data(*ptr);
        ptr++;
        }

}

