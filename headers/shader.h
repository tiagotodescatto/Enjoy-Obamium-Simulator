#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragPath);

    void use();
    void setInt(const std::string& name, int value);
    void setMat4(const std::string& name, const glm::mat4& value);
    void setVec3(const std::string& name, const glm::vec3& value);
};