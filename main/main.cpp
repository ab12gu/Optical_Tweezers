// title: main.cpp
// by: Abhay Gupta
//
// date: 4/5/19
// description: plot spheres in specific locations 
//  - parameterize number of spheres, and location of spheres

// site: https://community.khronos.org/t/draw-sphere/73994 

// import standard libraries
#include <GL/freeglut.h> //not opengl... just a window manager
#include <iostream>

// import functions
#include "utils/variables/global_variables.h"
#include "utils/plotting/draw_spheres.h"
#include "utils/update/update_position.h"


#include <math.h>
//using namespace std;


//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int x, int y)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
 
    gluPerspective (100.0, (GLdouble)x / (GLdouble)y, 3.0, 50.0);
    glMatrixMode   (GL_MODELVIEW);
    glViewport     (0, 0, x, y); 
}

//----------------------------------  main  ------------------------------------
 
int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode    (GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("Plot multiple beads and obstacles");
    glPolygonMode          (GL_FRONT_AND_BACK, GL_LINE); // specify how polygons are rastered

    glClearColor (1.0, 1.0, 1.0, 0.0); // black background

    // display spheres
    glutDisplayFunc (draw_spheres);
    glutReshapeFunc (reshapeFunc);

    // update the location of objects
    glutIdleFunc        (idleFunc);
	glutKeyboardFunc    (processNormalKeys); // esc key
	glutSpecialFunc     (processSpecialKeys); // arrow key

    glutMainLoop();
}

