#include "BasicShaderHeader.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD)
{
	VSOutput output; // ピクセルシェーダーに渡す値
    output.pos = mul(mat, pos);
    output.normal = normal;
    output.uv = uv;
	return output;
}