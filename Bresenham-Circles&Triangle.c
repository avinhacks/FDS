#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int first=0;
int xx1,xx2,yy1,yy2;

int sign(int x) {
    if(x > 0)
    	     return 1;
    if(x < 0) 
    		return -1;
    return 0;
}

void drawline(int X1,int Y1, int X2,int Y2)
{
	    float x,y,dx,dy,length;
	    int i;

	    dx=abs(X2-X1);
	    dy=abs(Y2-Y1);
	    
	    if(dx>=dy)
		   length=dx;
	    else
		   length=dy;
		   
	    dx=(X2-X1)/length;
	    dy=(Y2-Y1)/length;
	    x=X1 + 0.5*sign(X1);
	    y=Y1 + 0.5*sign(Y1);
	    i=1;
	    
         while(i<=length) {
             glBegin(GL_POINTS);
             glVertex2i(x,y);
             glEnd();
             glFlush();
		   x=x+dx;
		   y=y+dy;
		   i=i+1;
    	    }
}

void bresenham_circle(int r)
{
	int x=0,y=r;
	int d=3-2*r;
	
	do
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(x,-y);
		glVertex2i(y,x);
		glVertex2i(y,-x);
		glVertex2i(-x,-y);
		glVertex2i(-y,-x);
		glVertex2i(-x,y);
		glVertex2i(-y,x);
		glEnd();
	
		if(d<0) {
		   d=d+4*x+6;
		} else {
		 d=d+4*(x-y)+10;
		 y=y-1;
		}
		
		x=x+1;
     
   }while(x<=y);
}
  
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);

	bresenham_circle(100);

	glColor3f(1.0,0.0,0.0);

	bresenham_circle(50);
	
	drawline(0,105,-85,-45);
	drawline(0,105,85,-45);
	drawline(-90,-48,90,-48);

	glFlush();
}

void init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(-200,200,-200,200);
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bresenham Circles & Triangle");
    init();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glFlush();
    glutMainLoop();

    return 0;
   
}