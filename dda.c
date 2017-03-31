#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
//using namespace std;

int xx1,xx2,yy1,yy2,i,ch;
float x,y,dx,dy,length;
	
int sign(int x)
{
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}
void solid(int x,int y, int dx,int dy ,int length)	
{
		
	i=1;
	while(i<=length)
	{
	
	       glBegin (GL_POINTS);  
               glVertex2i (x, y);  
               glEnd ();  
                glFlush (); 
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
	//glFlush();

}
   
void dotdashed(int x,int y,int dx,int dy,int len)
{
	int i,m;
	for(i=1;i<=len;i++)
	{
		m=i%15;
		if(m==0)
		{
                        glColor3f(1,0,0);
			glBegin (GL_POINTS);  
                        glVertex2i (x, y);  
                        glEnd ();  
                        glFlush ();
			x=x+dx;
			y=y+dy;
		}
		else if(m>=3&&m<=8)
		{
		 glColor3f(1,1,1);
			glBegin (GL_POINTS);  
                        glVertex2i (x, y);  
                        glEnd ();  
                        glFlush ();
			x=x+dx;
			y=y+dy;
		}
		else
		{
			x=x+dx;
			y=y+dy;
		}
	}
}

void dot(int x,int y,int dx,int dy,int len)
{
	int i,m;
	for(i=1;i<=len;i++)
	{
		m=i%10;
		if(m==0)
		{
		   glColor3f(1.0,1.0,1.0);
			glBegin (GL_POINTS);  
                        glVertex2i (x, y);  
                        glEnd ();  
                        glFlush ();
			x=x+dx;
			y=y+dy;
		}
		else
		{
			x=x+dx;
			y=y+dy;
		}
	}
}

void dashed(int x,int y,int dx,int dy,int len)
{
	int i,m;
	for(i=1;i<=len;i++)
	{
		m=i%10;
		if(m>=3&&m<=7)
		{
			glColor3f(1.0,1.0,0.0);
			glBegin (GL_POINTS);  
                        glVertex2i (x, y);  
                        glEnd ();  
                        glFlush ();
			x=x+dx;
			y=y+dy;
		}
		else
		{
			x=x+dx;
			y=y+dy;
		}
	}
}


void thick(int x,int y, int dx,int dy ,int length)	
{
		
	i=1;
	while(i<=length)
	{
	
	       glBegin (GL_POINTS);  
               glVertex2i (x, y);  
               glEnd ();  
                glFlush (); 
               glBegin (GL_POINTS);  
               glVertex2i (x+1, y);  
               glEnd ();  
                glFlush (); 
                glBegin (GL_POINTS);  
               glVertex2i (x-1, y);  
               glEnd ();  
                glFlush ();
               glBegin (GL_POINTS);  
               glVertex2i (x+1, y+1);  
               glEnd ();  
                glFlush (); 
               glBegin (GL_POINTS);  
               glVertex2i (x-1, y-1);  
               glEnd ();  
                glFlush ();  
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
	//glFlush();

}
 
void init(void)
{ 
         glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-600.0,600.0,-600.0,600.0);
        glColor3f(1.0,1.0,0.0);
	
}
int main(int argc,char** argv)
{
	printf("enter vertex x1 and y1"); 
        scanf("%d%d",&xx1,&yy1);
        printf("enter vertex x2 and y2"); 
        scanf("%d%d",&xx2,&yy2);
       
        
	 dx=abs(xx2-xx1);
	dy=abs(yy2-yy1);
	if(dx>=dy)
		length=dx;
	else
		length=dy;
	dx=(xx2-xx1)/length;
	dy=(yy2-yy1)/length;
	x=xx1 + 0.5*sign(xx1);
	y=yy1 + 0.5*sign(yy1);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("DDA Line");
	init();
	//glutDisplayFunc(display);
        glClear(GL_COLOR_BUFFER_BIT);
        
        for(;;)
       {
        printf("\n Enter ur choice 1. Solid 2 dot 3 dash 4 dotdash 5 thick 6 exit ");
        scanf("%d",&ch);
        switch(ch) 
        {
         case 1:
               glClear(GL_COLOR_BUFFER_BIT);
               solid(x,y,dx,dy,length);
               break;
         case 2:
             glClear(GL_COLOR_BUFFER_BIT);
	     dot(x,y,dx,dy,length);
	     break;
	case 3: 
            glClear(GL_COLOR_BUFFER_BIT);
            dashed(x,y,dx,dy,length);
	   break;
	case 4:
           glClear(GL_COLOR_BUFFER_BIT);
	   dotdashed(x,y,dx,dy,length);
	   break;
        case 5:
           glClear(GL_COLOR_BUFFER_BIT);
	   thick(x,y,dx,dy,length);
           break;
        case 6:
               exit(0);
        }
      }
                    
	glFlush();
	glutMainLoop();

	return 0;
	
}

