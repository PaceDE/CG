#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include <math.h>
#include<stdio.h>

void fillPyramid(){
	glBegin(GL_TRIANGLE_FAN); 
	glColor3f(1, 1, 0.0f);  
    glVertex2f(0.0f, 0.0f); 
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(-0.1f, -0.5f);
    glColor3f(0, 1, 0.0f);  
    glVertex2f(0.1f, -0.5f);
    glColor3f(1, 0, 0.0f); 
    glVertex2f(0.1f, -0.3f); 
	glEnd();
	
}
void drawPyramid()
{

	glLineWidth(5); // Set the point size
	glBegin(GL_LINES); //Begin drawing points
	glColor3f(0,0,0); // Set point color
 	glVertex2f(0.0f, 0.0f); 
    glVertex2f(-0.1f, -0.3f);
	glVertex2f(0.0f, 0.0f); 
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.0f, 0.0f); 
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.0f, 0.0f); 
    glVertex2f(0.1f, -0.3f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, -0.3f);
    glEnd();
}


int main(){
	glfwInit(); //Initialize GLFW
	 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow( 1000, 1000, "Name: Dipesh Shrestha , Lab no : 9(g) , Roll no: 08", NULL, NULL );
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
		fillPyramid();
		drawPyramid();
	
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

