#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<math.h>
GLfloat x,a,b,c,d;
int oil1,oil2,oil3;
int flag=0,dialogcount=0;


void ship()
{
  glPushMatrix();
  glTranslatef(a,0,0);	
  glColor3f(0.4,0.4,0.4);
  glBegin(GL_POLYGON);
  glVertex2f(48,388);
  glVertex2f(48,420);
  glVertex2f(52,422);
  glVertex2f(53,388);
  glEnd();	

  glColor3f(0.8,0.6,0.6);
  glBegin(GL_POLYGON);
  glVertex2f(28,378);
  glVertex2f(28,390);
  glVertex2f(100,390);
  glVertex2f(100,378);
  glEnd();	
   	
  glColor3f(0.6,0.6,0.6);
  glBegin(GL_POLYGON);
  glVertex2f(28,368);
  glVertex2f(28,380);
  glVertex2f(220,380);
  glVertex2f(224,368);
  glEnd();	
  
  for(int i=36;i<200;i+=16)
  {
	  glColor3f(0.9,0.9,0.9);
      glBegin(GL_POLYGON);
      glVertex2f(i,370);
      glVertex2f(i,378);
      glVertex2f(i+8,378);
      glVertex2f(i+8,370);
      glEnd();
  }	
	
  glColor3f(0.4,0.4,0.4);
  glBegin(GL_POLYGON);
  glVertex2f(30,340);
  glVertex2f(20,370);
  glVertex2f(230,370);
  glVertex2f(210,340);
  glEnd();
  glPopMatrix();
  
}

void oildrop1()
{
  glPushMatrix();
  glTranslatef(0,c,0);	
  glColor3f(.5,.5,.5);
  glBegin(GL_POLYGON);
  glVertex2f(48,340);
  glVertex2f(50,360);
  glVertex2f(50,370);
  glVertex2f(48,375);
  glVertex2f(46,370);
  glVertex2f(46,360);
  glVertex2f(48,340);
  glEnd();
  glPopMatrix();
}

void oildrop2()
{
  glPushMatrix();
  glTranslatef(0,d,0);	
  glColor3f(.5,.5,.5);
  glBegin(GL_POLYGON);
  glVertex2f(735,340);
  glVertex2f(737,360);
  glVertex2f(737,370);
  glVertex2f(735,375);
  glVertex2f(733,370);
  glVertex2f(733,360);
  glVertex2f(735,340);
  glEnd();
  glPopMatrix();
}
void fishes(int x,int y,int z)
{
 glPushMatrix();
 glTranslatef(z,0,0);	
 glColor3f(0,1,0);
 glBegin(GL_POLYGON);
 glVertex2f(50+x,250+y);
 glVertex2f(45+x,260+y);
 glVertex2f(55+x,255+y);
 glVertex2f(55+x,245+y);
 glVertex2f(45+x,240+y);
 glVertex2f(50+x,250+y);
 glEnd();

 glBegin(GL_POLYGON);
 glVertex2f(55+x,255+y);
 glVertex2f(65+x,260+y);
 glVertex2f(75+x,265+y);
 glVertex2f(85+x,265+y);
 glVertex2f(90+x,260+y);
 glVertex2f(95+x,250+y);
 glVertex2f(92+x,245+y);
 glVertex2f(85+x,242+y);
 glVertex2f(75+x,240+y);
 glVertex2f(65+x,240+y);
 glVertex2f(55+x,245+y);
 glVertex2f(55+x,255+y);
 glEnd();

 glColor3f(0,0,0);
 glBegin(GL_LINE_STRIP);
 glVertex2f(95+x,250+y);
 glVertex2f(90+x,250+y);
 glVertex2f(82+x,252+y);
 glEnd();
 
 glPointSize(2.5);//eye
 glColor3f(0,0,0);
 glBegin(GL_POINTS);
 glVertex2f(90+x,253+y);
 glEnd();
 
 glPopMatrix();
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,350);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,350);
glEnd();
}
{
//sea
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,350);
glVertex2f(1100,350);
glVertex2f(1100,0);
glEnd();
}

   glPushMatrix();
	glTranslatef(a,0,0);
	ship();
	glPopMatrix();
    glPushMatrix();
      
	glTranslatef(b,0,0);
	fishes(0,0,b);
    if(a<425)
	  fishes(-200,-135,b);
	fishes(-300,-100,b);  
	fishes(100,-150,b);
	if(a<80)
	  fishes(-200,-65,b);
	glPopMatrix();
	glPushMatrix();
	
	if(a>0)
	{
	glTranslatef(0,c,0);
	oildrop1();
	glPopMatrix();
	glPushMatrix();
    }
	
	if(a>350)
	{
	glTranslatef(0,d,0);
	oildrop2();
	glPopMatrix();
	glPushMatrix();
    }
	
//sun


	for(l=0;l<=50;l++)
{
		glColor3f(0.992,0.721,0.075);
		draw_circle(100,625,l);
}
}

void cloud()

{
    int l;


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200,625,l);
		draw_circle(225,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370,550,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410,550,l);
		draw_circle(435,550,l);
		draw_circle(470,550,l);
	}

    for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500,550,l);
    }
    
    //cloud3

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(600,600,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(650,600,l);
		draw_circle(675,600,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(675,600,l);
	}
 }   

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void displayfst()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
cloud();
glFlush();
glutPostRedisplay();
glutSwapBuffers();
}


void spin()
{
if(a>600)
a=-115;
else
a=a+2;

if(b>600)
b=-115;
else
b=b+2;


if(c<-600)
c=115;
else
c=c-2;

if(a>=350)
  flag=1;
if(flag==1)
{
if(d<-600)
{
d=0;flag=0;
}
else
d=d-3;
}

glutPostRedisplay();
}
int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("FISHING");
	myinit();
	glutDisplayFunc(displayfst);
    glutIdleFunc(spin);
	//update();
	glutMainLoop();
	return 0;
}
