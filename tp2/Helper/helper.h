#ifndef HELPER_H
#define HELPER_H


//* Couleurs 
// Reset
#define RESET   "\033[0m"

// Text colors
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bold text
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"

// Backgrounds
#define BGRED    "\033[41m"
#define BGGREEN  "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE   "\033[44m"


//* Fonctions

// Flag global pour activer/désactiver le debug
bool DEBUG = true;



// Niveaux de log
typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG_LEVEL
} LogLevel;


// Macro pratique pour ne pas écrire file/func/line à chaque fois
#define LOG(lvl, fmt, ...) log_msg(lvl, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)

#endif // HELPER_H