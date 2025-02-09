# Définition du compilateur et des options
CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0) -mwindows  # ✅ Ajout de -mwindows

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
TEST_DIR = DossierForTesting

# Fichiers sources
SOURCES = $(wildcard $(SRC_DIR)/windows/*.c $(SRC_DIR)/widgets/*.c $(SRC_DIR)/containers/*.c $(TEST_DIR)/test_project_1/*.c $(TEST_DIR)/test_project_2/*.c $(SRC_DIR)/*.c temp.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/application.exe

# Compilation principale
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers compilés
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Exécution de l'application
run: all
	@echo "Lancement de l'application..."
	./$(TARGET)

.PHONY: all clean run
