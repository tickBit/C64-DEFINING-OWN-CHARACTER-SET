#include <conio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <cc65.h>
#include <cbm.h>
#include <6502.h>

/*
 User defined multicolor characters..

 Based on a BASIC program I've made as kid.
 I will try to later check from my old books, what those POKEs mean.. :-)
 ..and comment the source better... I hope I find the info...

*/

const unsigned char charset[] =
{
    85,66,66,66,66,66,66,106
};

int main (void) {

    unsigned i;
    unsigned s;
    unsigned x;

    // background color
    POKE(53281U,(unsigned char)15);

    POKE(53272U,(PEEK(53272U) & (unsigned char)240) | (unsigned char)12);
    

    POKE(56334U,(unsigned char)0);
    POKE(1U,(unsigned char)51);

    for (i = 0; i < 512; i++) {
        POKEW(12288U+i,PEEKW(53248U+i));
    }

    POKE(1U,(unsigned char)55);
    POKE(56334U,(unsigned char)1);
    POKE(53270U,(unsigned char)24);
    POKE(53282U,(unsigned char)1);
    POKE(53283U,(unsigned char)0);
   
    for (s = 0; s < 8; s++) {
        POKEW(12288U+s,charset[s]);
    }


    for (x = 0; x < 500; x++) {
        POKEW(1024U+x,0);
        POKEW(2023U-x,0);
        waitvsync();
    }

    while (0 == 0) {
        waitvsync();
        if (PEEK(197) == 60) return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;

}