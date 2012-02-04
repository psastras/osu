precision mediump float;
uniform mat4 modelviewMatrix;
uniform mat4 projMatrix;

#ifdef _VERTEX_
attribute vec3 in_Position;
attribute vec3 in_TexCoord;
varying vec3 pass_TexCoord;
void main(void) {
	pass_TexCoord = in_TexCoord;
	gl_Position = projMatrix * modelviewMatrix * vec4(in_Position,1.0);
}
#endif

#ifdef _FRAGMENT_
varying vec3 pass_TexCoord;
void main() {
	float r = ((0.5 - pass_TexCoord.s)*(0.5 - pass_TexCoord.s)+
				(0.5 - pass_TexCoord.t)*(0.5 - pass_TexCoord.t));
   gl_FragColor =  vec4(1.0-r*r);
}
#endif
