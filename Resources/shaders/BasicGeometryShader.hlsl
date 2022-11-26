#include "BasicShaderHeader.hlsli"

[maxvertexcount(3)]
void main(
	point VSOutput input[1] : SV_POSITION,
	inout TriangleStream<GSOutput> output
)
{
    GSOutput element; // �o�͗p���_�f�[�^
    // ����
    element.normal = input[0].normal; // �@�����R�s�[
    element.uv = input[0].uv * 2.0f; // uv���R�s�[
    // 1�_��
    element.svpos = input[0].pos; // ���_���W���R�s�[
    output.Append(element);
    // 2�_��
    element.svpos = input[0].pos + float4(10.0f, 10.0f, 0, 0); // ���_���W���R�s�[
    output.Append(element);
    // 3�_��
    element.svpos = input[0].pos + float4(10.0f, 0, 0, 0); // ���_���W���R�s�[
    output.Append(element);
}

