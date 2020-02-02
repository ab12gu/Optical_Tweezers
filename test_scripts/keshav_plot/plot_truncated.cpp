
// Abhay's headers
#include <GL/freeglut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

void Keys( int key, int x, int y ) 
{
  //  Request display update
  glutPostRedisplay();
 
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}


void renderScene(void)
{
   glClearColor(0.0, 0.3, 0.3, 1.0); // sets color
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears color

   glutSwapBuffers();
}



void display()
{

    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();

    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();

    
    // traslate the draw by z = -40.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-40.0);
    // Red color used to draw.
    glColor3f(0.0, 0.0, 0.4); 
    // changing in transformation matrix.
    // rotation about Z axis
    //glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    //glutWireSphere(radius,50,50);
    // Flush buffers to screen
    glTranslatef(0.0,0.0,0.0);
    //glFlush(); 
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(1040,720,0.0);
    glutSolidSphere(0.3,50,50);
    glTranslatef(-1040,-720,0.0); 



    glFlush();
    glFlush();
    
   glutSwapBuffers();
} 


int main(int argc, char **argv)
{
    glutInit(&argc, argv); 
    
    glutInitWindowSize(1024,740);
    glutCreateWindow("Solid Sphere");
    glClearColor(1,1,1,0);
    glutDisplayFunc(display);
    //glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutSpecialFunc(Keys);
    glutMainLoop();
    
}