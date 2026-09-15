#version 460 core

in vec3 LocalPos;
out vec4 FragColor;

uniform samplerCube environmentMap;

void main()
{
    // O cubemap usa a própria posição 3D local do vértice como vetor de direção
    vec3 envColor = texture(environmentMap, LocalPos).rgb;
    
    FragColor = vec4(envColor, 1.0);
}