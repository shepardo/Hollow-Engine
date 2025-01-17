#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Memory/MemoryBuffer.h>
#include <Runtime/Memory/MemoryOwnedBuffer.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include <Runtime/ShaderCompiler/ShaderReflection.h>
#include <Runtime/ShaderCompiler/ShaderIncluder.h>

namespace Hollow
{
	class RUNTIME_API ShaderCompiler
	{
	public:
		static bool CompileShaderToSPIRV(const String& Source, const String& entryMethod, const ShaderStage stage,
			const ShaderLanguage language, u32** ppBytesOut, u32& bytesSizeOut, String& errorMessageOut) { return true; }
		static bool CompileShaderToSPIRV(const MemoryBuffer& view, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, 
			MemoryOwnedBuffer& pViewOut, String& errorMessageOut);
		static bool ReflectShader(MemoryOwnedBuffer& buffer, SharedPtr<ShaderReflection> reflectedData);
	public:
		ShaderCompiler() = delete;
		~ShaderCompiler() = delete;
	};
}