#include <fcntl.h>
#include <string.h>

/* 
 * Twistlock print hack
 * Seems it needs only 70 characters per file for the vulnerability to take effect 
 * Also using fraction slash (unicode) because for obvious reasons can't use forward slash in filenames
 */

#define TWISTLOCK "_________         _________ _______ _________ _        _______  _______  _       \n" \
"\\__   __⁄|\\     ⁄|\\__   __⁄(  ____ \\\\__   __⁄( \\      (  ___  )(  ____ \\| \\    ⁄\\\n" \
"   ) (   | )   ( |   ) (   | (    \\⁄   ) (   | (      | (   ) || (    \\⁄|  \\  ⁄ ⁄\n" \
"   | |   | | _ | |   | |   | (_____    | |   | |      | |   | || |      |  (_⁄ ⁄ \n" \
"   | |   | |( )| |   | |   (_____  )   | |   | |      | |   | || |      |   _ (  \n" \
"   | |   | || || |   | |         ) |   | |   | |      | |   | || |      |  ( \\ \\ \n" \
"   | |   | () () |___) (___⁄\\____) |   | |   | (____⁄\\| (___) || (____⁄\\|  ⁄  \\ \\\n" \
"   )_(   (_______)\\_______⁄\\_______)   )_(   (_______⁄(_______)(_______⁄|_⁄    \\⁄"

#define CLEARSCREEN "\e[2J\e[1;1H"
#define COLORFORMAT "\e[48;5;135;m\e[97m" /* Purple background and white foreground */
#define ENDFORMAT "\e[0m"

int main()
{
        const char twistlock[] = CLEARSCREEN COLORFORMAT TWISTLOCK ENDFORMAT;
        char next[71] = {0};

        for (int i = 0; i < sizeof(twistlock); i+=70)
        {
            strncpy(next, twistlock + i, 70);
            open(twistlock, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
        }

        return 0;
}

