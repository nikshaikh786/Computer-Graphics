#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>

const double PI = 3.141592654;
int frameNumber = 0;

void drawDisk(double radius)
{
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void drawWheel()
{	
	int i;
	//Drawing 12 seats
	glColor3f(1,0.2,0);
	for (i = 0; i < 12; i++)	
	{ 
		glRotatef( 360/12, 0, 0, 1 ); 
		glBegin(GL_POLYGON);
		glVertex2f(1.25,1);
		glVertex2f(1.25,1.25);
		glVertex2f(1.6,1.25);
		glVertex2f(1.6,1);
		glEnd();
	}
	
	glColor3f(0,0.5,0.5);
	drawDisk(1.5);
	
	glColor3f(1,1,1);
	drawDisk(1.4);

	glColor3f(0,0.5,0.5);
	drawDisk(0.8);
	
	glColor3f(1,1,1);
	drawDisk(0.7);
	
	//Drawing 12 strokes
	glColor3f(1,0.2,0);
	for (int i = 0; i < 12; i++)	
	{ 
		glRotatef( 360 / 12, 0, 0, 1 );
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.05, 0);
		glVertex2f(1.25, 1);
		glVertex2f(1.3, 1);
		glEnd();
	}
}

void drawStand()
{	
	glColor3f(0,0.5,0.5);
	drawDisk(0.2);
	
	glColor3f(0,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,0);
	glVertex2f(0,0);
	glVertex2f(-1.1,-2.1);
	glVertex2f(-1,-2.1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.1,0);
	glVertex2f(0,0);
	glVertex2f(1,-2.1);
	glVertex2f(1.1,-2.1);
	glEnd();
	
	glColor3f(0.5,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-1.8,-2.1);
	glVertex2f(-1.8,-2.3);
	glVertex2f(1.8,-2.3);
	glVertex2f(1.8,-2.1);
	glEnd();	
}

void drawSun() {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 13; i++)
	{ 
		glRotatef( 360 / 13, 0, 0, 1 );
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0.4, 0);
		glEnd();
	}
	drawDisk(0.3);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
	glTranslated(3.5,2,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawWheel();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(3.5,2,0);
	drawStand();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(6.2,3.3,0);
	drawSun();
	glPopMatrix();

	
	glColor3f( 1, 0, 0 );
	glRasterPos2f(2.75,-0.6);
	int len0, i;
	char string[] ="FERRIS WHEEL";
	len0 = (int)strlen(string);
	for (i = 0; i < len0; i++)
		glutBitmapCharacter(  GLUT_BITMAP_TIMES_ROMAN_24 , string[i]);
		
	glColor3f( 1, 0, 0 );
	glRasterPos2f(6,0);
	int len1, m;
	char made[] ="MADE BY-";
	len1 = (int)strlen(made);
	for (m = 0; m < len1; m++)
		glutBitmapCharacter(  GLUT_BITMAP_9_BY_15 , made[m]);
		
	glColor3f( 1, 0, 0 );
	glRasterPos2f(6,-0.2);
	int len2, a;
	char roll1[] ="17CO41";
	len2 = (int)strlen(roll1);
	for (a = 0; a < len2; a++)
		glutBitmapCharacter(  GLUT_BITMAP_9_BY_15 , roll1[a]);
		
	glColor3f( 1, 0, 0 );
	glRasterPos2f(6,-0.4);
	int len3, f;
	char roll2[] ="17CO45";
	len3 = (int)strlen(roll2);
	for (f = 0; f < len3; f++)
		glutBitmapCharacter(  GLUT_BITMAP_9_BY_15 , roll2[f]);
		
	glColor3f( 1, 0, 0 );
	glRasterPos2f(6,-0.6);
	int len4, s;
	char roll3[] ="17CO48";
	len4 = (int)strlen(roll3);
	for (s = 0; s < len4; s++)
		glutBitmapCharacter(  GLUT_BITMAP_9_BY_15 , roll3[s]);

	glutSwapBuffers();
}

void doFrame(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(1,doFrame,0);
}

void init()
{
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);  
    glutCreateWindow("Ferris Wheel"); 

    init();

    glutDisplayFunc(display);   
    glutTimerFunc(200,doFrame,0); 

    glutMainLoop(); 
    return 0;
}    

