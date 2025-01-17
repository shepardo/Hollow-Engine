#pragma once 

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferUsage.h>
#include <Runtime/Graphics/Memory/GraphicsMemory.h>
#include <Runtime/Graphics/Core/ShareMode.h>

namespace Hollow
{
	/**
	 * @struct GraphicsBufferDesc
	 * @brief Describes a graphics buffer.
	 */
	struct RUNTIME_API GraphicsBufferDesc
	{
		u64 SubSizeInBytes;
		u64 SubResourceCount;
		GraphicsBufferUsage Usage;
		ShareMode ShareMode;
		SharedPtr<GraphicsMemory> pMemory;
	};
}