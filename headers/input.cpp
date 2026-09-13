#include "Input.h"

Input::Input(GLFWwindow* window) {}

void Input::windowInput(GLFWwindow* window, Camera& camera, float deltaTime)
{
    float speed = 2.5f * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) speed = 3.0f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) speed = 5.0f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)) speed = 3.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) speed = 1.0f * deltaTime;

    // Direção "achatada": remove o componente Y, pra olhar pra cima/baixo não mover verticalmente
    glm::vec3 frontXZ = glm::vec3(camera.Front.x, 0.0f, camera.Front.z);
    if (glm::length(frontXZ) > 0.0001f)
        frontXZ = glm::normalize(frontXZ);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera.Move(frontXZ, speed);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera.Move(-frontXZ, speed);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera.Move(-camera.Right, speed);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera.Move(camera.Right, speed);
}