#include <stdio.h>
#include <stdlib.h>
#include "system_manager.h"

// Установка MariaDB в контейнере Docker
int install_mariadb_docker() {
    printf("Установка MariaDB в Docker...\n");
    int result = system("docker run --name mariadb -e MYSQL_ROOT_PASSWORD=password -d mariadb:latest");
    if (result != 0) {
        handle_error("Ошибка установки MariaDB в Docker");
        return -1;
    }
    printf("MariaDB успешно установлена в Docker.\n");
    return 0;
}

// Установка Nginx в контейнере Docker
int install_nginx_docker() {
    printf("Установка Nginx в Docker...\n");
    int result = system("docker run --name nginx -p 80:80 -d nginx:latest");
    if (result != 0) {
        handle_error("Ошибка установки Nginx в Docker");
        return -1;
    }
    printf("Nginx успешно установлен в Docker.\n");
    return 0;
}
