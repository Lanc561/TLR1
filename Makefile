CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCDIR = src
HEADERDIR = src/headers
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/modAlphaCipher.cpp
HEADERS = $(HEADERDIR)/modAlphaCipher.h
TARGET = alpha_cipher
LDFLAGS = 

# Определение кодировки для Windows/Linux
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    CXXFLAGS += -DLINUX
endif
ifeq ($(UNAME_S), Darwin)
    CXXFLAGS += -DOSX
endif

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild
