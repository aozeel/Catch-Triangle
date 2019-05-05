#include "GL\glew.h"
#include "GL\freeglut.h"
#include<windows.h>
#include "string"
#include<iostream>
#include <stdlib.h>
#include <sstream>
#include <cstdlib> 
#include <ctime> 
#include "cmath"

using namespace std;

int i, y, z, ilkucgensag, ilkucgensol, ilkucgenorta, ikiucgensag, ikiucgensol, ikiucgenorta;
int ucucgensag, ucucgensol, ucucgenorta;
float xr = 0, yr1 = 0, yr2 = 0, yr3 = 0;
int karesol, karesag, yucgenkenarsag, yuckenkenarsol;
const int font = (int)GLUT_BITMAP_9_BY_15;
char s[30];
float ucgenbiryatayrandom, ucgenikiyatayrandom, ucgenucyatayrandom;
float xranddeger, ikiranddeger, ucranddeger;
int skor,geciciskor = 0;
bool playGame = true;



void sekmeAlgila();
float RandomFloat(float a, float b);


void idle() {
	
	
	sekmeAlgila();
	yr1 = yr1 - 0.1;
	yr2 -= 0.05;
	yr3 -= 0.1;


	ucgenbiryatayrandom += xranddeger;
	ucgenikiyatayrandom += ikiranddeger;
	ucgenucyatayrandom += ucranddeger;
	

	if (yr1 < -601) {
		yr1 = 100;

		
		i = (rand() % 5) * 75;
		
		xranddeger = RandomFloat(0.0, 0.4) - 0.2;
		ucgenbiryatayrandom = 0;

		
	}
	if (yr2 < -601) {
		yr2 = 200;
		y = (rand() % 5) * 75;
		ikiranddeger = RandomFloat(0.0, 0.4) - 0.2;
		ucgenikiyatayrandom = 0;
		
	}
	if (yr3 < -601) {
		yr3 = 300;
		z = (rand() % 5) * 75;
		ucranddeger = RandomFloat(0.0, 0.4) - 0.2;
		ucgenucyatayrandom = 0;
		
	}

	if (i == y) { y = (rand() % 5) * 75; }
	if (i == z) { z = (rand() % 5) * 75; }







	glutPostRedisplay();
}

float RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

void sekmeAlgila() {
	if (ilkucgensol <= 0 || ilkucgensag >= 400) {
		xranddeger = -xranddeger;

	}
	if (ikiucgensol <= 0 || ikiucgensag >= 400) { ikiranddeger = -ikiranddeger; }
	if (ucucgensol <= 0 || ucucgensag>=400) { ucranddeger = -ucranddeger; }

}
void enter_giris(unsigned char key, int x, int y) {
	if (key == 13 && playGame == false) {
		playGame = true;
		yr1 = yr2 = yr3 = 0;
		geciciskor = clock() / 1000;

	}

}

void tus_giris(int key, int x, int y) {
	switch (key) {

	case GLUT_KEY_LEFT:
		xr = xr - 15; if (xr <= -175) { xr = -175; }
		
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		xr = xr + 15; if (xr >= 175) { xr = 175; }
		
		
		glutPostRedisplay();
		break;
	case GLUT_KEY_HOME:
		exit(0);
		break;
	}


}

void renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}



bool kontrolet(int karesol, int karesag, int ucgensol, int ucgensag, int yuckenkenarsol, int yuckenkenarsag) {
	if ((karesol <= yuckenkenarsag && karesol - ucgensol>0) || ((karesag >= ucgensol && karesag >= yuckenkenarsol) && ucgensag - karesag>0)) {
		//karenin ucgene saðdan ve soldan çarpma durumlarýný ayrý ayrý ele alýnmýþtýr.
		//kare üçgenin saðýndaysa ve temas ediyorsa, karesol deðeri ucgensag deðerinden küçük veya eþit demektir.
		//kare üçgenin solundaysa ve temas ediyorsa, karesag deðeri ucgensol deðerinden büyük veya eþit demektir.
		renderBitmapString(0, 200, (void *)font, "Oyun Bitti,Yeniden baslamak icin enter'a týkla");
		renderBitmapString(0, 200, (void*)font, s);
		playGame = false;




	}
	return true;
}




