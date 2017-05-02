// OpenGL Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "glut.h"
#include <iostream>
//#include <GL/glut.h>

// stała do obsługi menu podręcznego
enum
{
EXIT // wyjście
};

double PredkoscKamery=0;
// pionowy kąt pola widzenia
GLdouble fovy = 60;
float czajnikrot=0;
float katkamera1=90;
// wpółrzędne położenia obserwatora
GLdouble eyex = 0;
GLdouble eyey = 0;
GLdouble eyez = 3;

GLdouble ObrotX=3.14/2.0;
GLdouble ObrotY=0;

bool KeyUP=false;
bool KeyDOWN=false;
bool KeyRIGHT=false;
bool KeyLEFT=false;

// współrzędne punktu, w którego kierunku jest zwrócony obserwator,
GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = -100;

int figure=0;
float kat=0;

GLuint idlisty;

// my own -----------------------------------------------------------------------

int circle(double radius, int points, int index) {
	double rX = radius;
	double rY = radius;
	double a = -180.0;
	for (int i = 0; i < index; ++i) {
		a += 360.0 / points;
		double x = radius * cos(a * M_PI/180.0);
		double y = radius * sin(a * M_PI/180.0);
		glVertex3f (x, y, 0.0);
	}
	return 0;
}

// ------------------------------------------------------------------------------

