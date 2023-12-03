#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include <math.h>
#include<stdio.h>

void fillCube(){
	glBegin(GL_QUADS); 
	glColor3f(1, 1, 0.0f);  
    glVertex2f(-0.35f, 0.35f); 
    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.35f, -0.35f);
    glVertex2f(-0.35f, -0.35f);
    
	glColor3f(0, 1, 1.0f);
    glVertex2f(-0.6f, 0.6f); 
    glVertex2f(-0.35f, 0.35f); 
    glVertex2f(-0.35f, -0.35f);
    glVertex2f(-0.6f, -0.10); 
	
    glColor3f(0.5, 0.5, 0.5); 
    glVertex2f(-0.6f, 0.6f); 
    glVertex2f(0.10f, 0.6f);;
    glVertex2f(0.35f, 0.35f);
    glVertex2f(-0.35f, 0.35f);   
	glEnd();
	
}
void drawCube()
{

	glLineWidth(5); // Set the point size
	glBegin(GL_LINE_STRIP); //Begin drawing points
	glColor3f(0,0,0); // Set point color
  	glVertex2f(-0.35f, 0.35f); 
    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.35f, -0.35f);
    glVertex2f(-0.35f, -0.35f);
    glVertex2f(-0.35f, 0.35f); 
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, 0.6f); 
    glVertex2f(-0.35f, 0.35f); 
    glVertex2f(-0.35f, -0.35f);
    glVertex2f(-0.6f, -0.10); 
    glVertex2f(-0.6f, 0.6f); 
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, 0.6f); 
    glVertex2f(0.10f, 0.6f);;
    glVertex2f(0.35f, 0.35f);
    glVertex2f(-0.35f, 0.35f); 
    glVertex2f(-0.6f, 0.6f); 
    glEnd();
}

int main(){
	glfwInit(); //Initialize GLFW
	 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow( 1000, 1000, "Name: Dipesh Shrestha , Lab no : 9(h) , Roll no: 08", NULL, NULL );
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
		fillCube();
		drawCube();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

