# Nome do executável
TARGET = build/game

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Compilador e flags
CC = gcc
CFLAGS = -I $(INCLUDE_DIR)

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(TARGET)

# Limpeza dos arquivos compilados
clean:
	rm -f $(TARGET)
