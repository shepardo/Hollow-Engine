#pragma once

#include <Runtime/Core/Core.h>

namespace Hollow
{
	/**
	 * @struct BufferTextureCopyDesc
	 * @brief Mostly used for copying between host texture data and device buffers
	 */
	struct RUNTIME_API BufferTextureCopyDesc
	{
		u64 BufferOffsetInBytes;
		Vector3i TextureOffset;
		Vector3u TextureSize;
		byte TargetArrayIndex;
		byte TargetMipIndex;
	};
}