// funkcja generująca scenę 3D
void GenerujListyWyswietlania()
{
	idlisty = glGenLists( 4 );
	glColor3f(0, 0.8, 0);
	// utworzenie pierwszej listy
	glNewList( idlisty + 0, GL_COMPILE );
	glTranslatef(0,0,10);
	glutSolidCube(1);
	glEndList();

	// utworzenie drugiej listy
	glNewList( idlisty + 1, GL_COMPILE );
	glTranslatef(0,0,8);

	//glutWireTeapot(1);

	glTranslatef(0,0,10);
//	glutWireTeapot(1);
	glTranslatef(0,0,10);
	glutSolidTeapot(1);

	glPushMatrix();
	glTranslatef(0,0,-40);
	glutSolidTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20,0,-10);
	glutSolidTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20,0,-10);
	glutSolidTeapot(1);
	glPopMatrix();




	//podstawa czerwona
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(0.0f, -2.0f, 0.0f);
	glScalef(100.0f,0.02f,100.0f);
	glutSolidSphere(10, 1000, 1000);
	glPopMatrix();

















	//koniec czajnika, moje:
	glTranslatef(0, 0, 2);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



	



















	//GORA NAKRETKI
	glColor3f(0, 0.8, 0);
	glBegin(GL_TRIANGLE_STRIP);
	double kat = 0.0;
	double r1 = 1.0;
	double r2 = 1.5;
	int poi = 6;
	glNormal3f(0,0,-1);
	for (int i = 0; i < poi; i++) {
		
		double xx = r1*cos(kat*M_PI / 180);
		double yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -22);
		xx=r2*cos(kat*M_PI / 180);
		yy=r2*sin(kat*M_PI / 180);
		kat += 360 / poi;
		glVertex3d(xx, yy, -22);
	}
	double xx = r1*cos(kat*M_PI / 180);
	double yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	xx = r2*cos(kat*M_PI / 180);
	yy = r2*sin(kat*M_PI / 180);
	kat += 360 / poi;
	glVertex3d(xx, yy, -22);
	glEnd();


	//DOL NAKRETKI
	glColor3f(0, 0, 0.8);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 1.0;
	r2 = 1.5;
	poi = 6;
	glNormal3f(0,0,1);
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -21.5);
		xx = r2*cos(kat*M_PI / 180);
		yy = r2*sin(kat*M_PI / 180);
		kat += 360 / poi;
		glVertex3d(xx, yy, -21.5);
	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -21.5);
	xx = r2*cos(kat*M_PI / 180);
	yy = r2*sin(kat*M_PI / 180);
	kat += 360 / poi;
	glVertex3d(xx, yy, -21.5);
	glEnd();


	//bok nakretki wnetrze
	glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 1.0;
	r2 = 1.5;
	poi = 6;
	for (int i = 0; i < poi; i++) {
		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glNormal3f(xx,yy,0);
		glVertex3d(xx, yy, -22);
		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -21.5);
		glNormal3f(xx,yy,0);
		kat += 360 / poi;	
	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);

	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -21.5);


	glEnd();



	//bok nakretki zewnatrz
	glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 1.0;
	r2 = 1.5;
	poi = 6;
	for (int i = 0; i < poi; i++) {
		xx = r2*cos(kat*M_PI / 180);
		yy = r2*sin(kat*M_PI / 180);
		glNormal3f(xx,yy,0);
		glVertex3d(xx, yy, -22);
		xx = r2*cos(kat*M_PI / 180);
		yy = r2*sin(kat*M_PI / 180);
		glNormal3f(xx,yy,0);
		glVertex3d(xx, yy, -21.5);
		
		kat += 360 / poi;
	}
	xx = r2*cos(kat*M_PI / 180);
	yy = r2*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);

	xx = r2*cos(kat*M_PI / 180);
	yy = r2*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -21.5);


	glEnd();



	//rurka 1
	//gorne kolko
	//glTranslatef(0, 0, 1.75);
	glRotated(90, 0, 1, 0);
	glRotated(45, 1, 0, 0);
	glColor3f(0, 1.0, 1.0);
	glTranslatef(21.8, 0, 24);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);

		glVertex3d(xx, yy, -22);
		glVertex3d(0, 0, -22);
		kat += 360 / poi;
		
	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	glVertex3d(0, 0, -22);
	glEnd();

	//dolne kolko
	//glTranslatef(3, 3, 2);
	glColor3f(0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -26);
		glVertex3d(0, 0, -26);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -26);
	glVertex3d(0, 0, -26);
	glEnd();

	//polaczenie kola
	//glTranslatef(3, 3, 2);
	glColor3f(0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glNormal3f(xx,yy,0);
		glVertex3d(xx, yy, -22);
		glNormal3f(xx,yy,0);
		glVertex3d(xx, yy, -26);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	glVertex3d(xx, yy, -26);
	glEnd();
















	//rurka 2
	//gorne kolko
	glColor3f(0, 1.0, 1.0);
	glRotated(90, 1, 0, 0);

	glTranslatef(0, -24, 24);

	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -22);
		glVertex3d(0, 0, -22);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	glVertex3d(0, 0, -22);
	glEnd();

	//dolne kolko
	//glTranslatef(3, 3, 2);
	glColor3f(0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -26);
		glVertex3d(0, 0, -26);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -26);
	glVertex3d(0, 0, -26);
	glEnd();

	//polaczenie kola
	//glTranslatef(3, 3, 2);
	glColor3f(0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -22);
		glVertex3d(xx, yy, -26);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	glVertex3d(xx, yy, -26);
	glEnd();











	//rurka 3
	//gorne kolko
	glPushMatrix();
	glColor3f(1.0, 0, 0);
	glTranslated(0, 0, 2);
	glRotated(45, 1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -22);
		glVertex3d(0, 0, -22);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	glVertex3d(0, 0, -22);
	glEnd();

	//dolne kolko
	//glTranslatef(3, 3, 2);
	glColor3f(0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glVertex3d(xx, yy, -26);
		glVertex3d(0, 0, -26);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -26);
	glVertex3d(0, 0, -26);
	glEnd();

	//polaczenie kola
	//glTranslatef(3, 3, 2);
	glColor3f(0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	kat = 0.0;
	r1 = 0.1;
	poi = 24;
	for (int i = 0; i < poi; i++) {

		xx = r1*cos(kat*M_PI / 180);
		yy = r1*sin(kat*M_PI / 180);
		glNormal3f(xx,yy,1);
		glVertex3d(xx, yy, -22);
		glNormal3f(xx,yy,1);
		glVertex3d(xx, yy, -26);
		kat += 360 / poi;

	}
	xx = r1*cos(kat*M_PI / 180);
	yy = r1*sin(kat*M_PI / 180);
	glVertex3d(xx, yy, -22);
	glVertex3d(xx, yy, -26);
	glEnd();
	glPopMatrix();










	glEndList();

	//utworzenie trzeciej listy
	//glNewList( idlisty + 2, GL_COMPILE );
	//glTranslatef(0,0,10);
	//glutWireCone(1,1,10,10);
	//glEndList();


	// my own -----------------------------------------------------------------------

	glNewList( idlisty + 2, GL_COMPILE );
	glTranslatef(0,0,10);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	float a;
	int points;
	float radius;
	float z1;
	float z2;

	radius = 1;
	points = 6;
	z1 = -0.5;
	z2 = 0.5;

	glRotatef(30, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	//glRotatef(30, 0, 0, 1);

	// Śruba

	glColor3f( 0.0, 0.0, .8 );
	glBegin (GL_TRIANGLE_FAN);
	a= -180.0;
	glVertex3f(0, 0, z1);
	for (int i = 0; i <= points; ++i) {
		a += 360.0 / points;
		float x = radius * cos(a * M_PI/180.0);
		float y = radius * sin(a * M_PI/180.0);
		glVertex3f(x, y, z1);
	}
    glEnd ();

	glColor3f( 0.8, 0.0, 0 );
	glBegin (GL_TRIANGLE_FAN);
	a= -180.0;
	glVertex3f(0, 0, z2);
	for (int i = 0; i <= points; ++i) {
		a += 360.0 / points;
		float x = radius * cos(a * M_PI/180.0);
		float y = radius * sin(a * M_PI/180.0);
		glVertex3f(x, y, z2);
	}
    glEnd ();

	glColor3f( 0, 0.8, 0 );
	glBegin (GL_TRIANGLE_STRIP);
	a= -180.0;
	for (int i = 0; i <= points; ++i) {
		a += 360.0 / points;
		float x = radius * cos(a * M_PI/180.0);
		float y = radius * sin(a * M_PI/180.0);
		glVertex3f(x, y, z1);
		glVertex3f(x, y, z2);
	}
    glEnd ();

	// Śruba end



	// Rura
	radius = 0.15;
	points = 12;
	z1 = 5;
	z2 = -5;

	glRotatef(90, 0, 1, 0);
	glRotatef(90, 1, 0, 0);


	glColor3f( 0.8, 0, .8 );
	glBegin (GL_TRIANGLE_FAN);
	a= -180.0;
	glVertex3f(0, 0, z1);
	for (int i = 0; i <= points; ++i) {
		a += 360.0 / points;
		float x = radius * cos(a * M_PI/180.0);
		float y = radius * sin(a * M_PI/180.0);
		glVertex3f(x, y, z1);
	}
    glEnd ();

	glColor3f( 0.8, 0.8, 0 );
	glBegin (GL_TRIANGLE_FAN);
	a= -180.0;
	glVertex3f(0, 0, z2);
	for (int i = 0; i <= points; ++i) {
		a += 360.0 / points;
		float x = radius * cos(a * M_PI/180.0);
		float y = radius * sin(a * M_PI/180.0);
		glVertex3f(x, y, z2);
	}
    glEnd ();

	glColor3f( 0, 0.8, 0.8 );
	glBegin (GL_TRIANGLE_STRIP);
	a= -180.0;
	for (int i = 0; i <= points; ++i) {
		a += 360.0 / points;
		float x = radius * cos(a * M_PI/180.0);
		float y = radius * sin(a * M_PI/180.0);
		glVertex3f(x, y, z1);
		glVertex3f(x, y, z2);
	}
    glEnd ();

	//Rura end


	// Gwint

	radius = 0.151;

	glColor3f( 0, 0, 1 );
	glBegin (GL_LINE_STRIP);

	while (z2 < z1) {
		a= -180.0;
		for (int i = 0; i <= points; ++i) {
			a += 360.0 / points;
			float x = radius * cos(a * M_PI/180.0);
			float y = radius * sin(a * M_PI/180.0);
			glVertex3f(x, y, z2);
			z2 += 0.003;
			if (z2 > z1) break;
		}
	}
    glEnd ();

	glEndList();

	// -----------------------------------------------------------------
}

void UstawKamere(){

double cosx, siny, sinx;
double CelX, CelY, CelZ;
// wartości funkcji trygonometrycznych
// obliczamy tylko raz dla oszczędności
if (KeyDOWN) PredkoscKamery=-0.03;
if (KeyUP) PredkoscKamery=0.03;
if (KeyLEFT) ObrotX-=0.03;
if (KeyRIGHT) ObrotX+=0.03;

siny = sin(ObrotY);
cosx = cos(ObrotX);
sinx = sin(ObrotX);

// nowa pozycja kamery
eyex += cosx*PredkoscKamery;
eyey += siny*PredkoscKamery;
eyez += sinx*PredkoscKamery;

// punkt wycelowania kamery powinien

// znajdować się gdzieś "przed jej nosem"
CelX = eyex+cosx;
CelY = eyey+siny;
CelZ = eyez+sinx;

gluLookAt(eyex, eyey, eyez,CelX, CelY, CelZ, 0, 1, 0);
//gluLookAt( eyex, eyey, eyez, centerx, centery, centerz, 0, 1, 0 );
PredkoscKamery=0;
}

void Display()
{
	katkamera1++;
	// kolor tła - zawartość bufora koloru
	//glClearColor( 1.0, 1.0, 1.0, 1.0 );
	glClearColor( 0, 0, 0, 1.0 );
	// czyszczenie bufora koloru
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	//GLfloat ambientlight[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientlight);

//	glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	//glEnable(GL_NORMALIZE);

	// wybór macierzy modelowania
	glMatrixMode( GL_MODELVIEW );
	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	UstawKamere();
	glEnable(GL_LIGHTING);
    //GLfloat ambientlight[]={1.0, 1.0, 1.0, 1.0};
        GLfloat ambientlight[]={0.2, 0.2, 0.2, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientlight);
 
 
    GLfloat gray[] = {0.75, 0.75, 0.75, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
 
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
 
 
 
    glEnable(GL_NORMALIZE);
    GLfloat DiffuseLight1[]={1.0,1.0,1.0,1.0};
    GLfloat LightPosition1[]={0.0, 0.0, 60.0, 1.0};
    GLfloat AmbientLight[]={0.1, 0.1, 0.1, 1.0};
 
 
    glLightfv( GL_LIGHT0, GL_DIFFUSE, DiffuseLight1 );
	glPushMatrix();
	
	glRotatef(katkamera1, 0,1,0);

    glLightfv( GL_LIGHT0, GL_POSITION, LightPosition1 );
	glPopMatrix();
    
	glLightfv( GL_LIGHT0, GL_AMBIENT, AmbientLight );
    glEnable(GL_LIGHT0);
 
    GLfloat specular[]={1.0,1.0,1.0,1.0};
    glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
 
 
    GLfloat specref[]={1.0,1.0,1.0,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 56);

	/*
	glEnable(GL_LIGHTING);
	//GLfloat ambientlight[]={1.0, 1.0, 1.0, 1.0};
		GLfloat ambientlight[]={0.2, 0.2, 0.2, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientlight);


	GLfloat gray[] = {0.75, 0.75, 0.75, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);



	glEnable(GL_NORMALIZE);
	GLfloat DiffuseLight1[]={1.0,1.0,1.0,1.0};

	
	GLfloat LightPosition1[]={0.0, 0.0, 60.0, 1.0};
	GLfloat AmbientLight[]={0.1, 0.1, 0.1, 1.0};
	glLightfv( GL_LIGHT0, GL_DIFFUSE, DiffuseLight1 );

	glPushMatrix();
	glRotatef(katkamera1, 0, 1, 0);
	glLightfv( GL_LIGHT0, GL_POSITION, LightPosition1 );
	glPopMatrix();



	//test
	
	GLfloat LightPosition2[]={0.0, 0.0, 5.0, 2.0};
	glPushMatrix();
	glRotatef(katkamera1+180.0f, 0, 1, 0);
	glLightfv( GL_LIGHT0, GL_POSITION, LightPosition2 );
	glPopMatrix();



	
	//koniec testu
	glLightfv( GL_LIGHT0, GL_AMBIENT, AmbientLight );
	glEnable(GL_LIGHT0);

	GLfloat specular[]={1.0,1.0,1.0,1.0};
	glLightfv( GL_LIGHT0, GL_SPECULAR, specular );


	GLfloat specref[]={1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 56);

























	// ustawienie obserwatora
	//glRotatef(kat,1,0,0);
	// przesunięcie obiektu o wektor [0,0,-3]
	//glTranslatef( 0, 0, 2.0 );
	// kolor krawędzi sześcianu
	glColor3f( 0.0, 0.0, 0.0 );
	// glutWireCube(1);
	*/
	switch (figure)
	{
	case 1:
		glCallList(idlisty+0);
		break;
	case 2:
		glCallList(idlisty+1);
		break;
	case 3:
		glCallList(idlisty+2);
		break;
	}

	// skierowanie poleceń do wykonania
	glFlush();
	// zamiana buforów koloru
	glutSwapBuffers();
}

// zmiana wielkości okna

void Reshape( int width, int height )
{
	// obszar renderingu - całe okno
	glViewport( 0, 0, width, height );
	// wybór macierzy rzutowania
	glMatrixMode( GL_PROJECTION );
	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();
	// obliczenie aspektu obrazu z uwzględnieniem
	// przypadku, gdy wysokość obrazu wynosi 0
	GLdouble aspect = 1;

	if( height > 0 )
		aspect = width /( GLdouble ) height;

	// rzutowanie perspektywiczne
	gluPerspective( fovy, aspect, 0.01, 100.0 );
	// generowanie sceny 3D
	Display();
}

// obsługa klawiatury
void Klawisze( unsigned char key, int x, int y )
{
	// klawisz +
	if( key == '+' && fovy < 180 )
	fovy++;
	// klawisz -
	if( key == '-' && fovy > 0 )
	fovy--;
	if( key == 'a' && fovy > 0 )
	kat++;
	if( key == 'w' )
	PredkoscKamery=0.02;
	if( key == 's' )
	PredkoscKamery=-0.02;
	if( key == 'e' )
	ObrotX+=0.02;
	if( key == 'q' )
	ObrotX-=0.02;
	if( key == 'r' )
	ObrotY+=0.02;
	if( key == 'f' )
	ObrotY-=0.02;
	// odrysowanie okna
	Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );
}

void KlawiszeSpecjalne( int key, int x, int y )
{
switch( key )

{

// kursor w lewo

case GLUT_KEY_LEFT:

eyex += 0.1;

break;

// kursor w górę

case GLUT_KEY_UP:

eyey -= 0.1;

break;

// kursor w prawo

case GLUT_KEY_RIGHT:

eyex -= 0.1;

break;

// kursor w dół

case GLUT_KEY_DOWN:

eyey += 0.0;

break;

}

// odrysowanie okna

Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );

}

