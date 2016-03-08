# Console Colors
Crossplatform library for colored text output in terminal window.
Works on Microsoft Windows and Linux(Ubuntu).

# API

## enum TerminalColor
There are 7 available colors and brightness attribute, so 16 colors in total.
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
To set a bright color combine color value with attribute COLOR_BRIGHT. E.g, bright green is COLOR_GREEN | COLOR_BRIGHT


## TerminalInfo* console_init();
Initalizes library. At this moment the function makes sense only for Windows. On Linux you can skip library initialization and call other library functions directly using NULL as the first argument. On Windows the call is obligatory, it gets the current console handle and saves the current console colors to use it in console_reset_colors.
Retunrs pointer to initialized TerminalInfo structure or NULL if getting console info failed. The latter may happen, e.g, if console output is redirected.

## int console_reset_colors(TerminalInfo* ti);
Changes console colors to colors that were used at the application start.

## int console_set_colors(TerminalInfo* ti, TerminalColor fg, TerminalColor bg);
Changes the current foreground and background terminal colors. Passing COLOR_NONE as an arguments means that the color should not be changed, so console_set_colors(ti, COLOR_GREEN, COLOR_NONE) means the same as console_set_fg_color(ti, COLOR_GREEN).
Returns error code (on Linux the function is always successful):
0 - No errors;
1 - Console is not available (Either TerminalInfo* is uninitialized or getting console info failed. The latter may happen, e.g, if console output is redirected)

## int console_set_fg_color(TerminalInfo* ti, TerminalColor fg);
Changes only foreground terminal color. Returns the same error as console_set_colors.

## int console_set_bg_color(TerminalInfo* ti, TerminalColor bg);
Changes only background terminal color. Returns the same error as console_set_colors.
