#include "Swapchain.h"

#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Fence/Fence.h>

#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureBuffer.h>
#include <Runtime/Graphics/Semaphore/Semaphore.h>
#include <Runtime/Graphics/Command/CommandBuffer.h>

namespace Hollow
{
	Swapchain::Swapchain(const SwapchainDesc& desc, const SharedPtr<GraphicsDevice> pDevice) : GraphicsDeviceObject(pDevice),
		mImageSize(desc.ImageSize), mSwapchainFormat(desc.SwapchainImageFormat), mSwapchainUsage(desc.SwapchainUsage), mBufferCount(desc.BufferCount),
		mGraphicsQueue(desc.pQueue), mCurrentFrameIndex(0), mPresentMode(desc.VSync), mShareMode(desc.SwapchainMode)
	{
		// Create the fences for the swapchain
		for (u32 i = 0; i < mBufferCount; i++)
		{
			mImageSemaphores.push_back(pDevice->CreateSyncSemaphore());
			mFlightSemaphores.push_back(pDevice->CreateSyncSemaphore());
		}
	}

	void Swapchain::Resize(const Vector2u& newSize)
	{
		GetOwnerDevice()->WaitQueueIdle(GetPresentQueue());
		GetOwnerDevice()->WaitForIdle();

		for (byte i = 0; i < mBufferCount; i++)
		{
			mImageBuffers[i].reset();
			mImages[i].reset();
		}

		mImages.clear();
		mImageBuffers.clear();

		mImageSize = newSize;
		ResizeImpl(newSize);
	}

	void Swapchain::AcquireNextImage()
	{
		AcquireNextImageImpl();
	}

	void Swapchain::Present()
	{
		PresentImpl();
	}

	void Swapchain::AddTexture(SharedPtr<Texture> pTexture)
	{
		mImages.push_back(pTexture);
	}

	void Swapchain::AddTextureBuffer(SharedPtr<TextureBuffer> pTextureView)
	{
		mImageBuffers.push_back(pTextureView);
	}
}