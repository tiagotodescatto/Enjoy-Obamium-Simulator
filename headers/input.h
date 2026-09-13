#pragma once

#include <GLFW/glfw3.h>
#include "Camera.h"

class Input {
public:
    Input(GLFWwindow* window);
    void windowInput(GLFWwindow* window, Camera& camera, float deltaTime);
};