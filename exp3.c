#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int r;
void bresenham_circle(int r)
{
 
  int x=0,y=r;
  int d=3-2*r;
  do
  {
	  glBegin(GL_POINTS);
	  glVertex2i(x, y);
	  glVertex2i(x, -y);
	  glVertex2i(y, x);
	  glVertex2i(y, -x);
	  glVertex2i(-x, -y);
	  glVertex2i(-y, -x);
	  glVertex2i(-x, y);
	  glVertex2i(-y, x);
	  glEnd();

	if(d < 0)
	{ 
		x=x+1;
		d = d + 4*x+6;
	}
	else
	{
		x=x+1;
		d = d + 4*(x - y) + 10;
		y = y - 1;
	}
  }while(x<=y);
  //glFlush();
}

  void display()
  {
      
    glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   bresenham_circle(r);
       glFlush();
}


void Init()
{

  glClearColor(0,0,0,0);
  gluOrtho2D(0.0,600.0 ,0.0 ,480.0);
}

int main(int argc, char **argv)
{
  printf("\n Enter radius ");
  scanf("%d",&r);
  glutInit(&argc,argv);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,640);
  glutCreateWindow("bresenham_circle");
  Init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

