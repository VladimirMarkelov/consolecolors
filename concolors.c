#ifndef _WIN32
#include <stdio.h>
#endif

#include <stdlib.h>
#include "concolors.h"

TerminalInfo* console_init() {
    TerminalInfo* ti = (TerminalInfo*)calloc(1, sizeof(TerminalInfo));
#ifdef _WIN32
    ti->std_console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (ti->std_console != NULL) {
        if (! GetConsoleScreenBufferInfo(ti->std_console, &ti->console_info)) {
            ti->std_console = NULL;
        }
    }
#endif
    return ti;
}

int console_reset_colors(TerminalInfo* ti) {
#ifdef _WIN32
    if (ti == NULL) {
        return 1;
    }

    if (ti->std_console != NULL) {
        if (SetConsoleTextAttribute(ti->std_console, ti->console_info.wAttributes)) {
            return 0;
        }
        return 2;
    }

    return 3;
#else
    printf("\x1b[0m");
    return 0;
#endif
}

int console_set_fg_color(TerminalInfo* ti, TerminalColor fg) {
    return console_set_colors(ti, fg, COLOR_NONE);
}

int console_set_bg_color(TerminalInfo* ti, TerminalColor bg) {
    return console_set_colors(ti, COLOR_NONE, bg);
}

#ifdef _WIN32
static int windows_console_colors(TerminalInfo* ti, TerminalColor fg, TerminalColor bg) {
    WORD color = 0;
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (! GetConsoleScreenBufferInfo(ti->std_console, &info)) {
        return 1;
    }
    color = info.wAttributes;

    if (fg != COLOR_NONE) {
        color = (color & 0xFFF0) | fg;
    }
    if (bg != COLOR_NONE) {
        color = (color & 0xFF0F) | (bg << 4);
    }

    SetConsoleTextAttribute(ti->std_console, color);

    return 0;
}
#else
static int unix_console_colors(TerminalColor fg, TerminalColor bg) {
    char fgstr[COLOR_FMT_SIZE];
    char bgstr[COLOR_FMT_SIZE];
    char *fgbrightstr = "";

    int realcolor[] = {0, 4, 2, 6, 1, 5, 3, 7};

    if (fg == COLOR_NONE) {
        fgstr[0] = '\0';
    } else {
        snprintf(fgstr, COLOR_FMT_SIZE-1, "%d", 30+realcolor[(fg & COLOR_WHITE)]);
        if ((fg & COLOR_BRIGHT) == COLOR_BRIGHT) {
            fgbrightstr = ";1";
        }
    }

    if (bg == COLOR_NONE) {
        bgstr[0] = '\0';
    } else {
        if (fg != COLOR_NONE) {
            snprintf(bgstr, COLOR_FMT_SIZE-1, ";%d", 40+realcolor[(bg & COLOR_WHITE)]);
        } else {
            snprintf(bgstr, COLOR_FMT_SIZE-1, "%d", 40+(bg & COLOR_WHITE));
        }
    }

    printf("\x1b[0;%s%s%sm", fgstr, fgbrightstr, bgstr);
    return 0;
}
#endif

int console_set_colors(TerminalInfo* ti, TerminalColor fg, TerminalColor bg) {
    if (bg == COLOR_NONE && fg == COLOR_NONE) {
        return 0;
    }
#ifdef _WIN32
    return windows_console_colors(ti, fg, bg);
#else
    return unix_console_colors(fg, bg);
#endif
}

