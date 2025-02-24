#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>

void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, char *argv[]) {
  // initialzing glfw library
  if (!glfwInit())
    return -1;

  // creates a window
  // specifies window title, and resolution
  GLFWwindow *window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  //make subsequent opengl calls
  glfwMakeContextCurrent(window);


  //initilaize glew, a loading library
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    fprintf(stderr, "Error initializing GLEW.\n");
    glfwTerminate();
    return -1;
  }

  int glVersion[2] = {-1, 1};
  glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
  glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

  printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);


  // game loop:
  // specifies window color, here red
  glClearColor(1.0, 0.0, 0.0, 1.0);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // cleanup and exit
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