void display()
{
	if (playGame == true) {


		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.5, 0.3, 1.0);
		//glPointSize(5.0f);
		glBegin(GL_QUADS);
		glVertex2f(175 + xr, 25);
		glVertex2f(225 + xr, 25);
		glVertex2f(karesag = (225 + xr), 75);
		glVertex2f(karesol = (175 + xr), 75);
		glEnd();


		//0,400 baslangýc noktasý
		glColor3f(0.1, 0.5, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(ilkucgensol = (0 + i + ucgenbiryatayrandom), 550 + yr1);
		glVertex2f(ilkucgensag = (75 + i + ucgenbiryatayrandom), 550 + yr1);
		glVertex2f(ilkucgenorta = (37.5 + i + ucgenbiryatayrandom), 475 + yr1);
		glEnd();

		//0,400 baslangýc noktasý
		glColor3f(0.3, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(ikiucgensol = (0 + y + ucgenikiyatayrandom), 550 + yr2);
		glVertex2f(ikiucgensag = (75 + y + ucgenikiyatayrandom), 550 + yr2);
		glVertex2f(ikiucgenorta = (37.5 + y + ucgenikiyatayrandom), 475 + yr2);
		glEnd();

		//0,400 baslangýc noktasý
		glColor3f(0.1, 0.0, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(ucucgensol = (0 + z + ucgenucyatayrandom), 550 + yr3);
		glVertex2f(ucucgensag = (75 + z + ucgenucyatayrandom), 550 + yr3);
		glVertex2f(ucucgenorta = (37.5 + z + ucgenucyatayrandom), 475 + yr3);
		glEnd();


		if (yr1 < -400 && yr1>-525) {
			int yucgenkenarsag = ilkucgenorta + ((75 - (475 + yr1)) / 2);
			int yuckenkenarsol = ilkucgenorta - ((75 - (475 + yr1)) / 2);
			kontrolet(karesol, karesag, ilkucgensol, ilkucgensag, yuckenkenarsol, yucgenkenarsag);
		}
		if (yr2<-400 && yr2>-525) {
			int ikiucgenkenarsag = ikiucgenorta + ((75 - (475 + yr2)) / 2);
			int ikiucgenkenarsol = ikiucgenorta - ((75 - (475 + yr2)) / 2);
			kontrolet(karesol, karesag, ikiucgensol, ikiucgensag, ikiucgenkenarsol, ikiucgenkenarsag);
		}
		if (yr3<-400 && yr3>-525) {
			int ucucgenkenarsag = ucucgenorta + ((75 - (475 + yr3)) / 2);
			int ucucgenkenarsol = ucucgenorta - ((75 - (475 + yr3)) / 2);
			kontrolet(karesol, karesag, ucucgensol, ucucgensag, ucucgenkenarsol, ucucgenkenarsag);
		}


		//sað üstte zamana baðlý skoru yazdýrmak
		int skor = clock() / 1000 - geciciskor;
		string yazi = std::to_string(skor);
		const char * charskor = yazi.c_str();

		renderBitmapString(350, 380, (void *)font, charskor);
		renderBitmapString(350, 380, (void*)font, s);

		
		




		glFlush();
		glutPostRedisplay();
		glutSwapBuffers();
	}
}


int main(int argc, char**argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(600, 50);
	glutCreateWindow("PROJE-1");
	void sekmealgila();

	srand(time(NULL));

	i = (rand() % 5) * 75;
	y = (rand() % 5) * 75;
	z = (rand() % 5) * 75;
	if (i == y) { y = (rand() % 5) * 75; }
	if (i == z) { z = (rand() % 5) * 75; }
	
	xranddeger = RandomFloat(0.0, 0.4) - 0.2;
	ikiranddeger = RandomFloat(0.0, 0.4) - 0.2;
	ucranddeger = RandomFloat(0.0, 0.4) - 0.2;


	glutDisplayFunc(display);
	glClearColor(1, 1, 1, 0);
	gluOrtho2D(0.0, 400, 0.0, 400);

	
	glutSpecialFunc(tus_giris);
	glutKeyboardFunc(enter_giris);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}