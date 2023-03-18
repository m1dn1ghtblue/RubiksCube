#version 330 core

in vec4 vertexColor;
in vec2 textureCoord;
out vec4 fragmentColor;
uniform sampler2D uTexture;

void main()
{
    if (texture(uTexture, textureCoord) == vec4(0.0, 0.0, 0.0, 1.0)) {
        fragmentColor = vec4(0.0, 0.0, 0.0, 1.0);
    }
    else {
        fragmentColor = vertexColor;
    }
}