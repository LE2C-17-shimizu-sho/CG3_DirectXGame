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
   
[maxvertexcount(6)]
void main(
	triangle VSOutput input[3] : SV_POSITION,
	inout TriangleStream<GSOutput> output
)
{
    // 1つ目の三角形
    for (uint i = 0; i < 3; i++)
    {
        GSOutput element; // 出力用頂点データ
         // 線分の終点
        element.svpos = input[i].svpos; // 頂点座標をコピー
        element.normal = input[i].normal; // 法線をコピー
        element.uv = input[i].uv * 2.0f; // uvをコピー
        // 頂点を1つ出力(出力リストに追加)
        output.Append(element);
    }
    // 現在のストリップを終了
    output.RestartStrip();
    
    // 2つ目の三角形
    for (uint i = 0; i < 3; i++)
    {
        GSOutput element; // 出力用頂点データ
        element.svpos = input[i].svpos + float4(20.0f,0.0f,0.0f,0.0f); // 頂点座標をコピー
        element.normal = input[i].normal; // 法線をコピー
        element.uv = input[i].uv * 5.0f; // uvをコピー
        output.Append(element);
    }
}

