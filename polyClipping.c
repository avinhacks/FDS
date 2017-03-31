/*
Author - Saurabh Narhe
Description - A C graphics program for implementation of polygon cliping algorithm, 
              The program does following tasks,
              1. Asks the co-ordinates of main window 
              2. Asks the number of vertices of the polygoan, and thier co-ordinates 
              3. Clip the polygon region that goes outside the main window, from left, top, right and bottom side.
*/
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

float p[20][2], c[20][2], wxmin, wxmax, wymin, wymax;
int n;

void init()
{
	glClearColor(0,0,0,0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawLine(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
  glFlush();
}

void drawFrame() {
  glColor3f(0,1,0);
  drawLine(wxmin, wymin, wxmax, wymin);
  drawLine(wxmin, wymax, wxmax, wymax);
  drawLine(wxmin, wymin, wxmin, wymax);
  drawLine(wxmax, wymax, wxmax, wymin);
}

void drawPoly() {
  int i;
  glColor3f(1,0,0);
  for(i=0;i<n;i++)
    drawLine(p[i][0], p[i][1], p[(i+1)%n][0], p[(i+1)%n][1]);
}

void leftClip() {
  float x1, x2, y1, y2;
  int i, k = 0;

  for(i=0;i<n;i++) {

    x1 = p[i][0];
    y1 = p[i][1];
    x2 = p[(i+1)%n][0];
    y2 = p[(i+1)%n][1];

    if(x1 >= wxmin) {
      c[k][0] = x1;
			c[k++][1] = y1;
    }

    if((x1<wxmin && x2>wxmin) || (x1>wxmin && x2<wxmin)) {
      c[k][0] = wxmin;
			c[k++][1] = y1 + (wxmin-x1)*((y2-y1)/(x2-x1));
    }
  }

  n = k;
  for(i=0;i<n;i++) {
    p[i][0] = c[i][0];
    p[i][1] = c[i][1];
  }

}

void rightClip() {
  float x1, x2, y1, y2;
  int i, k = 0;

  for(i=0;i<n;i++) {

    x1 = p[i][0];
    y1 = p[i][1];
    x2 = p[(i+1)%n][0];
    y2 = p[(i+1)%n][1];

    if(x1 <= wxmax) {
      c[k][0] = x1;
			c[k++][1] = y1;
    }

    if((x1<wxmax && x2>wxmax) || (x1>wxmax && x2<wxmax)) {
      c[k][0] = wxmax;
			c[k++][1] = y1 + (wxmax-x1)*((y2-y1)/(x2-x1));
    }

  }
  n = k;
  for(i=0;i<n;i++) {
    p[i][0] = c[i][0];
    p[i][1] = c[i][1];
  }

}

void topClip() {
  float x1, x2, y1, y2;
  int i, k = 0;

  for(i=0;i<n;i++) {

    x1 = p[i][0];
    y1 = p[i][1];
    x2 = p[(i+1)%n][0];
    y2 = p[(i+1)%n][1];

    if(y1 <= wymax) {
      c[k][0] = x1;
			c[k++][1] = y1;
    }

    if((y1<wymax && y2>wymax) || (y1>wymax && y2<wymax)) {
      c[k][0] = wymax;
			c[k++][1] = x1 + (wymax-x1)*((y2-y1)/(x2-x1));
    }

  }
  n = k;
  for(i=0;i<n;i++) {
    p[i][0] = c[i][0];
    p[i][1] = c[i][1];
  }

}

void bottomClip() {
  float x1,y1,x2,y2;
	int i, k=0;
	for(i=0; i<n; i++)
	{
		x1=p[i][0];
    y1=p[i][1];
		x2=p[(i+1)%n][0];
    y2=p[(i+1)%n][1];

		if(y1 >= wymin)
		{
			c[k][0] = x1;
			c[k++][1] = y1;
		}
		if( (y1<wymin && y2>wymin) || (y1>wymin && y2<wymin))
		{
			c[k][0] = x1 + (wymin-y1)*((x2-x1)/(y2-y1));
			c[k++][1] = wymin;
		}
	}
	n = k;

	for(i =0; i<n; i++)
	{
		p[i][0] = c[i][0];
		p[i][1] = c[i][1];
	}
}

void main(int argc, char** argv) {

  int i ;

  printf("\nEnter wxmin, wymin, wxmax and wymax : \t");
  scanf("%f%f%f%f",&wxmin, &wymin, &wxmax, &wymax);

  printf("\nEnter number of vertices of polygon :\t");
  scanf("%d",&n);

  for(i=0; i<n; i++)
	{
		printf("Enter vertex %d(x, y) -> ", i+1);
		scanf("%f%f", &p[i][0], &p[i][1]);
	}

  glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Polygon Clipping");
	init();

  drawFrame();
  drawPoly(p, n);

  printf("Enter integer to show left clipped version ");
	scanf("%d",&i);

	glClear(GL_COLOR_BUFFER_BIT);
	drawFrame();
	leftClip();
	drawPoly();

  printf("Enter integer to show top clipped version ");
	scanf("%d",&i);

	glClear(GL_COLOR_BUFFER_BIT);
  drawFrame();
	topClip();
	drawPoly();

	printf("Enter integer to show right clipped version ");
	scanf("%d",&i);

	glClear(GL_COLOR_BUFFER_BIT);
  drawFrame();
	rightClip();
	drawPoly();

	printf("Enter integer to show bottom clipped version ");
	scanf("%d",&i);

	glClear(GL_COLOR_BUFFER_BIT);
    drawFrame();
	bottomClip();
	drawPoly();

	glutMainLoop();

}
