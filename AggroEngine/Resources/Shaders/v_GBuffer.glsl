#version 430

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
in vec3 v_vertex;
in vec2 v_texture;
in vec3 v_normal;
out vec3 normal;
out vec2 texCoord;

void main() {
	gl_Position = modelViewProjectionMatrix * vec4(v_vertex,1.0);
	texCoord = vec2(v_texture);
	normal = normalMatrix * normalize(v_normal);
}