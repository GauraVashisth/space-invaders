#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>

void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, char *argv[]) {

  if (!glfwInit())
    return -1;

  GLFWwindow *window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

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
  glClearColor(1.0, 0.0, 0.0, 1.0);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // cleanup and close
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
