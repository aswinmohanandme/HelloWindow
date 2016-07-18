/*
 	* Author :: Aswin MOhan
 	* Dated : 2 July 2016 

 	* @Description : Hello Window . I created this snippet to render an empty black window , and to exit when 
 	*  the user presses ESC key
 */

// OpenGl wrapper
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Input COntrol
void keyCallback(GLFWwindow *window , int key , int scancode , int action , int mode);

int main() {

    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE , GL_TRUE);

    // Initialise GLEw
    GLFWwindow *window = glfwCreateWindow(600 , 400 , "Learn OpenGL" , NULL , NULL);
    if (!window){
        std::cout << " Cannot Create a Window " << std::endl;
        glfwTerminate();

        return 0;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window , keyCallback);

    if (glewInit() != GLEW_OK){
        std::cout << " Glew Not working " << std::endl;
        glfwTerminate();

        return 0;
    }

    // Rendering ViewPort
    int width , height;
    glfwGetFramebufferSize(window , &width , &height);
    glViewport(0 , 0 ,width , height);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}

// Key Press
void keyCallback(GLFWwindow *window , int key , int scancode , int action , int mode){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window , GL_TRUE);
    }
}