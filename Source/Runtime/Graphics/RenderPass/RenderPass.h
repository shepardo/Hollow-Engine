#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/RenderPass/RenderPassDesc.h>

namespace Hollow
{
	class DEPRECATED_CLASS RUNTIME_API RenderPass : public GraphicsDeviceObject
	{
	public:
		RenderPass(const RenderPassDesc& desc, SharedPtr<GraphicsDevice> device);
		virtual ~RenderPass() override = default;

		FORCEINLINE const DArray<PassAttachmentDesc>& GetColorAttachments() const noexcept { return mColorAttachments; }
		FORCEINLINE const PassAttachmentDesc& GetColorAttachment(u32 index) const noexcept { return mColorAttachments[index]; }
		FORCEINLINE const DArray<PassAttachmentDesc>& GetInputAttachments() const noexcept { return mInputAttachments; }
		FORCEINLINE const PassAttachmentDesc& GetInputAttachment(u32 index) const noexcept { return mInputAttachments[index]; }
		FORCEINLINE const PassAttachmentDesc& GetDepthStencilAttachment() const noexcept { return mDepthStencilAttachment; }

		FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept { return GraphicsDeviceObjectType::RenderPass; }

	private:
		DArray<PassAttachmentDesc> mColorAttachments;
		DArray<PassAttachmentDesc> mInputAttachments;
		PassAttachmentDesc mResolveAttachment;
		PassAttachmentDesc mDepthStencilAttachment;
		bool mHasDepthStencilAttachment;
		bool mHasResolveAttachment;
	};
}
