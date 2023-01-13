// #ifdef GL_ES
// // Set default precision to medium
// precision mediump int;
// precision mediump float;
// #endif

//varying highp vec3 vert;
//varying highp vec3 vertNormal;
//uniform highp vec3 lightPos;
//varying float forColor;
//uniform vec3 ColorLine;
//uniform int colorFlag;
//void main() {
//   highp vec3 L = normalize(lightPos - vert);
//   highp float NL = max(dot(normalize(vertNormal), L), 0.0);
//   highp vec3 color = ColorLine * forColor;
//   if (colorFlag == 1) {
//       highp vec3 col;
//       col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);
//       gl_FragColor = vec4(col, 1.0);
//   } else {
//       gl_FragColor = vec4(color, 1.0);
//   }
//}


varying highp vec3 vert;
varying highp vec3 vertNormal;
uniform highp vec3 lightPos;
varying float forColor;
uniform vec3 ColorLine;
uniform vec3 ColorVertex;
uniform vec3 ColorFacets;
uniform vec3 ColorLight;
uniform int colorFlag;
void main() {
   highp vec3 L = normalize(lightPos - vert);
   highp float NL = max(dot(normalize(vertNormal), L), 0.0);
   highp vec3 colorL = ColorLine * forColor;
   highp vec3 colorV = ColorVertex * forColor;
   if (colorFlag == 1) {
       gl_FragColor = vec4(colorV, 1.0);
   } else if (colorFlag == 2) {
       gl_FragColor = vec4(colorL, 1.0);
   } else if (colorFlag == 3) {
       highp vec3 col;
       highp vec3 colN = ColorFacets * 0.2 + ColorFacets * 0.8 * NL;
       highp vec3 colNCL;
       colNCL = colN * ColorLight;
       col = clamp(colNCL, 0.0, 1.0);
       gl_FragColor = vec4(col, 1.0);
   }
}
