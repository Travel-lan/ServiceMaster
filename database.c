#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>  // Измененный путь для MariaDB
#include "system_manager.h"

// Инициализация базы данных
int initialize_database() {
    MYSQL *conn;
    conn = mysql_init(NULL);
    
    if (conn == NULL) {
        handle_error("Ошибка инициализации MySQL");
        return -1;
    }

    if (mysql_real_connect(conn, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL) {
        handle_error("Ошибка подключения к MySQL");
        mysql_close(conn);
        return -1;
    }

    if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS system_manager_db")) {
        handle_error("Ошибка создания базы данных");
        mysql_close(conn);
        return -1;
    }

    mysql_close(conn);
    printf("База данных успешно инициализирована.\n");
    return 0;
}

// Запись данных в базу
int store_data_in_database(const char *data) {
    MYSQL *conn;
    conn = mysql_init(NULL);

    if (conn == NULL) {
        handle_error("Ошибка инициализации MySQL");
        return -1;
    }

    if (mysql_real_connect(conn, "localhost", "root", "password", "system_manager_db", 0, NULL, 0) == NULL) {
        handle_error("Ошибка подключения к MySQL");
        mysql_close(conn);
        return -1;
    }

    char query[512];
    snprintf(query, sizeof(query), "INSERT INTO logs (data) VALUES ('%s')", data);
    if (mysql_query(conn, query)) {
        handle_error("Ошибка вставки данных в базу");
        mysql_close(conn);
        return -1;
    }

    mysql_close(conn);
    return 0;
}

