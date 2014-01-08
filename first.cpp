#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>
// One-time initializtion logic
void init( void )
{
    printf( "OpenGL version: %s\n", (char*)glGetString(GL_VERSION));
    printf( "OpenGL renderer: %s\n", (char*)glGetString(GL_RENDERER));
 
    //Configure basic OpenGL settings
    glClearColor(0.0, 0.0, 0.0, 0.0);
}
 
// Main drawing routine. Called repeatedly by GLUT's main loop
void display( void )
{
    //Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);
  
	glBegin(GL_LINES); // glBegin can take different values
	
	//TODO: Perform drawing here
	
	glEnd();

   	//We just drew to the back buffer. Now we need to swap that with the
   	//front buffer to show it on screen.
    glutSwapBuffers();
}
 
// Entry point - GLUT setup and initialization
int main( int argc, char** argv )
{
 
   glutInit( &argc, argv );
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow( "OpenGL Test" );
   glutDisplayFunc( display );
 
   init();
 
   glutMainLoop();
 
   return 0;
}

