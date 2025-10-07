#include <SDL3/SDL.h> // Nota la carpeta SDL3/
#include <glad/glad.h> 
#include <iostream>


int main(int argc, char* argv[]) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // 2. Crear la ventana con el flag SDL_WINDOW_OPENGL
    SDL_Window* window = SDL_CreateWindow(
        "Proyecto OpenGL con SDL3", 
        640, 480, 
        SDL_WINDOW_OPENGL
    );

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        // Manejar error
    }

    // 2. Carga las funciones de OpenGL usando GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Fallo al inicializar GLAD" << std::endl;
        return -1;
    }

    // 3. ¡Ahora puedes usar funciones de OpenGL!
    std::cout << "Versión de OpenGL: " << glGetString(GL_VERSION) << std::endl;
    
    while (1) {
        
    }
    
    // Limpieza
    SDL_GL_DestroyContext(context);

    return 0;
}