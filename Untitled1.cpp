#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <gl/GL.h>


void render_loop()
{
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10);
	glLineWidth(2.5); 
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(100.0,100.0,0.0);
	glVertex3f(1500.0,1500.0,0.0);
	
	glEnd();
}

/* program entry */
int main(int argc, char *argv[])
{
	GLFWwindow* window;

	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		exit( EXIT_FAILURE );
	}

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow( 1800, 800, "LearnOpenGL", NULL, NULL );
	if (!window)
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		exit( EXIT_FAILURE );
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );

	// set up view
	glViewport( 0, 0, 400, 400 );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
	glOrtho(0.0,400.0,0.0,400.0,0.0,1.0); // this creates a canvas you can do 2D drawing on


	// Main loop
	while( !glfwWindowShouldClose(window) )
	{
		// Draw gears
		render_loop();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Terminate GLFW
	glfwTerminate();

	// Exit program
	exit( EXIT_SUCCESS );
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3); // Tell GLFW what version of OpenGl we are suing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3); // In this Case 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE); // Tell we are using CORE profile (modern functions)*/
	
}
