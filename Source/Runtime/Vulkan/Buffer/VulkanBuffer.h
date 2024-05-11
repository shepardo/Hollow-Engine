#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

#include <vulkan.h>

namespace Hollow
{
	class RUNTIME_API VulkanBuffer : public GraphicsBuffer
	{
	public:
		VulkanBuffer(const GraphicsBufferDesc& desc,const SharedPtr<VulkanDevice> pDevice);
		~VulkanBuffer() override = default;

		VkBuffer GetVkBuffer() const { return mVkBuffer; }
		VkDevice GetVkDevice() const { return mVkDevice; }

		uint64 GetVkOffset() const { return mOffset; }
		uint64 GetVkAlignedOffset() const { return mAlignedOffset; }

		void OnShutdown() noexcept override;

	private:
		VkBuffer mVkBuffer;
		VkDevice mVkDevice;

		uint64 mOffset;
		uint64 mAlignedOffset;
	};
}