/* Program to draw the line, user will click on any 2 points on screen then
 * line should be drawn using these two points.
*/
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
	
int xx1, xx2, yy1, yy2;
int first=0;

int sign(int x) {
    if(x>0) 
    	return 1;
    if(x<0)
      return -1;
    return 0;
}

void drawline(int X1, int Y1, int X2, int Y2) {
    float x, y, dx, dy, length;
    int i;
    
    dx = abs(X2-X1);
    dy = abs(Y2-Y1);
    
    if(dx >= dy)
        length=dx;
    else
        length = dy;
    
    dx = (X2-X1)/length;
    dy = (Y2-Y1)/length;
    
    x = X1 + 0.5*sign(dx);
    y = Y1 + 0.5*sign(dy);
    
    i = 1;
    
    while(i<=length) {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        x = x+dx;
        y = y+dy;
        i = i+1;
    }
    glFlush();
}

void mouse(int button, int State, int x, int y) {
   
   if(button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { 
     switch(first) {
       case 0:
         xx1 = x;
         yy1 = 480-y;
         first = 1;
         break;
         
       case 1:
         xx2 = x;
         yy2 = 480-y;
      
			glColor3f(0.0,0.0,1.0);
			drawline(xx2,yy2,xx1,yy1);
		 	glEnd();
		 	glFlush();
		 	first = 0;
		 	break;
     }
     
   }
}
int main(int argc, char ** argv)
{ 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("DDA Line Drawing using Mouse");
    gluOrtho2D(0.0,640,0.0,480);
    glutMouseFunc(mouse);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutMainLoop();
    
    return 0;            
}
