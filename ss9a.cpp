#include<stdio.h>
#include<conio.h>
#include<gl/GL.h>
#include<GLFW/glfw3.h>
void render_loop()
{
	glPointSize(10);
	glLineWidth(2.5); 
	glColor4f(1.0, 0.0, 0.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(0.4f,200);
	glVertex2f(1000,600);	
	glEnd();
}
int main(int argc, char *argv[])
{
	glfwInit(); //Initialize GLFW
	 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
		GLFWwindow* window = glfwCreateWindow( 1800, 800, "LearnOpenGL", NULL, NULL );
	if (!window)
	{
		printf("Failed to open GLFW window\n" );
		glfwTerminate();
		exit( EXIT_FAILURE );
	}


	glfwMakeContextCurrent(window);


	// Main loop
	while( !glfwWindowShouldClose(window) )
	{
			glClearColor ( 0.14f, 0.10f, 0.08f, 1.0f ); // Specify color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear back buffer and assign new color
		// Draw gears
		render_loop();

		// Swap buffers
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Terminate GLFW
	glfwTerminate();
	
}
