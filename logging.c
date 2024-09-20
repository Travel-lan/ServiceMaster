#include <stdio.h>
#include <time.h>
#include "system_manager.h"

void log_action(const char *action) {
    FILE *log_file = fopen("system_manager.log", "a");
    if (log_file != NULL) {
        time_t now = time(NULL);
        fprintf(log_file, "%s: %s\n", ctime(&now), action);
        fclose(log_file);
    }
}

void handle_error(const char *error) {
    log_action(error);
    fprintf(stderr, "Ошибка: %s\n", error);
}
