#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include <math.h>
#include<stdio.h>

void drawPoint(){
	GLfloat radius= 0.5f,angle;
	glBegin(GL_TRIANGLE_FAN); 
	glColor3f(1.0f, 1.0f, 0.0f);  
    glVertex3f(0.0f, 0.0f,0.0f);
    int Segments = 100;
    for (int i = 0; i <= Segments; i++) { 
        angle = i * 2.0f * M_PI /Segments;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
	glEnd();
}


int main(){
	glfwInit(); //Initialize GLFW
	 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow( 1000, 1000, "Name: Dipesh Shrestha , Lab no : 9(e) , Roll no: 08", NULL, NULL );
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
