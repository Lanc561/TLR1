# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
LDFLAGS = 

# Директории
SRCDIR = src
HEADERDIR = src
TARGET = table_route_cipher
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/TableRouteCipher.cpp
HEADERS = $(HEADERDIR)/TableRouteCipher.h

# Определение операционной системы для корректной работы с локалями
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    CXXFLAGS += -DLINUX
    LOCALE_FLAG = -DLOCALE_RU
endif
ifeq ($(UNAME_S), Darwin)
    CXXFLAGS += -DOSX
    LOCALE_FLAG = -DLOCALE_RU
endif

# Основная цель
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LOCALE_FLAG) -I$(HEADERDIR) $(SOURCES) -o $(TARGET) $(LDFLAGS)

# Отладочная сборка
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Быстрая сборка (без оптимизаций)
fast: CXXFLAGS = -std=c++11 -Wall -Wextra
fast: $(TARGET)

# Очистка
clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f $(SRCDIR)/*.o

# Пересборка
rebuild: clean all

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Запуск с отладкой
debug-run: debug
	./$(TARGET)

# Показать информацию о проекте
info:
	@echo "=== Table Route Cipher Project ==="
	@echo "Цель: $(TARGET)"
	@echo "Компилятор: $(CXX)"
	@echo "Флаги: $(CXXFLAGS)"
	@echo "Исходные файлы: $(SOURCES)"
	@echo "Заголовочные файлы: $(HEADERS)"
	@echo "Платформа: $(UNAME_S)"

# Проверка структуры проекта
check-structure:
	@echo "=== Проверка структуры проекта ==="
	@if [ -d "$(SRCDIR)" ]; then \
		echo "✓ Каталог src существует"; \
		if [ -f "$(SRCDIR)/main.cpp" ]; then echo "✓ main.cpp найден"; else echo "✗ main.cpp не найден"; fi; \
		if [ -f "$(SRCDIR)/TableRouteCipher.cpp" ]; then echo "✓ TableRouteCipher.cpp найден"; else echo "✗ TableRouteCipher.cpp не найден"; fi; \
		if [ -f "$(HEADERDIR)/TableRouteCipher.h" ]; then echo "✓ TableRouteCipher.h найден"; else echo "✗ TableRouteCipher.h не найден"; fi; \
	else \
		echo "✗ Каталог src не существует"; \
	fi

# Помощь
help:
	@echo "Доступные команды:"
	@echo "  make all        - Сборка проекта (по умолчанию)"
	@echo "  make debug      - Сборка с отладочной информацией"
	@echo "  make fast       - Быстрая сборка без оптимизаций"
	@echo "  make clean      - Очистка собранных файлов"
	@echo "  make rebuild    - Полная пересборка"
	@echo "  make run        - Сборка и запуск программы"
	@echo "  make debug-run  - Сборка с отладкой и запуск"
	@echo "  make info       - Информация о проекте"
	@echo "  make check-structure - Проверка структуры проекта"
	@echo "  make help       - Эта справка"

.PHONY: all debug fast clean rebuild run debug-run info check-structure help
