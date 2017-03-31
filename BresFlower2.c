#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

 int x,y,d,x1,y11,r;
void putpixel (int x, int y)  
{  
   glColor3f(1.0,0.0,0.0);
   glBegin (GL_POINTS);  
   glVertex2i (x, y);  
   glEnd ();  
   glFlush (); 
  } 

void cir(int x1,int y1,int r)
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
     
  printf("Enter radius ");
  scanf("%d",&r);
  printf("  Enter the New center: ");
   scanf("%d%d",&x1,&y11);
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,640);
  glutCreateWindow("bresenham_circle");
  init();
 cir(x1,y11,r);
cir(x1-2*r,y11,r);
cir(x1+2*r,y11,r);
cir(x1+r,y11+sqrt(3)*r,r);
cir(x1-r,y11+sqrt(3)*r,r);
cir(x1+r,y11-sqrt(3)*r,r);
cir(x1-r,y11-sqrt(3)*r,r);
cir(x1,y11,r*2);
 glFlush();
 glutMainLoop();

  return 0;
 }