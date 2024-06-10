#pragma once

#include <Runtime/Core/Definitions.h>
#include <Runtime/Core/StdFix.h>

#include <Runtime/Monitor/MonitorDesc.h>

namespace Hollow
{
	class RUNTIME_API Monitor
	{
	public:
		static SharedPtr<Monitor> CreateMonitorInfo(const MonitorDesc& desc)
		{
			return std::make_shared<Monitor>(desc);
		}

	public:
		Monitor(const MonitorDesc& desc) : mMonitorName(desc.MonitorName), mMonitorResolution(desc.MonitorResolution), 
			mRefreshRate(desc.RefreshRate), mBitsPerPixel(desc.BitsPerPixel){}
		~Monitor() = default;

		String GetMonitorName() const { return mMonitorName; }
		Vector2i GetMonitorResolution() const { return mMonitorResolution; }
		u16 GetRefreshRate() const { return mRefreshRate; }
		byte GetBitsPerPixel() const { return mBitsPerPixel; }

	private:
		String mMonitorName;
		Vector2i mMonitorResolution;
		u16 mRefreshRate;
		byte mBitsPerPixel;
	};
}
