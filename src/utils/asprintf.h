#ifndef ASPRINTF_H
#define ASPRINTF_H

#include <stdarg.h>

int vscprintf(const char *format, va_list ap);
int vasprintf(char **strp, const char *format, va_list ap);
int asprintf(char **strp, const char *format, ...);

#endif // ASPRINTF_H