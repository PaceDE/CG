#include <GLFW/glfw3.h>
#include<stdio.h>
#include <gl/gl.h>
#include<stdio.h>

void drawPoint(){
	glColor3f(1.0,1.0,0); // Set point color
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.4,0.0f);
	glVertex2f(0.4,0.0f);
	glVertex2f(0.0f,0.8f);
	glEnd();
}


int main(){
	glfwInit(); //Initialize GLFW
	 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow( 1800, 800, "Name: Dipesh Shrestha , Lab no : 9(c) , Roll no: 08", NULL, NULL );
	if (!window)
	{
		printf("Failed to open GLFW window\n" );
		glfwTerminate();
		return -1;
	}	
	glfwMakeContextCurrent(window);
	while(!glfwWindowShouldClose(window)){
		glClearColor(0.14f,0.10f,0.08f,0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		drawPoint();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
