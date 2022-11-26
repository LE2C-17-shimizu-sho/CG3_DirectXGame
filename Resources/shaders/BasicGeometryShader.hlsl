#include "BasicShaderHeader.hlsli"

//[maxvertexcount(3)]
//void main(
//	triangle VSOutput input[3] : SV_POSITION,
//	inout TriangleStream<GSOutput> output
//)
//{
//    for (uint i = 0; i < 3; i++)
//    {
//        GSOutput element;
//        element.svpos = input[i].svpos;
//        element.normal = input[i].normal;
//        element.uv = input[i].uv;
//        output.Append(element);
//    }
//}
   
[maxvertexcount(3)]
void main(
	point VSOutput input[1] : SV_POSITION,
	inout TriangleStream<GSOutput> output
)
{
    GSOutput element; // 出力用頂点データ
    // 共通
    element.normal = input[0].normal; // 法線をコピー
    element.uv = input[0].uv * 2.0f; // uvをコピー
    // 1点目
    element.svpos = input[0].svpos; // 頂点座標をコピー
    output.Append(element);
    // 2点目
    element.svpos = input[0].svpos + float4(10.0f,10.0f,0,0); // 頂点座標をコピー
    output.Append(element);
    // 3点目
    element.svpos = input[0].svpos + float4(10.0f, 0, 0, 0); // 頂点座標をコピー
    output.Append(element);
}

