CXX=g++
CUDA_INSTALL_PATH=/usr/local/cuda-8.0
CFLAGS= -I. -I$(CUDA_INSTALL_PATH)/include `pkg-config --cflags opencv`
LDFLAGS= -L$(CUDA_INSTALL_PATH)/lib64 -lcudart `pkg-config --libs opencv`

all:

	$(CXX) $(CFLAGS) -c main.cpp -o main.o
	nvcc $(CUDAFLAGS) -arch="sm_21" -c kernel_gpu.cu -o kernel_gpu.o
	$(CXX)  main.o `pkg-config --libs opencv` -L$(CUDA_INSTALL_PATH)/lib64 -lcudart kernel_gpu.o -o main
