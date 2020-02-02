void Keys( int key, int x, int y ) 
{
 
  //  Right arrow - increase rotation by 5 degree
  

  if (key == GLUT_KEY_RIGHT)
    yRotated += 10;
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    yRotated -= 10;
 
  else if (key == GLUT_KEY_UP)
    radius += 0.1;
 
  else if (key == GLUT_KEY_DOWN)
    xRotated -= 10;
 
  //  Request display update
  glutPostRedisplay();
 
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
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    //glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    //glutWireSphere(radius,50,50);
    // Flush buffers to screen
    glTranslatef(0.0,0.0,0.0);
    //glFlush(); 
    
    std::ifstream infile;
    
    infile.open("Locs.txt");
    //while(!infile.eof())
    //{
        
        for(int i = 0;i<reference;i++)
        {
            float x,y,state;
            infile>>x;
            
            infile>>y;
            
            infile>>state;
            y=(y-45)*14.4/Ymax;
            x=(x-60)*20.48/Xmax;
            if(state == 1)
            {
                glColor3f(0.0, 0.0, 0.4);
                glTranslatef(x,y,0.0);
                glutSolidSphere(0.3,50,50);
                glTranslatef(-x,-y,0.0); 

            }
            else
            {
                glColor3f(0.0, 0.4, 0.0);
                glTranslatef(x,y,-5.0);
                glutSolidSphere(0.3,50,50);
                glTranslatef(-x,-y,5.0); 
                //glFlush();
 

            }


        }
        glFlush();
    //}
    //infile.close();
    
    glFlush();
    
    //glutWireSphere(radius,50,50);  
    //glClear(GL_COLOR_BUFFER_BIT);
    //glutWireSphere(radius,50,50);

    
    //glutTimerFunc(1000,display,void);
    // sawp buffers called because we are using double buffering 
   glutSwapBuffers();
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