// obsługa menu podręcznego

void Menu( int value )

{

switch( value )

{

// wyjście

case EXIT:

exit( 0 );

// wyjście

case 1:

figure=1;

break;

case 2:

figure=2;

break;

case 3:

figure=3;

break;

}

Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );

}

void KeyDown(int key,int x,int y){

switch(key){

case GLUT_KEY_UP:

KeyUP=true;

break;

case GLUT_KEY_DOWN:

KeyDOWN=true;

break;

case GLUT_KEY_LEFT:

KeyLEFT=true;

break;

case GLUT_KEY_RIGHT:

KeyRIGHT=true;

break;

}

}

void KeyUp(int key,int x,int y){

switch(key){

case GLUT_KEY_UP:

KeyUP=false;

break;

case GLUT_KEY_DOWN:

KeyDOWN=false;

break;

case GLUT_KEY_LEFT:

KeyLEFT=false;

break;

case GLUT_KEY_RIGHT:

KeyRIGHT=false;

break;

}

}

int main( int argc, char * argv[] )

{

// inicjalizacja biblioteki GLUT

glutInit( & argc, argv );

// inicjalizacja bufora ramki

glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

// rozmiary głównego okna programu

glutInitWindowSize( 800, 800 );

// utworzenie głównego okna programu

#ifdef WIN32

glutCreateWindow( "Sześcian 3" );

#else

glutCreateWindow( "Szescian 3" );

#endif

// dołączenie funkcji generującej scenę 3D

glutDisplayFunc( Display );

// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna

glutReshapeFunc( Reshape );

// dołączenie funkcji obsługi klawiatury

glutKeyboardFunc( Klawisze );

// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora

// glutSpecialFunc( KlawiszeSpecjalne );

glutSpecialFunc(KeyDown);

glutSpecialUpFunc(KeyUp);

// utworzenie menu podręcznego

glutCreateMenu( Menu );

// dodanie pozycji do menu podręcznego

glutAddMenuEntry( "Wyjście", EXIT );

glutAddMenuEntry( "Rys1", 1 );
glutAddMenuEntry( "Rys2", 2 );
glutAddMenuEntry( "Rys3", 3 );

// określenie przycisku myszki obsługującej menu podręczne
glutAttachMenu( GLUT_RIGHT_BUTTON );

GenerujListyWyswietlania();

glutIdleFunc(Display);

// wprowadzenie programu do obsługi pętli komunikatów

glutMainLoop();

return 0;

}
