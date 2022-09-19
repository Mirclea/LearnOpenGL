#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
int main()
{
	glfwInit();
	// 设置主要版本和次要版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  MAC OS 系统要使用改行命令完成兼容操作

	//创建窗口
	GLFWwindow* window = glfwCreateWindow(800,600,"learnOpenGL",NULL,NULL);
	if(window == NULL){
		std::cout<<"open wrong!"<<std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// 初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
    	return -1;
	}
	// 设置视口
	glViewport(0,0,800,600);

	glfwSetWindowSizeCallback(window,framebuffer_size_callback);

	
	while (!glfwWindowShouldClose(window))
	{
		processInput(window); // 渲染按键信息

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate(); //最后回收资源
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window){
	if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window,true);
	}
}