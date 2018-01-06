//========================================================================
// Copyright (c) Yann Clotioloman Yeo, 2017
//
//	Author					: Yann Clotioloman Yeo
//	E-Mail					: orionrenderer@gmail.com
//========================================================================

#pragma once

#include "Graphics/Texture/CubeMap.h"
#include <vector>

#define TGRAPHIC_ALLOC_PARAMETER_LIST typename TextureHandle,\
									  typename VertexBufferHandle,\
									  typename IndexBufferHandle

#define TGRAPHIC_ALLOC_PARAMETERS TextureHandle,  \
								  VertexBufferHandle, \
								  IndexBufferHandle

namespace Graphics { namespace Renderer { namespace Realtime
{
template <TGRAPHIC_ALLOC_PARAMETER_LIST>
class TGraphicResourceAllocator
{
public:
	virtual bool createRGBATexture2D(const Texture::RGBAImage* image, TextureHandle& dst) = 0;
	virtual bool createRGBATexture2DArray(const std::vector<const Texture::RGBAImage*>& images, TextureHandle& dst) = 0;
	virtual bool releaseTexture(const TextureHandle& textureHandle) const = 0;

	virtual bool createVertexBuffer(const std::vector<Model::Vertex>& data, VertexBufferHandle& dst) = 0;
	virtual bool createVertexBuffer(const std::vector<Graphics::Texture::CubeMap::Vertex>& data, VertexBufferHandle& dst) = 0;
	virtual bool releaseVertexBuffer(const VertexBufferHandle& arrayBufferHandle) const = 0;

	virtual bool createIndexBuffer(const std::vector<uint32_t>& data, IndexBufferHandle& dst) = 0;
	virtual bool releaseIndexBuffer(const IndexBufferHandle& arrayBufferHandle) const = 0;
};
}}}