#version 460 core

in vec3 Normal;
in vec2 TexCoords;

out vec4 fragColor;

uniform sampler2D texture_diffuse1;
uniform vec3 lightDir;

void main()
{
    vec3 norm = normalize(Normal);
    float diffuseLight = max(dot(norm, lightDir), 0.0);
    float ambient = 0.2;

    vec3 texColor = texture(texture_diffuse1, TexCoords).rgb;
    fragColor = vec4(texColor * (diffuseLight + ambient), 1.0);
}