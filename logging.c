#include <stdio.h>
#include <time.h>
#include "system_manager.h"

// Функция логирования с уровнями важности
void log_action(const char *action, const char *level) {
    FILE *log_file = fopen("/var/log/system_manager.log", "a");
    if (log_file != NULL) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] %s: %s\n", level, ctime(&now), action);
        fclose(log_file);
    }
}

// Обработка ошибок и запись в лог
void handle_error(const char *error) {
    log_action(error, "ERROR");
    fprintf(stderr, "Ошибка: %s\n", error);
}
