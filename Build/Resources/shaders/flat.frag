#version 430 core
	flat in vec3 fs_color;
    in vec2 fs_textcord;

    out vec4 outColor;

    uniform sampler2D textureSampler;

    void main()
    {
        outColor = texture(textureSampler, fs_textcord) *vec4(fs_color,1);
    }