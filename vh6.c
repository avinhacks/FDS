#include <GL/glut.h>    // Header File For The GLUT Library 

float rtri = 0.0f;

void InitGL(int Width, int Height)         
{
  // This Will Clear The Background Color To Black
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     
  glMatrixMode(GL_PROJECTION);
   gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);  
  glMatrixMode(GL_MODELVIEW);
}

float ballX = -0.5f;
float ballY = 0.0f;
float ballZ = 0.0f;

/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Clear The Screen And The Depth Buffer
  glLoadIdentity();                // Reset The View
  glTranslatef(rtri,0.0f,-6.0f);        // Move Left 1.5 Units And Into The Screen 6.0 //VIMP before scene
   
   glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(1.0f,0.0f,0.0f);            // Set The Color To Red
  glVertex3f(-1.0f, 1.0f, 0.0f);        // Top left
  glVertex3f(0.4f, 1.0f, 0.0f);
  glVertex3f(1.0f, 0.4f, 0.0f);
  glColor3f(0.0f,1.0f,0.0f);            // Set The Color To Green
  glVertex3f( 1.0f,0.0f, 0.0f);        // Bottom Right
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Blue
  glVertex3f(-1.0f,0.0f, 0.0f);// Bottom Left    

  glEnd();                 
 
  glColor3f(0.0, 1.0, 0.0); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.3, 20, 20); //create ball.
        glTranslatef(ballX+1.5,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.3, 20, 20);
 
  rtri+=0.005f;                    // Increase The Rotation Variable For The Triangle
  if(rtri>2)                       //Set to left corner   
      rtri=-2.0f;
 
  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}


int main(int argc, char **argv) 
{  
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH); 
  glutInitWindowSize(640, 480);  
  glutInitWindowPosition(0, 0);  
  glutCreateWindow("Moving Car");  
  glutDisplayFunc(DrawGLScene);  
  glutIdleFunc(DrawGLScene);   //imp to move
  
  /* Initialize our window. */
  InitGL(640, 480);
    /* Start Event Processing Engine */  
  glutMainLoop();  

  return 1;
}


