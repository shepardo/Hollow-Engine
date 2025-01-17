#pragma once

#include <Runtime/Core/Core.h>

namespace Hollow
{
	class RUNTIME_API MemoryOwnedBuffer final
	{
	public:
		MemoryOwnedBuffer();
		MemoryOwnedBuffer(void* pData, const u64 size);
		MemoryOwnedBuffer(const MemoryOwnedBuffer& other);
		MemoryOwnedBuffer(MemoryOwnedBuffer&& other) noexcept;
		~MemoryOwnedBuffer();

		FORCEINLINE void* GetData() const { return mData; }
		FORCEINLINE u64 GetSize() const { return mSize; }

		MemoryOwnedBuffer& operator=(const MemoryOwnedBuffer& other);
		MemoryOwnedBuffer& operator=(MemoryOwnedBuffer&& other) noexcept;

	private:
		void AllocateAndCopy(const void* pData, const u64 size);
	private:
		void* mData;
		u64 mSize;
	};
}
