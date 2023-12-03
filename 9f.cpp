#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cmath>

#define PI 3.14159265f

void drawSphere(float radius, int slices, int stacks) {
    for (int i = 0; i < slices; i++) {
        float theta1 = i * 2.0f * PI / slices;
        float theta2 = (i + 1) * 2.0f * PI / slices;

        for (int j = 0; j < stacks; j++) {
            float phi1 = j * PI / stacks;
            float phi2 = (j + 1) * PI / stacks;

            glBegin(GL_TRIANGLES);
            glColor3f(0.0f,0.5f,0.0f);
            
            glVertex3f(
                radius * sin(phi1) * cos(theta1),
                radius * sin(phi1) * sin(theta1),
                radius * cos(phi1)
            );
            glColor3f(0.5f,0.5f,0.0f);                      
                glVertex3f(
                radius * sin(phi2) * cos(theta1),
                radius * sin(phi2) * sin(theta1),
                radius * cos(phi2)
            );
            glColor3f(0.5f,0.0f,0.0f);
            glVertex3f(
                radius * sin(phi1) * cos(theta2),
                radius * sin(phi1) * sin(theta2),
                radius * cos(phi1)
            );
            glColor3f(0.5f,1.0f,0.0f);
            glVertex3f(
                radius * sin(phi1) * cos(theta2),
                radius * sin(phi1) * sin(theta2),
                radius * cos(phi1)
            );
            glColor3f(0.0f,0.0f,0.5f);
            glVertex3f(
                radius * sin(phi2) * cos(theta1),
                radius * sin(phi2) * sin(theta1),
                radius * cos(phi2)
            );
            glColor3f(0.5f,0.0f,0.5f);
            glVertex3f(
                radius * sin(phi2) * cos(theta2),
                radius * sin(phi2) * sin(theta2),
                radius * cos(phi2)
            );

            glEnd();
        }
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Name: Dipesh Shrestha , Lab no: 9(f) , Roll no: 08 ", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
       
//        glTranslatef(0.0f, 0.0f, -5.0f);
         glRotatef(glfwGetTime()* 50.0f, 0.0f, 1.0f, 0.0f);

        drawSphere(1.0f, 50, 50);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

