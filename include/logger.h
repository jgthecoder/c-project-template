#include <stdio.h>

#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} LogLevel;

// This provides a consistent way to print across the whole project
void log_msg(LogLevel level, const char* message);

#endif

#ifdef LOGGER_IMPLEMENTATION

void log_msg(LogLevel level, const char* message) {
    const char* label;
    switch (level) {
        case LOG_INFO:  label = "INFO"; break;
        case LOG_WARN:  label = "WARN"; break;
        case LOG_ERROR: label = "ERROR"; break;
        default:        label = "LOG";  break;
    }
    printf("[%s] %s\n", label, message);
}

#endif /* ifdef LOGGER_IMPLEMENTATION */
