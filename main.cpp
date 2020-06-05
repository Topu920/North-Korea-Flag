#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
const float Pi = 3.1415926535897932384626433832795;
void DrawStar(float fX, float fY) {


	// Draw ten triangles
	const float Radius = 0.11;
	const float InnerRadius = Radius*(1.0/(sin((2.0*Pi)/5.0)*2.0*cos(Pi/10.0) + sin((3.0*Pi)/10.0)));
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0);
		for (int i = 0; i < 10; ++i) {
			float fAngleStart	= Pi/2.0 + (i*2.0*Pi)/10.0;
			float fAngleEnd		= fAngleStart + Pi/5.0;
			if (i % 2 == 0) {
				glVertex3f(fX + Radius*cos(fAngleStart)/1.9, fY + Radius*sin(fAngleStart), 0.0);
				glVertex3f(fX + InnerRadius*cos(fAngleEnd)/1.9, fY + InnerRadius*sin(fAngleEnd), 0.0);
			} else {
				glVertex3f(fX + InnerRadius*cos(fAngleStart)/1.9, fY + InnerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + Radius*cos(fAngleEnd)/1.9, fY + Radius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

void quad()
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);///blue
		glVertex3f(0.2, 0.8, 0.0);
		glVertex3f(0.8, 0.8, 0.0);
		glVertex3f(0.8, 0.2, 0.0);
		glVertex3f(0.2, 0.2, 0.0);

		glColor3f(1.0, 1.0, 1.0);///white

		glVertex3f(0.2, 0.7, 0.0);
		glVertex3f(0.8, 0.7, 0.0);
		glVertex3f(0.8, 0.3, 0.0);
		glVertex3f(0.2, 0.3, 0.0);


		glColor3f(1.0, 0.0, 0.0);///red

		glVertex3f(0.2, 0.65, 0.0);
		glVertex3f(0.8, 0.65, 0.0);
		glVertex3f(0.8, 0.35, 0.0);
		glVertex3f(0.2, 0.35, 0.0);

        glEnd();





}
void circle()
{
     glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    float n;
    for(int i=0;i<360;i++)
    {
        n=i*Pi/180;
       glVertex3f(0.4+.1*cos(n),0.5+.1*sin(n),0.0);

    }


        glEnd();
}


void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);


     quad();
     circle();
     DrawStar(.4,.5);
	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(950, 500);///black windows er length and wide
	glutInitWindowPosition(100, 100);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
