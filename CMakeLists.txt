# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.16) 

# Nombre del proyecto
project(CDM VERSION 1.0) 

# Indica a CMake que busque el código fuente de SDL3
add_subdirectory(external/SDL3-3.2.24) 

# Crea tu ejecutable a partir de tu código fuente
add_executable(game src/Game/main.cpp) 

# ======================================================================
# 1. COMPILAR GLAD (Versión Corregida)
# ======================================================================

# 1.1. Crea la librería 'glad' con su archivo fuente explícito
add_library(glad STATIC 
    external/glad/src/glad.c
)

# 1.2. ¡CORRECCIÓN CLAVE! Establece el path de inclusión para la LIBRERÍA 'glad'
# Esto permite que glad.c encuentre <glad/glad.h>
target_include_directories(glad PUBLIC external/glad/include)

# 1.3. Establece el path de inclusión para tu ejecutable 'game'
# Esto permite que tu main.cpp encuentre <glad/glad.h>
target_include_directories(game PRIVATE external/glad/include)

# ======================================================================
# 2. ENLAZAR LIBRERÍAS
# ======================================================================

# Enlaza tu ejecutable con SDL3 y GLAD
target_link_libraries(game PRIVATE SDL3::SDL3 glad)

# SDL3::SDL3 es el nombre del target que define el CMake de SDL3
target_link_libraries(game PRIVATE SDL3::SDL3)