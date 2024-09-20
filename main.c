#include <stdio.h>
#include <string.h>
#include "system_manager.h"

#ifndef USE_GUI  // Только если не используется GUI

int main() {
    if (!check_superuser_permissions()) {
        return 1;
    }

    // Определение ОС и вывод сообщения
    int os_type = detect_os();
    if (os_type == 1) {
        printf("Вы используете Ubuntu.\n");
    } else if (os_type == 2) {
        printf("Вы используете Kali Linux.\n");
    } else {
        printf("Неизвестная операционная система.\n");
        return 1;
    }

    // Установка и проверка сервисов
    if (install_mariadb() != 0) {
        return 1;
    }

    if (install_nginx() != 0) {
        return 1;
    }

    // Инициализация базы данных и настройка Nginx
    if (initialize_database() != 0) {
        return 1;
    }

    if (configure_nginx() != 0) {
        return 1;
    }

    printf("MariaDB и Nginx успешно установлены и настроены.\n");

    char command[256];
    while (1) {
        printf("\nВведите команду (или 'exit' для выхода): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Пример использования команды для записи данных в базу данных
        if (strncmp(command, "log", 3) == 0) {
            store_data_in_database(command + 4);
        } else {
            printf("Неизвестная команда.\n");
        }
    }

    return 0;
}

#endif  // Завершение блока USE_GUI
