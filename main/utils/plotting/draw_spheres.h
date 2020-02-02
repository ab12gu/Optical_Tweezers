//------------------------------  Draw_Spheres   -------------------------------

void draw_elems(float (&my_array)[2][9]){

    // obstacles:
    int rows = sizeof my_array / sizeof my_array[0];
    int cols = sizeof my_array[0] / sizeof(int);

    for (int elem = 0; elem < rows; elem++) {
        glPushMatrix ();
            glTranslatef    (my_array[elem][0], my_array[elem][1], my_array[elem][2]); //position
            glRotatef       (my_array[elem][3], 0,0,0);
            glutSolidSphere (1.0, 10, 30); // radius, verticies, edges per vertices
        glPopMatrix ();
    }
}


// ----------------------------- if esc pressed, leave window ------------------
void processNormalKeys(unsigned char key, int x, int y) {

    if (key == 27) //escape key
        exit(0); 

}

// ----------------------------- movement keys ------------------
// initialize angles
float horz_angle = 0.0f;
float vert_angle = 0.0f;

void processSpecialKeys(int key, int xx, int yy) {

    if (key == 27) //escape key
        exit(0); 

	switch (key) {
		case GLUT_KEY_LEFT :
			horz_angle -= 3.0f;
			break;
		case GLUT_KEY_RIGHT :
			horz_angle += 3.0f;
			break;
		case GLUT_KEY_UP :
			vert_angle += 3.0f;
			break;
		case GLUT_KEY_DOWN :
			vert_angle -= 3.0f;
			break;
	}
}

void create_grid(){

    // near clipping plane grid
    glColor3f(0.0, 0.0, 0.0);
    int xsize=0,ysize=0;
    for(int j=0;j<10;j++)
    {
        xsize=0;
        for(int i=0;i<10;i++)
        {
             glBegin(GL_POLYGON);
               glVertex3f(1.0+xsize, 1.0+ysize, 0.0);
               glVertex3f(0.0+xsize, 1.0+ysize, 0.0);
               glVertex3f(0.0+xsize, 0.0+ysize, 0.0);
               glVertex3f(1.0+xsize, 0.0+ysize, 0.0);
            glEnd();
         xsize+=1.0;
     }
     ysize+=1.0;
     } // far clipping plane grid

    // near clipping plane grid
    glColor3f(0.0, 0.0, 0.0);
    int zsize=0;
    ysize=0;
    for(int j=0;j<10;j++)
    {
        zsize=0;
        for(int i=0;i<10;i++)
        {
             glBegin(GL_POLYGON);
               glVertex3f(0.0, 1.0+ysize, 1.0+zsize);
               glVertex3f(0.0, 0.0+ysize, 1.0+zsize);
               glVertex3f(0.0, 0.0+ysize, 0.0+zsize);
               glVertex3f(0.0, 1.0+ysize, 0.0+zsize);
            glEnd();
         zsize+=1.0;
     }
     ysize+=1.0;
     } // far clipping plane grid


    // near clipping plane grid
    glColor3f(0.0, 0.0, 0.0);
    zsize=0;
    xsize=0;
    for(int j=0;j<10;j++)
    {
        zsize=0;
        for(int i=0;i<10;i++)
        {
             glBegin(GL_POLYGON);
               glVertex3f(1.0+xsize, 0.0, 1.0+zsize);
               glVertex3f(0.0+xsize, 0.0, 1.0+zsize);
               glVertex3f(0.0+xsize, 0.0, 0.0+zsize);
               glVertex3f(1.0+xsize, 0.0, 0.0+zsize);
            glEnd();
         zsize+=1.0;
     }
     xsize+=1.0;
     } // far clipping plane grid



   }

void create_cube(void) {

    // White side - BACK
    glBegin(GL_QUADS);

    // RIGHT
    glColor3f(  0.0,  0.0,  0.0 );
    glVertex3f( 10.0, -0.0, -0.0 );
    glVertex3f( 10.0,  10.0, -0.0 );
    glVertex3f( 10.0,  10.0, 10.0 );
    glVertex3f( 10.0, -0.0,  10.0 );

    // TOP
    glColor3f(   0.0,  0.0,  0.0 );
    glVertex3f(  10.0,  10.0,  10.0 );
    glVertex3f(  10.0,  10.0, -0.0 );
    glVertex3f( -0.0,  10.0, -0.0 );
    glVertex3f( -0.0,  10.0,  10.0 );

    glEnd();
}

void draw_spheres (void)
{
    // setup window
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (-5.0, -5.0, -15.0);

    gluLookAt ( 0.0, 0.0, 1.0, 
                0.0, 0.0, 0.0, 
                0.0, 1.0, 0.0 ); 

    float a = 5.0;
    float b = 5.0;
    float c = 5.0;
    glTranslatef    (a, b, c);
    glRotatef( horz_angle, 0.0f, -1.0f, 0 ); // rotate around a particular vector with a specified angle
    glRotatef( vert_angle, 1.0f, 0.0f, 0 ); // rotate around a particular vector with a specified angle
    glTranslatef    (-a, -b, -c);

    //glTranslatef(0.0f, 0.5*sin(vert_angle), 0.0f); // rotate around a particular vector with a specified angle
    //glTranslatef(0.5*sin(horz_angle), 0.0f, 0.0f); // rotate around a particular vector with a specified angle



    // plot beads and obstacles
    glColor3f (0.8, 0.2, 0.1);              // Red ball displaced to left.
    draw_elems(beads);

    glColor3f (0.1, 0.2, 0.8);              // Blue ball displaced to right.
    draw_elems(obs);

    create_grid();

    create_cube();

    glEnable(GL_BLEND); //Enable blending.
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.

    glutSwapBuffers();

}
