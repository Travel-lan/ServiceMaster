#ifndef INSTALL_SERVICES_H
#define INSTALL_SERVICES_H

int detect_os();
int check_service_installed(const char *service);
int install_mariadb();
int install_nginx();
int check_superuser_permissions();

#endif // INSTALL_SERVICES_H
