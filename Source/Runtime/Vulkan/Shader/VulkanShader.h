#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Shader/Shader.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

#include <vulkan/vulkan.h>

namespace Hollow
{
	class RUNTIME_API VulkanShader final : public Shader
	{
	public:
		VulkanShader(const ShaderDesc& desc, SharedPtr<VulkanDevice> device);
		~VulkanShader() override;

		VkShaderModule GetVkShaderModule() const { return mVkShaderModule; }

	private:
		VkShaderModule mVkShaderModule;
		VkDevice mVkDevice;
	};
}
