#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "system_manager.h"

// Проверка прав суперпользователя
int check_superuser_permissions() {
    if (geteuid() != 0) {
        fprintf(stderr, "Ошибка: требуются права суперпользователя.\n");
        return 0;
    }
    return 1;
}

// Проверка дистрибутива
int detect_os() {
    FILE *os_file = fopen("/etc/os-release", "r");
    if (!os_file) {
        perror("Не удалось открыть /etc/os-release");
        return -1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), os_file)) {
        if (strstr(buffer, "ID=ubuntu")) {
            fclose(os_file);
            return 1;  // Ubuntu
        } else if (strstr(buffer, "ID=kali")) {
            fclose(os_file);
            return 2;  // Kali Linux
        } else if (strstr(buffer, "ID=debian")) {
            fclose(os_file);
            return 3;  // Debian
        } else if (strstr(buffer, "ID=centos")) {
            fclose(os_file);
            return 4;  // CentOS
        } else if (strstr(buffer, "ID=fedora")) {
            fclose(os_file);
            return 5;  // Fedora
        }
    }

    fclose(os_file);
    return -1;  // Неизвестная ОС
}

// Установка MariaDB
int install_mariadb() {
    int os_type = detect_os();
    if (os_type == -1) {
        handle_error("Неизвестная операционная система");
        return -1;
    }

    if (check_service_installed("mariadb-server")) {
        printf("MariaDB уже установлена.\n");
        return 0;
    }

    printf("Установка MariaDB...\n");
    int result;
    if (os_type == 1 || os_type == 3) {
        result = system("apt-get update && apt-get install -y mariadb-server");
    } else if (os_type == 4 || os_type == 5) {
        result = system("yum install -y mariadb-server");
    }

    if (result != 0) {
        handle_error("Не удалось установить MariaDB");
        return -1;
    }

    return 0;
}

// Установка Nginx
int install_nginx() {
    int os_type = detect_os();
    if (os_type == -1) {
        handle_error("Неизвестная операционная система");
        return -1;
    }

    if (check_service_installed("nginx")) {
        printf("Nginx уже установлен.\n");
        return 0;
    }

    printf("Установка Nginx...\n");
    int result;
    if (os_type == 1 || os_type == 3) {
        result = system("apt-get update && apt-get install -y nginx");
    } else if (os_type == 4 || os_type == 5) {
        result = system("yum install -y nginx");
    }

    if (result != 0) {
        handle_error("Не удалось установить Nginx");
        return -1;
    }

    return 0;
}
