#include <stdio.h>
#include <stdlib.h>
#include "system_manager.h"

int configure_nginx() {
    printf("Настройка Nginx...\n");

    int os_type = detect_os();
    if (os_type == -1) {
        handle_error("Неизвестная операционная система");
        return -1;
    }

    int result;
    if (os_type == 1) {
        result = system("echo 'server { listen 80; server_name localhost; location / { root /var/www/html; } }' > /etc/nginx/sites-available/default");
    } else if (os_type == 2) {
        result = system("echo 'server { listen 80; server_name localhost; location / { root /var/www/html; } }' > /etc/nginx/nginx.conf");
    }

    if (result != 0) {
        handle_error("Ошибка настройки Nginx");
        return -1;
    }

    result = system("systemctl restart nginx");
    if (result != 0) {
        handle_error("Ошибка перезапуска Nginx");
        return -1;
    }

    printf("Nginx успешно настроен и перезапущен.\n");
    return 0;
}
