
#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

// Функции установки и проверки MariaDB и Nginx
int install_mariДля улучшения проекта **ServiceMaster**, сделаны следующие изменения:

1. **Makefile**: добавлена поддержка Docker, веб-интерфейса и тестов.
2. **install_services.c**: добавлена поддержка различных дистрибутивов Linux.
3. **nginx_config.c**: добавлена установка SSL через Let's Encrypt.
4. **docker_support.c**: добавлена установка MariaDB и Nginx в контейнеры Docker.
5. **web_interface.py**: создан Flask веб-интерфейс для управления сервисами.
6. **logging.c**: добавлена система логирования с уровнями важности.
7. **test_install_services.c**: добавлены тесты для установки сервисов.

Пожалуйста, скопируйте код из каждого раздела и добавьте его в соответствующие файлы проекта.
