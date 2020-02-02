// title: multi-sphere.cpp
// by: Abhay Gupta
//
// date: 4/5/19
// description: plot spheres in specific locations 
//  - parameterize number of spheres, and location of spheres

// site: https://social.msdn.microsoft.com/Forums/en-US/aadab0a5-9e04-4232-908d-f849215a4f09/include-file-windowsh-no-such-file-or-directory-error?forum=vcgeneral

// headers
#include <GL/freeglut.h> //not opengl... just a window manager
#include <iostream>

using namespace std;

// global varriables
bool  movingUp = 0; // Whether or not we are moving up or down
float yLocation = 0.0f; // Keep track of our position on the y axis.
float yRotationAngle = 0.0f; // The angle of rotation for our object

// initial x,y,z position
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int x, int y)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
 
    gluPerspective (40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glMatrixMode   (GL_MODELVIEW);
    glViewport     (0, 0, x, y); 
}

//------------------------------  Draw_Spheres   -------------------------------

void Draw_Spheres (void)
{

	cout << zRotated << endl;

    glMatrixMode   (GL_MODELVIEW);
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);

    glColor3f (0.8, 0.2, 0.1);              // Red ball displaced to left.
    glPushMatrix ();
       glTranslatef    (-1.5, 0.0, yLocation);
       glRotatef       (0, 0,0,0);
       glRotatef       (zRotated*2.0, 0,0,0);   // Red ball rotates at twice the rate of blue ball.
       glutSolidSphere (1.0, 20, 50);
    glPopMatrix ();

    
    glColor3f (0.1, 0.2, 0.8);              // Blue ball displaced to right.
    glPushMatrix ();
       glTranslatef    (1.5, 0.0, yLocation);
       glRotatef       (0, 0,0,0);
       glRotatef       (zRotated, 0,0,0);
       glutSolidSphere (1.0, 20, 50); // radius, verticies, edges per vertices
    glPopMatrix ();

    glutSwapBuffers();

}

//--------------------------------  idleFunc  ----------------------------------
// runs in background... allows changes per frame 
void idleFunc (void)
{
    zRotated += 0.01;
    glutPostRedisplay();
}

//----------------------------------  main  ------------------------------------
 
int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode    (GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("Sphere Rotating Animation");
    glPolygonMode          (GL_FRONT_AND_BACK, GL_LINE);
 
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc (Draw_Spheres);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);

    glutMainLoop();
}

