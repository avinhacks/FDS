#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

float x,y,d,x1,y11,r;
void putpixel (int x, int y)  
{  
 
   glBegin (GL_POINTS);  
   glVertex2i (x, y);  
   glEnd ();  
   glFlush (); 
  } 

void circ(int x1,int y1,int r)
{
 d=3-2*r;
  x=0;
  y=r;
   do
{

putpixel(x+x1,y+y1);
putpixel(y+x1,x+y1);
putpixel(-x+x1,y+y1);
putpixel(y+x1,-x+y1);
putpixel(-x+x1,-y+y1);
putpixel(-y+x1,-x+y1);
putpixel(x+x1,-y+y1);
putpixel(-y+x1,x+y1);
if(d<0)
{
x++;
d=d+4*x+6;
}
else
{
x++;
y--;
d=d+4*(x-y)+10;
}
}while(x<=y);

}

void init(void)
{         glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
int main(int argc, char **argv)
{
     
  printf("ENter radius ");
  scanf("%f",&r);
  printf("  Enter the New center: ");
   scanf("%f%f",&x1,&y11);
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,640);
  glutCreateWindow("bresenham_circle");
  init();
 circ(x1,y11,r);
circ(x1+r,y11,r);
circ(x1-r,y11,r);
circ(x1,y11+r,r);
circ(x1,y11-r,r);
circ(x1,y11,2*r);
 glFlush();
 glutMainLoop();

  return 0;
 }
