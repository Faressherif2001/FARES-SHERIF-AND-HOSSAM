#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "GL/glu.h"

#include <string>

float angle=1.0;
double yRotated = 0;
double zRotated = 0;
double xRotated = 0;
int translateX1=0,translateY1=0;//input variables
int translateX2=0,translateY2=0;//input variables
double translateP=0;
double translateH=0;


void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (70.0, (GLdouble)w / (GLdouble)h, 1, 40.0);//gluPerspective for 3D Perspective Projection
    glMatrixMode(GL_MODELVIEW);
}

void addPlayer (int x, int y, int z, int tx, int ty)
{
    glTranslatef    (x+tx, y+ty, z);//x+tx and y+ty moves player by tx and ty in the right direction based on input
    glColor3f (0.5, 1.0, 1.0);



     glPushMatrix ();
       glTranslatef    (1.5, 0.0, 0.0);
       glRotatef       (180.0, 1,0,0);
       glRotatef       (zRotated, 0,0,1);
       glutSolidSphere (1.0, 5, 30);//player character is a solid sphere
    glPopMatrix ();



}

void addCoins (int x, int y, int z){//This method adds coins

    

    glutSolidTorus(x, y, z, 50);//coins items for players to pick up are made using torus shape
  



}

void addPlane (void){//This method adds a plane for our objects to stand on as a polygon
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.0f, 0.0f);
    glVertex3f( 4.0f, -7.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(4.0f, 7.0f, 0.0f);
    glColor3f(1.0f, 0.0f,1.0f);
    glVertex3f(-7.0f, 7.0f,0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-7.0f, -7.0f,0.0f);
    glEnd();
    }

void addPyramid(int x, int y, int z){//Drawing pyramid manually from scratch using GL_TRIANGLES

    glRotatef(90, 1, 0, 0);
    glTranslated(x, y, z);
    glRotated(yRotated, 0, 1, 0);
    glBegin(GL_TRIANGLES);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f+translateP, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f+translateP, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f+translateP, 1.0f);


      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f+translateP, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f+translateP, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f+translateP, -1.0f);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f+translateP, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f+translateP, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f+translateP, -1.0f);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f+translateP, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f+translateP, -1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f+translateP, 1.0f);

   glEnd();

   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f+translateP, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f+translateP, -1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f+translateP, -1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(1.0f, -1.0f+translateP, 1.0f);


    glEnd();

}



   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);

    glPushMatrix ();
       glTranslatef    (1.5, 0.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      // glRotatef       (zRotated, 0,0,1);

    glPopMatrix ();

    glRotated(-70, 1, 0, 0);
    glRotated(40, 0, 0, 1);
    addPlane();
    glPushMatrix();
    addPlayer(1, 1, 1, translateX1, translateY1);//adding first player character
    glEnd();glRasterPos2i(100, 120);
glColor4f(0.0f, 0.0f, 1.0f, 1.0f);


    glPopMatrix();
    glPushMatrix();
    addPlayer(-1, -2, 1, translateX2, translateY2);//adding second player character
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0,1,1);
    glRotated(-90, 1.0, 0.0, 0.0);
    glRotatef( xRotated,0, xRotated, 0);
    glutSolidTorus(0.1, 0.4, 5,30);//adding coin for players to pick up
    glEnd();
    glPopMatrix();

    glPushMatrix();
    addPyramid(0, -5, -12);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    addPyramid(0, -45, -12);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    addPyramid(0, -85, -12);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    addPyramid(0, -125, -12);
    glEnd();
    glPopMatrix();

    glPushMatrix ();
       glTranslatef    (2, -6.0, 0.5);
       glRotatef       (180.0, 1,0,0);
       glRotatef       (zRotated, 0,0,1);
       glutSolidCube(1);
    glPopMatrix ();

       glPushMatrix ();
       glTranslatef    (2, 6.0, 0.5);
       glRotatef       (180.0, 1,0,0);
       glRotatef       (zRotated, 0,0,1);
       glutSolidCube(1);
    glPopMatrix ();

       glPushMatrix ();
       glTranslatef    (-6, 3-translateH, 1);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated,0,1,0);
      glutSolidTeapot(1); //player character is a solid sphere
    glPopMatrix ();













    glutSwapBuffers();
}

void idleFunc (void)
{
    xRotated += 2;
    yRotated += 0.5;
    zRotated += 0.5;
    translateP += 0.03;
    translateH+=0.01;
    glutPostRedisplay();

}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

void keyboard(unsigned char Key,int x, int y){
switch(Key){
   case 'd' : translateX1++;
   break;

   case 'a' : translateX1--;
   break;

   case 'w' : translateY1++;
   break;

   case 's' : translateY1--;
   break;

   case 'l' : translateX2++;
   break;

   case 'j' : translateX2--;
   break;

   case 'i' : translateY2++;
   break;

   case 'k' : translateY2--;
   break;

   case 'f' : glutFullScreen();
   break;

   case 27 : exit(0);
   break;
}
}

int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("19102202-19100914");

    glClearColor (1.0, 1.0, 1.0, 1.0);


    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutKeyboardFunc(keyboard);
    glutIdleFunc    (idleFunc);

    glClearColor(0.5,0.5,0.5,0.5);
    texture();
    sndPlaySound("C:\\Users\\Fares Sherif\\Desktop\\program\\game\\sumotori.wav",SND_ASYNC);//adding background music
    glutMainLoop();
    return 0;


}

