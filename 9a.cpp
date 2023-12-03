/*#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include<stdio.h>

void drawPoint(){
	glPointSize(10); // Set the point size
	glBegin(GL_POLYGON); //Begin drawing points
/*	glColor3f(1,1,1); // Set point color
	glVertex2f(0.0f,-0.2f);
	glColor3f(0.0,1,1); 
	glVertex2f(-0.2f,0.2f);
	glColor3f(1,1,0.0); 
	glVertex2f(0.2f,0.2f);*/
/*	glPolygonMode(1.0f,-1.0f);
		glVertex3f(-0.5f,0.8f,0.0f);
				glVertex3f(-0.1f,0.0f,0.0f);
				glVertex3f(-0.5f,0.8f,0.0f);
				glVertex3f(0.5f,0.8f,0.0f);
				glVertex3f(-0.1f,0.0f,0.0f);
								glVertex3f(0.5f,0.8,0.0f);
	glEnd();
}


int main(){
	glfwInit(); //Initialize GLFW
	 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow( 1800, 800, "Name: Dipesh Shrestha , Lab no : 9(a) , Roll no: 08", NULL, NULL );
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
}*/
#include <GLFW/glfw3.h>
void drawPolygon(){
// Set the clear color
 glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 //Specify the vertices of the triangle
float vertices[] = {
 0.3f, 0.0f, // Vertex1 (x, y)
 0.3f, 0.5f, // Vertex2 (x, y)
 0.0f, 0.0f // Vertex3 (x, y)
};
// Draw the polygon (triangle in this example)
glColor3f(0.0f,0.0f,1.0f);

// Set the line width for wireframe rendering
 glLineWidth(2.0f);
 // Enable line drawing mode
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_POLYGON);
glVertex2f(vertices[0], vertices[1]); // Vertex 1
glVertex2f(vertices[2], vertices[3]); // Vertex 2
glVertex2f(vertices[4], vertices[5]); // Vertex 3
glEnd();
 }
int main() {
 // Initialize GLFW
 if (!glfwInit()) {
 return -1;
 }
 // Create a window
 GLFWwindow* window = glfwCreateWindow(400, 300, "Draw Poly", NULL, 
NULL);
 if (!window) {
 glfwTerminate();
 return -1;
 }
 // Make the window current
 glfwMakeContextCurrent(window);
 while (!glfwWindowShouldClose(window)) {
 /*int width, height;
 glfwGetFramebufferSize(window, &width, &height);
 glViewport(0, 0, width, height);*/
 // Draw a polygon
 drawPolygon();
 // Swap buffers
 glfwSwapBuffers(window);

 // Poll events
 glfwPollEvents();
 }
 // Terminate GLFW
 glfwTerminate();
 return 0;
}

