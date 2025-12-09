CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./src

# Nombre del ejecutable
TARGET = main

# Carpetas
SRC_DIR = src
BUILD_DIR = build

# Buscar todos los .cpp dentro de src/
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Convertir *.cpp → build/*.o
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Regla principal
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regla para compilar cada .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear carpeta build si no existe
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Limpiar
clean:
	del /Q $(BUILD_DIR)\*.o
	del /Q $(TARGET).exe
