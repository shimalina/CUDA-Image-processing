__global__ void grayscale(float4* imagem, int width, int height)
{
	const int i = blockIdx.x * (blockDim.x * blockDim.y) + blockDim.x * threadIdx.y + threadIdx.x;

	if(i < width * height)
	{
		float v = 0.3 * imagem[i].x + 0.6 * imagem[i].y + 0.1 * imagem[i].z;
		imagem[i] = make_float4(v, v, v, 0);
	}
}


extern "C" void cuda_grayscale(float* imagem, int width, int height, dim3 blocks, dim3 block_size)
{
	grayscale <<< blocks, block_size >>> ((float4*)imagem, width, height);
}

