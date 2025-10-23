#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "helper.h"




// Fonction principale de log
void log_msg(LogLevel lvl, const char *file, const char *func, int line, const char *format, ...) {
    if (!DEBUG && lvl == DEBUG_LEVEL)
        return; // ne rien afficher si debug désactivé et niveau debug

    const char *color;
    const char *label;

    switch(lvl) {
        case INFO:        color = GREEN;  label = "INFO"; break;
        case WARNING:     color = YELLOW; label = "WARN"; break;
        case ERROR:       color = RED;    label = "ERROR"; break;
        case DEBUG_LEVEL: color = CYAN;   label = "DEBUG"; break;
        default:          color = RESET;  label = ""; break;
    }

    printf("%s[%s] %s:%d:%s(): ", color, label, file, line, func);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf(RESET "\n"); // remise à zéro de la couleur
}


