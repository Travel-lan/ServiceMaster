CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I/usr/include/mariadb $(shell pkg-config --cflags gtk+-3.0)
LIBS = -L/usr/lib/x86_64-linux-gnu -lmariadb $(shell pkg-config --libs gtk+-3.0)

DEPS = system_manager.h install_services.h database.h nginx_config.h logging.h
OBJ_CONSOLE = main.o install_services.o database.o nginx_config.o logging.o docker_support.o monitoring.o
OBJ_GUI = gui.o install_services.o database.o nginx_config.o logging.o docker_support.o monitoring.o
OBJ_WEB = web_interface.py

# Компиляция консольной версии
console: echo $(OBJ_CONSOLE)
	$(CC) -o system_manager_console $(OBJ_CONSOLE) $(LIBS) $(CFLAGS)

# Компиляция GUI версии
gui: CFLAGS += -DUSE_GUI
gui: echo $(OBJ_GUI)
	$(CC) -o system_manager_gui $(OBJ_GUI) $(LIBS) $(CFLAGS)

# Установка Docker версии
docker: docker_support.o
	$(CC) -o system_manager_docker docker_support.o $(LIBS) $(CFLAGS)

%.o: %.c $(DEPS)
	@echo "Компиляция $< ..."
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDES)

clean:
	rm -f *.o system_manager_console system_manager_gui system_manager_docker

# Запуск тестов
test:
	gcc -o test_install_services test_install_services.c $(LIBS) $(CFLAGS)
	./test_install_services

# Запуск веб-интерфейса
web:
	python3 web_interface.py

# Вспомогательная команда для вывода компиляции
echo:
	@echo "CC: $(CC)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "INCLUDES: $(INCLUDES)"
	@echo "LIBS: $(LIBS)"


