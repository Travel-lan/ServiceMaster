# ServiceMaster
Описание

ServiceMaster — это кроссплатформенная утилита для управления установкой и конфигурацией сервисов MariaDB и Nginx с графическим (GTK) и консольным интерфейсами. Программа автоматически определяет операционную систему (поддерживает Ubuntu, Kali Linux, Debian, CentOS, Fedora) и предоставляет возможность управления сервисами через веб-интерфейс на основе Flask.
Особенности

    Поддержка дистрибутивов Linux: Ubuntu, Kali Linux, Debian, CentOS, Fedora.
    Поддержка Docker: установка MariaDB и Nginx в контейнеры Docker.
    Веб-интерфейс на Flask для установки и мониторинга сервисов.
    SSL-сертификаты через Let's Encrypt.
    Автоматическое обновление MariaDB и Nginx.
    Мониторинг ресурсов (CPU, RAM).
    Логирование с ротацией и уровнями важности (INFO, WARN, ERROR).
    Поддержка интернационализации (i18n).

Установка
Требуемые зависимости

Перед началом установки необходимо установить следующие зависимости:

bash

sudo apt-get update
sudo apt-get install -y libmariadb-dev libgtk-3-dev pkg-config docker.io python3-flask python3-certbot-nginx

Компиляция и запуск
Консольная версия:

bash

make console
sudo ./system_manager_console

GUI версия:

bash

make gui
sudo ./system_manager_gui

Веб-интерфейс:

bash

make web
python3 web_interface.py

Веб-интерфейс будет доступен по адресу http://localhost:5000.
Docker:

bash

make docker
sudo ./system_manager_docker

Использование
Консольные команды

    Установка MariaDB:

    bash

sudo ./system_manager_console install_mariadb

Установка Nginx:

bash

sudo ./system_manager_console install_nginx

Мониторинг ресурсов:

bash

    sudo ./system_manager_console monitor_mariadb
    sudo ./system_manager_console monitor_nginx

Веб-интерфейс

    Установка MariaDB и Nginx.
    Мониторинг состояния сервисов.
    Проверка нагрузки на CPU и RAM.
    Управление контейнерами Docker.

Логирование

Логи сохраняются в /var/log/system_manager.log и ротация логов настроена с помощью logrotate.

Пример конфигурации logrotate:

bash

/var/log/system_manager.log {
    daily
    rotate 7
    compress
    missingok
    notifempty
}

SSL-сертификаты через Let's Encrypt

Для установки SSL-сертификатов с использованием Let's Encrypt:

bash

sudo ./system_manager_console setup_ssl example.com

Тестирование

Проект поддерживает автоматические тесты для установки сервисов.

Для запуска тестов:

bash

make test

Авторы и лицензия

ServiceMaster распространяется под лицензией MIT.
