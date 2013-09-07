varying vec3 position, normal;
uniform sampler2D normals;
uniform sampler2D specular;

void AllLights(in vec3 position, in vec3 normal, out vec4 ambient, out vec4 diffuse, out vec4 specular);
float SoftShadow();

void main() {
	vec2 uv = vec2(gl_TexCoord[0]);
	//vec3 n = normalize(vec3(2.0, 2.0, 1.0) * texture2D(normals, uv).xyz - vec3(1.0, 1.0, 0.0) + normalize(normal));
	vec3 n = normalize(normal);
	vec4 ambient, diffuse, spec;
    AllLights(position, n, ambient, diffuse, spec);

    ambient = gl_FrontLightModelProduct.sceneColor + ambient * gl_FrontMaterial.ambient;
   	diffuse = diffuse * gl_FrontMaterial.diffuse;
    spec = spec * gl_FrontMaterial.specular;
    //vec4 specProprieties = texture2D(specular, uv);
    //spec = pow(spec, specProprieties.a) * vec4(specProprieties.rgb, 1);

	gl_FragData[0] = diffuse * SoftShadow();
	gl_FragData[1] = gl_Color + ambient + spec;
}