#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Descriptor/DescriptorLayout.h>

namespace Hollow
{
    struct RUNTIME_API ResourceLayoutDesc
    {
        DArray<SharedPtr<DescriptorLayout>> ResourceLayouts;
    };
}