#version 330 core

in vec2 texCoord;
smooth in vec3 vNormal;
smooth in vec3 vWorldPos;

out vec4 outputColor;

uniform sampler2D gSampler;

struct PointLight
{
	vec3 vColor; // Color of that point light
	vec3 vPosition;
	
	float fAmbient;

	float fConstantAtt;
	float fLinearAtt;
	float fExpAtt;
};

struct Material 
{ 
   float fSpecularIntensity; 
   float fSpecularPower; 
};

vec4 getPointLightColor(const PointLight ptLight, vec3 vWorldPos, vec3 vNormal)
{
	vec3 vPosToLight = vWorldPos-ptLight.vPosition;
	float fDist = length(vPosToLight);
	vPosToLight = normalize(vPosToLight);
	
	float fDiffuse = max(0.0, dot(vNormal, -vPosToLight));

	float fAttTotal = ptLight.fConstantAtt + ptLight.fLinearAtt*fDist + ptLight.fExpAtt*fDist*fDist;

	return vec4(ptLight.vColor*(ptLight.fAmbient+fDiffuse)/fAttTotal, 1.0);
}

vec4 GetSpecularColor(vec3 vWorldPos, vec3 vEyePos, Material mat, PointLight lamp, vec3 vNormal) 
{ 
   vec4 vResult = vec4(0.0, 0.0, 0.0, 0.0); 
    
   vec3 vReflectedVector = normalize(reflect(lamp.vPosition - vWorldPos, vNormal)); 
   vec3 vVertexToEyeVector = normalize(vEyePos-vWorldPos); 
   float fSpecularFactor = dot(vVertexToEyeVector, vReflectedVector); 
    
   if (fSpecularFactor > 0) 
   { 
      fSpecularFactor = pow(fSpecularFactor, mat.fSpecularPower); 
      vResult = vec4(lamp.vColor, 1.0) * mat.fSpecularIntensity * fSpecularFactor; 
   } 
    
   return vResult; 
}

uniform PointLight lamp[4];
uniform Material material;
uniform vec3 vEyePosition;
uniform int isTexture;

void main()
{
	vec4 color = vec4(0.0, 0.0, 0.0, 0.0);
	if (isTexture == 1)
		color = texture2D(gSampler, texCoord); 
	float fDiffuseIntensity = max(0.0, dot(normalize(vNormal), -vec3(0.2, -1.0, 0.1)));

	vec4 vPtLightColor = vec4(0.0, 0.0, 0.0, 1.0);
	for (int i=0; i<4; ++i)
	{
		vPtLightColor += getPointLightColor(lamp[i], vWorldPos, normalize(vNormal));
		vPtLightColor += GetSpecularColor(vWorldPos, vEyePosition, material, lamp[i], normalize(vNormal));
	}
	outputColor = color*vPtLightColor;
}