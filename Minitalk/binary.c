#include <stdio.h>
#include <unistd.h>

void    print_bits(unsigned char octet)
{
   int i;

   for (i = 7; i >= 0; i--)
   {
        if (octet & (1 << i))
            write (1, "1", 1);
        else
            write (1, "0", 1);
   }
   write(1,"\n", 1);
}
int main(void)
{
    int encoded_data = 0b1010101101101;

    int value1 = (encoded_data >> 8) & 0xFF;
    int value2 = (encoded_data >> 4) & 0xF;
    int value3 = encoded_data & 0xF;
    print_bits(value3);
    printf("Decoded Values: %d %d %d\n", value1, value2, value3);

}