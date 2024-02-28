#include "Object3d.hlsli"

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
	
};

Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    const float32_t u = 1.0f / 1280.0f;
    const float32_t v = 1.0f / 720.0f;
    const float32_t radius = 2.0f;
    const int kernelSize = 2 * radius + 1;
    const float32_t sigma = radius / 1.8f; // ガウシアン分布の標準偏差

    float32_t4 color = { 0, 0, 0, 0 };
    float32_t totalWeight = 0.0f;

    // ガウシアンカーネルを生成
    float32_t gaussianKernel[5][5];
    for (float32_t i = -radius; i <= radius; ++i)
    {
        for (float32_t j = -radius; j <= radius; ++j)
        {
            float32_t weight = exp(-(i * i + j * j) / (2.0f * sigma * sigma)); // ガウシアン分布の重み
            gaussianKernel[i + radius][j + radius] = weight;
            totalWeight += weight;
        }
    }

    // カーネルの正規化
    for (float32_t k = 0; k < kernelSize; ++k)
    {
        for (float32_t m = 0; m < kernelSize; ++m)
        {
            gaussianKernel[k][m] /= totalWeight;
        }
    }

    for (float32_t x = -radius; x <= radius; ++x)
    {
        for (float32_t y = -radius; y <= radius; ++y)
        {
            float32_t offsetX = x * u;
            float32_t offsetY = y * v;

            // ガウシアンカーネルの重みを適用してテクスチャをサンプリング
            float32_t weight = gaussianKernel[x + radius][y + radius];
            input.texcoord.x = input.texcoord.x + offsetX;
            input.texcoord.y = input.texcoord.y + offsetY;
            float32_t4 sampledColor = gTexture.Sample(gSampler, input.texcoord);
            color += sampledColor * weight;
        }
    }

    output.color = color;
    return output;
};