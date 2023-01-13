// #ifdef GL_ES
// // Set default precision to medium
// precision mediump int;
// precision mediump float;
// #endif

//attribute vec4 vertex;
//attribute vec3 normal;
//varying vec3 vert;
//varying vec3 vertNormal;
//varying float forColor;
//uniform mat4 projMatrix;
//uniform mat4 mvMatrix;
//uniform float vertexSize;
//uniform mat3 normalMatrix;
//void main() {
//   vert = vertex.xyz;
//   vertNormal = normalMatrix * normal;
//   gl_Position = projMatrix * mvMatrix * vertex;
//   gl_PointSize = vertexSize;
//   forColor = clamp((1.3 - (1.0 + gl_Position.z)/3.0) * 1.2, 0.0, 1.0);
//}

attribute vec4 vertex;
attribute vec3 normal;
varying vec3 vert;
varying vec3 vertNormal;
varying float forColor;
uniform mat4 projMatrix;
uniform mat4 mvMatrix;
uniform float vertexSize;
uniform mat3 normalMatrix;
void main() {
   vert = vertex.xyz;
   vertNormal = normalMatrix * normal;
   gl_Position = projMatrix * mvMatrix * vertex;
   gl_PointSize = vertexSize;
   forColor = clamp((1.3 - (1.0 + gl_Position.z)/3.0) * 1.2, 0.0, 1.0);
};
