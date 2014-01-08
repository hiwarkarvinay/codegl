#include <math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>
#define BIG 255,255,255
#define COLOR 174,33,98
#define EYES 20,20,20
//Initialize OpenGL here
void init(void) {
    glClearColor(0.0,0.35,0.35,0.0); 
    glOrtho(0.0,300.0,0.0,300.0,0.0,300.0);    
} 

//Draw circle by connecting polygon in steps of 2pie/no_of_steps
//2pie = 360 deg
//tx,ty - Translate in x,y direction
void drawCircle(int radius,int tx,int ty,int r,int g,int b)
{
    int points=360;
    glColor3ub(r,g,b);    
    glBegin(GL_POLYGON);

    for(int i=0;i<points;++i)
    {
        double angle = (2*M_PI*i)/points;
        glVertex2f(cos(angle)*radius+tx,sin(angle)*radius+ty);
    }
    glEnd();
}

void drawFace(void) {
    glClear(GL_COLOR_BUFFER_BIT);  
    //draw 3 circles
    drawCircle(100,150,150,BIG);
    drawCircle(15,100,180,COLOR);
    drawCircle(5,100,180,EYES);
    drawCircle(15,200,180,COLOR);
    drawCircle(5,200,180,EYES);
    
//    drawCircle(15,100,180,255,245,185);
//    drawCircle(15,200,180,255,245,185);
    glColor3ub(COLOR);    
    //draw triangle
    glBegin(GL_POLYGON);

    glVertex2i(135,135);
    glVertex2i(165,135);
    glVertex2i(150,165);

    glEnd();
    
    //draw semi-circle
    glColor3ub(COLOR);    
    glBegin(GL_POLYGON);
    int radius=30,tx=150,ty=110;
    for(int i=180;i<=360;++i)
    {
        double angle = (2*M_PI*i)/360;
        glVertex2f(cos(angle)*radius+tx,sin(angle)*radius+ty);
    }
    glEnd();
    
    // draw 2 ears - rectangles
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

    glFlush();
} 

int main(int argc, char**argv) {
    glutInit(&argc, argv);  
    glutInitWindowPosition(10,10); 
    glutInitWindowSize(500,500); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    glutCreateWindow("Example"); 
    init(); 
    glutDisplayFunc(drawFace); 
    glutMainLoop();
}
