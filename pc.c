#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

float p[20][2], wxmin, wxmax, wymin, wymax;
int v;

//---------------------------------------------------------
void draw_line(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	glFlush();
}
//---------------------------------------------------------
void draw_frame()
{
	glColor3f(1,1,0);
	draw_line(wxmin,wymin, wxmin, wymax);
	draw_line(wxmin,wymax, wxmax, wymax);
	draw_line(wxmax,wymax, wxmax, wymin);
	draw_line(wxmin,wymin, wxmax, wymin);
}

//---------------------------------------------------------
void draw_poly()
{
	glColor3f(0,1.0,0);
	int i;
	for(i=0; i<v; i++)
		draw_line(p[i][0], p[i][1], p[(i+1)%v][0], p[(i+1)%v][1]);
}

//---------------------------------------------------------
void left_clip()
{
	float t[10][2], x1,y1,x2,y2;
	int i, k=0;
	for(i=0; i<v; i++)
	{
		x1=p[i][0];	y1=p[i][1];
		x2=p[(i+1)%v][0];	y2=p[(i+1)%v][1];
		
		if(x1 >= wxmin)
		{
			t[k][0] = x1;
			t[k++][1] = y1;
		}
		if( (x1<wxmin && x2>wxmin) || (x1>wxmin && x2<wxmin))
		{
			t[k][0] = wxmin;
			t[k++][1] = y1 + (wxmin-x1)*((y2-y1)/(x2-x1));
		}
	}
	v = k;
	
	for(i =0; i<v; i++)
	{
		p[i][0] = t[i][0];
		p[i][1] = t[i][1];
	}
}

//---------------------------------------------------------
void top_clip()
{
	float t[10][2], x1,y1,x2,y2;
	int i, k=0;
	for(i=0; i<v; i++)
	{
		x1=p[i][0];	y1=p[i][1];
		x2=p[(i+1)%v][0];	y2=p[(i+1)%v][1];
		
		if(y1 <= wymax)
		{
			t[k][0] = x1;
			t[k++][1] = y1;
		}
		if( (y1<wymax && y2>wymax) || (y1>wymax && y2<wymax))
		{
			t[k][0] = x1 + (wymax-y1)*((x2-x1)/(y2-y1));
			t[k++][1] = wymax;
		}
	}
	v = k;
	
	for(i =0; i<v; i++)
	{
		p[i][0] = t[i][0];
		p[i][1] = t[i][1];
	}
}

//---------------------------------------------------------
void right_clip()
{
	float t[10][2], x1,y1,x2,y2;
	int i, k=0;
	for(i=0; i<v; i++)
	{
		x1=p[i][0];	y1=p[i][1];
		x2=p[(i+1)%v][0];	y2=p[(i+1)%v][1];
		
		if(x1 <= wxmax)
		{
			t[k][0] = x1;
			t[k++][1] = y1;
		}
		if( (x1<wxmax && x2>wxmax) || (x1>wxmax && x2<wxmax))
		{
			t[k][0] = wxmax;
			t[k++][1] = y1 + (wxmax-x1)*((y2-y1)/(x2-x1));
		}
	}
	v = k;
	
	for(i =0; i<v; i++)
	{
		p[i][0] = t[i][0];
		p[i][1] = t[i][1];
	}
}

//---------------------------------------------------------
void bottom_clip()
{
	float t[10][2], x1,y1,x2,y2;
	int i, k=0;
	for(i=0; i<v; i++)
	{
		x1=p[i][0];	y1=p[i][1];
		x2=p[(i+1)%v][0];	y2=p[(i+1)%v][1];
		
		if(y1 >= wymin)
		{
			t[k][0] = x1;
			t[k++][1] = y1;
		}
		if( (y1<wymin && y2>wymin) || (y1>wymin && y2<wymin))
		{
			t[k][0] = x1 + (wymin-y1)*((x2-x1)/(y2-y1));
			t[k++][1] = wymin;
		}
	}
	v = k;
	
	for(i =0; i<v; i++)
	{
		p[i][0] = t[i][0];
		p[i][1] = t[i][1];
	}
}


//---------------------------------------------------------
void init()
{	
	glClearColor(0,0,0,0); 
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

//---------------------------------------------------------
void main(int argc, char** argv)
{
	
	printf("Enter wxmin -> ");
	scanf("%f",&wxmin);
	printf("Enter wymin -> ");
	scanf("%f",&wymin);
	printf("Enter wxmax -> ");
	scanf("%f",&wxmax);
	printf("Enter wymax -> ");
	scanf("%f",&wymax);
	
	printf("Enter the number of verices of polygon -> ");
	scanf("%d",&v);
	int i;
	for(i=0; i<v; i++)
	{
		printf("Enter vertex %d -> ", i);
		scanf("%f%f", &p[i][0], &p[i][1]);
	}
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Poly Clipping");
	init();
	
	draw_frame();
	draw_poly(p,v);
	
	printf("Enter 1 integer to LEFT clipped versin ");
	scanf("%d",&i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	draw_frame();
	left_clip();
	draw_poly();
	
	printf("Enter ANY integer to TOP clipped versin ");
	scanf("%d",&i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	draw_frame();
	top_clip();
	draw_poly();
	
	printf("Enter ANY integer to RIGHT clipped versin ");
	scanf("%d",&i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	draw_frame();
	right_clip();
	draw_poly();
	
	printf("Enter ANY integer to BOTTOM clipped versin ");
	scanf("%d",&i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	draw_frame();
	bottom_clip();
	draw_poly();
	
	
	glutMainLoop();
}
