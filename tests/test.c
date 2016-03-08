#include <stdio.h>
#include "concolors.h"

int main (int argc, char** argv) {
    TerminalInfo* ti = console_init(&ti);

    console_set_colors(ti, COLOR_BLUE, COLOR_GREEN);
    printf("Blue on Green");
    console_set_colors(ti, COLOR_RED, COLOR_BLACK);
    printf("\nRed on Black\n");
    console_set_colors(ti, COLOR_GREEN, COLOR_BLACK);
    printf("Green on Black\n");
    console_set_colors(ti, COLOR_CYAN, COLOR_BLACK);
    printf("Cyan on Black\n");
    console_set_colors(ti, COLOR_MAGENTA, COLOR_BLACK);
    printf("Magenta on Black\n");
    console_set_colors(ti, COLOR_YELLOW, COLOR_BLACK);
    printf("Yellow on Black\n");
    console_set_colors(ti, COLOR_BLACK, COLOR_WHITE);
    printf("Black on White");
    console_set_colors(ti, COLOR_GREEN|COLOR_BRIGHT, COLOR_BLUE|COLOR_BRIGHT);
    printf("\nBright Green on Blue");
    console_reset_colors(ti);
    printf("\nColors reset\n");

    return 0;
}
