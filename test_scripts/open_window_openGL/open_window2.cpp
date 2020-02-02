// Need to link libraries
// -framework opengl
// -lglfw
// site: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLFW
#include <GLFW/glfw3.h> //uses homebrew version :)

#include <iostream>

int main(){
// Initialise GLFW
glfwInit();

// Open a window and create its OpenGL context
GLFWwindow* window; // (In the accompanying source code, this variable is global for simplicity)
window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

glfwMakeContextCurrent(window); // Initialize GLEW

// Ensure we can capture the escape key being pressed below
glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

do{
    // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
    glClear( GL_COLOR_BUFFER_BIT );

    // Draw nothing, see you in tutorial 2!

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

} // Check if the ESC key was pressed or the window was closed
while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
       glfwWindowShouldClose(window) == 0 );

}