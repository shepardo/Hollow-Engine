#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Queue/GraphicsQueue.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Hollow
{
	class RUNTIME_API VulkanQueue final : public GraphicsQueue
	{
	public:
		VulkanQueue(const GraphicsQueueDesc& desc, VkQueue reservedQueue, SharedPtr<VulkanDevice> pDevice);
		~VulkanQueue() override;

		VkQueue GetVkQueue() const { return mVkQueue; }
		u32 GetQueueFamilyIndex() const { return mQueueFamilyIndex; }

	private:
		VkQueue mVkQueue;
		u32 mQueueFamilyIndex;
	};
}