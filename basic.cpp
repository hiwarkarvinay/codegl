#include <math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>
//#include <GL/OpenGL.h>

//Initialize OpenGL 
void init(void) {
    glClearColor(0.0,0.35,0.35,0.0); 
//    glMatrixMode(GL_PROJECTION); 
    glOrtho(0.0,300.0,0.0,300.0,0.0,300.0);    
} 

void drawCircle(int radius,int tx,int ty,int r,int g,int b)
{
    int points=360;
//    glClearColor(0.0,0.0,0.0,0.0);

//    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(r,g,b);    
    glBegin(GL_POLYGON);

    for(int i=0;i<points;++i)
    {
        double angle = (2*M_PI*i)/points;
        glVertex2f(cos(angle)*radius+tx,sin(angle)*radius+ty);
    }
    glEnd();


//    glFlush();
}

void drawLines(void) {
    
    int points=360;

    glClear(GL_COLOR_BUFFER_BIT);  
//  glColor3f(1.0,0.0,0.0); 
//  glBegin(GL_POLYGON);
//  glPointSize(3.0);  
    drawCircle(100,150,150,204,204,204);
    //glColor3i(255,0,0);
    drawCircle(15,100,180,255,245,185);
    drawCircle(15,200,180,255,245,185);
    
    glBegin(GL_POLYGON);

    glVertex2i(135,135);
    glVertex2i(165,135);
    glVertex2i(150,165);

    glEnd();
    
    glColor3ub(255,245,185);    
    glBegin(GL_POLYGON);
    int radius=30,tx=150,ty=110;
    for(int i=180;i<=360;++i)
    {
        double angle = (2*M_PI*i)/360;
        glVertex2f(cos(angle)*radius+tx,sin(angle)*radius+ty);
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    glVertex2i(247,160);
    glVertex2i(255,160);
    glVertex2i(255,140);
    glVertex2i(247,140);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(47,160);
    glVertex2i(55,160);
    glVertex2i(55,140);
    glVertex2i(47,140);

    glEnd();


//    glVertex2d(180, 250);
//    glVertex2d(100, 100);
//    glEnd();
    glFlush();
//    glutSwapBuffers();
} 

int main(int argc, char**argv) {
    glutInit(&argc, argv);  
    glutInitWindowPosition(10,10); 
    glutInitWindowSize(500,500); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    glutCreateWindow("Example"); 
    init(); 
    glutDisplayFunc(drawLines); 
    glutMainLoop();
}
