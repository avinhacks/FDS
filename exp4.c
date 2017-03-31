#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<GL/glut.h>
int ch, n, tx, ty;
float A[10][3], B[3][3], C[3][3];

void dis(float A[10][3], int n) {

	int i;
	glColor3f(1.0,1.0,1.0);
	
	for(i=0;i<n;i++) {

		glBegin(GL_LINES);
		glVertex2i(A[i][0],A[i][1]);
		glVertex2i(A[(i+1)%n][0], A[(i+1)%n][1]);
		glEnd();
		glFlush();
	
	}

}


void translate(float B[3][3], int tx, int ty) {

	int i,j;
	
	for(i=0;i<3;i++) {

		for(j=0;j<3;j++) {
		
			if(i==j) 
				B[i][j] = 1;
			else 
				B[i][j] = 0;		
				
		}	
	
	}

	B[2][0] = tx;
	B[2][1] = ty;

}

void shear(float B[3][3], int sx, int sy) {
	
	int i,j;
	
	for(i=0;i<3;i++) {

		for(j=0;j<3;j++) {
		
			if(i==j) 
				B[i][j] = 1;
			else 
				B[i][j] = 0;		
				
		}	
	
	}
	B[0][1] = sy;
	B[1][0] = sx;

}

void rotate(float B[3][3], int r) {

	int i, j, s1;
	float t;
	
	if(r<0) {
			s1 = -1;
	} else {
			s1 = 1;
	}

	t = r*3.14/100;
	
	for(i=0;i<3;i++) {

		for(j=0;j<3;j++) {
			if(i==j) 
				B[i][j] = 1;
			else 
				B[i][j] = 0;			
		}	
	
	}
	
	B[0][0] = B[1][1] = cos(t);
	B[0][1] = s1*sin(t);
	B[1][0] = s1*sin(t); 
	
	

} 

void scale(float B[3][3], int tx, int ty) {

	int i,j;
	
	for(i=0;i<3;i++) {

		for(j=0;j<3;j++) {
		
			if(i==j) 
				B[i][j] = 1;
			else 
				B[i][j] = 0;		
				
		}	
	
	}
	B[0][0] = tx;
	B[1][1] = ty;

}

void multiply(float A[10][3], float B[3][3], float C[10][3], int n) {

	int i, j, k;
	
	for(i=0;i<n;i++) {

		for(j=0;j<3;j++)	{
		
			C[i][j] = 0;
			for(k=0;k<3;k++) 			
				C[i][j] += A[i][k]*B[k][j];
		
		}
	
	}

}

void display() { 

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	dis(A,n);
	
	printf("\nAfter transforamtion");
	glColor3f(1.0,0.0,0.0);
	dis(C,n);
	glFlush();

}

void init() {

	glViewport(0,0,1200,800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1200.0,0.0,800.0);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv) {

		
		int ch, size, a, c, r;
		float x1, x2, x3, y1, y2, y3;

		printf("\nChoose one...\n1.Rombus \n2.Equilateral Trinangle\n");
		scanf("%d",&ch);

		switch (ch) {

			case 1:
				
				break;
			case 2:
			    n = 3;
			    A[0][2] = A[1][2] = A[2][2] = 1;  

			    printf("\nWhat do you want to do ?");
			    printf("\n1.Translation\n2.Shear\n3.Rotation\n4.Scaling");
			    scanf("%d",&c);
			    
			    printf("\n\nEnter one point of equilateral triangle:\nx-coordinate :\t");
				 scanf("%f",&x1);
				 printf("\ny-coordinate :\t");
				 scanf("%f",&y1);
				 printf("\nEnter length of one side :\t");
				 scanf("%d",&size);

				 x2 = x1 + size;
				 y2 = y1;
				 x3 = (x1+x2)/2 ;
				 y3 = y1 + sqrt((size*size) - ((size/2)*(size/2)));

				 printf("\nx2=%f\t y2=%f\t x3=%f\t y3=%f", x2,y2,x3,y3);				
						
				 A[0][0] = x1;
				 A[0][1] = y1;
				 A[1][0] = x2;
				 A[1][1] = y2;
				 A[2][0] = x3;
				 A[2][1] = y3;

			    switch(c) {
			    	case 1:
			    		
						printf("\nEnter tx:\t");
						scanf("%d", &tx);
						printf("\nEnter ty:\t");
						scanf("%d", &ty);
						
						translate(B,tx,ty);
						
						multiply(A,B,C,n);
						
						glutInit(&argc,argv);
						glutInitWindowPosition(100,100);
						glutInitWindowSize(640,480);
						glutCreateWindow("2D Translation");
						init();
						
						glutDisplayFunc(display);
						glutMainLoop();
			    		break;

			    	case 2:
			    		printf("\nEnter value for Sx & Sy:\t");
						scanf("%d%d",&tx,&ty);
						shear(B,tx,ty);
						multiply(A, B, C, n);
						
						glutInit(&argc,argv);
						glutInitWindowPosition(100,100);
						glutInitWindowSize(640,480);
						glutCreateWindow("2D Shearing");
						init();
						
						glutDisplayFunc(display);
						glutMainLoop();
			    		
			    		break;

			    	case 3:
			    		printf("\nEnter rotation angle:\t");
			    		scanf("%d",&r);
			    		rotate(B,r);
						multiply(A, B, C, n);
						
						glutInit(&argc,argv);
						glutInitWindowPosition(100,100);
						glutInitWindowSize(640,480);
						glutCreateWindow("2D Shearing");
						init();
						
						glutDisplayFunc(display);
						glutMainLoop();
			    		break;
					case 4:
						printf("\nEnter value for Sx & Sy:\t");
						scanf("%d%d",&tx,&ty);
						scale(B,tx,ty);
						multiply(A, B, C, n);
						
						glutInit(&argc,argv);
						glutInitWindowPosition(100,100);
						glutInitWindowSize(640,480);
						glutCreateWindow("2D Shearing");
						init();
						
						glutDisplayFunc(display);
						glutMainLoop();
					break;
					
			    	default:
			    	printf("\nWrong choice...");
			    }
				
				break;

			default: 
				printf("\nWrong choice please try again.");
		}
		
		return 0;	
}