#pragma once
#if BUILD_DIRECTX

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include "Renderer.h"

typedef struct UniformBuffer {
	DirectX::XMFLOAT4X4 MVM;
	DirectX::XMFLOAT4 Colour;
} UniformBuffer;

// DirectX Device & Context
class Renderer_DX :
		public Renderer {
protected:
	IDXGISwapChain* _swapchain; // the pointer to the swap chain interface
	ID3D11Device* _device; // the pointer to our Direct3D device interface
	ID3D11DeviceContext* _context; // the pointer to our Direct3D device context
	ID3D11RenderTargetView* _backbuffer; // the pointer to our back buffer
	ID3D11DepthStencilView* _depthStencil;
	ID3D11InputLayout* _layout; // the pointer to the input layout
	ID3D11VertexShader* _vertexShader; // the pointer to the vertex shader
	ID3D11PixelShader* _pixelShader; // the pointer to the pixel shader
	ID3D11Buffer* _uniformBuffer; // Stores the MVM and colour

	HWND _hWnd; // Window handle

public:
	Renderer_DX(HWND hWnd);

	virtual ~Renderer_DX();

	ID3D11Device* GetDevice() const { return _device; }

	void SetDevice(ID3D11Device* v) { _device = v; }

	ID3D11DeviceContext* GetContext() const { return _context; }

	void SetContext(ID3D11DeviceContext* v) { _context = v; }

	void ClearScreen() override;

	void Destroy() override;

	void Draw(const Mesh* mesh, glm::mat4 MVM, const Colour& colour) override;

	void Initialise(int width, int height) override;

	void SwapBuffers() override;

	// Initialise the shaders
	void InitialiseShaders();

};

#endif
