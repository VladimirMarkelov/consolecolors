#ifndef CON_COLORS_VM
#define CON_COLORS_VM

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#include <windows.h>
#else
#define COLOR_FMT_SIZE 8
#endif

typedef struct teminal_info_t {
#ifdef _WIN32
    HANDLE std_console;
    CONSOLE_SCREEN_BUFFER_INFO console_info;
#else
    int dummy;
#endif
} TerminalInfo;

typedef enum term_color_t {
    COLOR_NONE = -1,
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_YELLOW = 6,
    COLOR_WHITE = 7,
    COLOR_BRIGHT = 8
} TerminalColor;

TerminalInfo* console_init();
int console_reset_colors(TerminalInfo* ti);
int console_set_colors(TerminalInfo* ti, TerminalColor fg, TerminalColor bg);
int console_set_fg_color(TerminalInfo* ti, TerminalColor fg);
int console_set_bg_color(TerminalInfo* ti, TerminalColor bg);

#ifdef __cplusplus
}
#endif

#endif
