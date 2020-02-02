// libraries: 
// -framework opengl
// -framework glut
// -lglew
// site; http://in2gpu.com/2014/10/17/creating-opengl-window/
// date: oct 2014

#include <iostream>
#include <GL/freeglut.h> //not opengl... just a window manager

// usr/local/include/ ... unsure if homebrew installed them or already installed...

using namespace std;

void renderScene(void)
{
   glClearColor(0.0, 0.3, 0.3, 1.0); // sets color
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears color

   glutSwapBuffers();
}

void create_window(int argc, char **argv)
{	
	//std::cout << &argc;
	//std::cout << argv;

	glutInit(&argc, argv); // initalize glut library
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); //most common display mod (depth for overlapping images, sooth animation to prevent flickering, allocate color channels)
	//glutInitWindowPosition(500, 500); // position of window on screen
	//glutInitWindowSize(800, 400); // size of window
	glutCreateWindow("OpenGL First Window"); // actually create window
}

int main(int argc, char **argv)
{
	create_window(argc, argv);

	//glEnable(GL_DEPTH_TEST); 
	// register callbacks
	glutDisplayFunc(renderScene);
	
	glutMainLoop();
	
	return 0;

}
      
