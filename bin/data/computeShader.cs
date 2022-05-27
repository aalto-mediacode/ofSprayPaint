#version 440


layout(rgba8, binding = 0) uniform sampler2D src;
layout(rgba8, binding = 1) uniform writeonly image2D dst;
layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform vec3 iResolution;
uniform sampler2D texSam;

void main()
{
    vec4 dripsTex = imageLoad(src, ivec2(gl_GlobalInvocationID.xy));

    vec3 refractiveIndex = vec3(1.0, 1.015, 1.03);
    vec2 uv = dripsTex.xy / iResolution.xy;
    vec2 normalizedTexCoord = vec2(2.0, 2.0) * uv - vec2(1.0, 1.0);    // [0, 1] -> [-1, 1]
    vec3 texVec = vec3(normalizedTexCoord, 1.0);
    vec3 normalVec = vec3(0.0, 0.0, -1.0);
    vec3 redRefractionVec = refract(texVec, normalVec, refractiveIndex.r);
    vec3 greenRefractionVec = refract(texVec, normalVec, refractiveIndex.g);
    vec3 blueRefractionVec = refract(texVec, normalVec, refractiveIndex.b);
    vec2 redTexCoord = ((redRefractionVec / redRefractionVec.z).xy + vec2(1.0, 1.0)) / vec2(2.0, 2.0);
    vec2 greenTexCoord = ((greenRefractionVec / greenRefractionVec.z).xy + vec2(1.0, 1.0)) / vec2(2.0, 2.0);
    vec2 blueTexCoord = ((blueRefractionVec / blueRefractionVec.z).xy + vec2(1.0, 1.0)) / vec2(2.0, 2.0);

    float tempR = texture(texSam, redTexCoord).r;
    float tempG = texture(texSam, greenTexCoord).g;
    float tempB = texture(texSam, blueTexCoord).b;

    vec4 chroma;

    chroma.r = tempR;
    chroma.g = tempG;
    chroma.b = tempB;
    chroma.a = 1.0;

    imageStore(dst, ivec2(gl_GlobalInvocationID.xy), chroma);
}