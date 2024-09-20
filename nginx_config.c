#include <stdio.h>
#include <stdlib.h>
#include "system_manager.h"

// Установка SSL через Let's Encrypt
int setup_ssl(const char* domain) {
    printf("Установка SSL для домена %s через Let's Encrypt...\n", domain);
    char command[512];
    snprintf(command, sizeof(command), "sudo apt-get install certbot python3-certbot-nginx -y && sudo certbot --nginx -d %s", domain);
    int result = system(command);

    if (result != 0) {
        handle_error("Ошибка установки SSL");
        return -1;
    }
    printf("SSL успешно установлен.\n");
    return 0;
}
