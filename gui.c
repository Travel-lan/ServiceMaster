#include <gtk/gtk.h>
#include <stdlib.h>
#include "system_manager.h"

#ifdef USE_GUI  // Только если используется GUI

void on_mariadb_install_clicked(GtkWidget *widget, gpointer data) {
    if (install_mariadb() == 0) {
        g_print("MariaDB успешно установлена!\n");
    } else {
        g_print("Ошибка установки MariaDB\n");
    }
}

void on_nginx_install_clicked(GtkWidget *widget, gpointer data) {
    if (install_nginx() == 0) {
        g_print("Nginx успешно установлен!\n");
    } else {
        g_print("Ошибка установки Nginx\n");
    }
}

void on_configure_services_clicked(GtkWidget *widget, gpointer data) {
    if (configure_nginx() == 0) {
        g_print("Nginx успешно настроен!\n");
    } else {
        g_print("Ошибка настройки Nginx\n");
    }
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button_install_mariadb;
    GtkWidget *button_install_nginx;
    GtkWidget *button_configure_services;

    gtk_init(&argc, &argv);

    // Создание главного окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Управление сервисами");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Создание таблицы для размещения кнопок
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Кнопка для установки MariaDB
    button_install_mariadb = gtk_button_new_with_label("Установить MariaDB");
    g_signal_connect(button_install_mariadb, "clicked", G_CALLBACK(on_mariadb_install_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_install_mariadb, 0, 0, 1, 1);

    // Кнопка для установки Nginx
    button_install_nginx = gtk_button_new_with_label("Установить Nginx");
    g_signal_connect(button_install_nginx, "clicked", G_CALLBACK(on_nginx_install_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_install_nginx, 0, 1, 1, 1);

    // Кнопка для настройки сервисов
    button_configure_services = gtk_button_new_with_label("Настроить Nginx");
    g_signal_connect(button_configure_services, "clicked", G_CALLBACK(on_configure_services_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_configure_services, 0, 2, 1, 1);

    // Отображение всех элементов
    gtk_widget_show_all(window);

    // Закрытие окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}

#endif  // Завершение блока USE_GUI
