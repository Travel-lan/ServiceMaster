#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

// Функции установки и проверки MariaDB и Nginx
int install_mariadb();
int install_nginx();
int check_service_installed(const char *service);
int detect_os();
int check_superuser_permissions();

// Функции инициализации базы данных
int initialize_database();
int store_data_in_database(const char *data);

// Функции для работы с Nginx
int configure_nginx();

// Логирование и обработка ошибок
void log_action(const char *action);
void handle_error(const char *error);

#endif // SYSTEM_MANAGER_H
