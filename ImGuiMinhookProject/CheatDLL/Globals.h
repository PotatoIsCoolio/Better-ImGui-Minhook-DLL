#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <thread>

#include "../Deps/Kiero/kiero.h"
#include "../Deps/ImGui/imgui.h"
#include "../Deps/ImGui/imgui_impl_win32.h"
#include "../Deps/ImGui/imgui_impl_dx11.h"
#include "../Deps/Kiero/minhook/include/MinHook.h"

namespace ImGuiProject::Config
{
	extern bool DllDeveloperMode;
}

namespace ImGuiProject::Globals
{
	namespace Render
	{
		extern int CurrentSection;
	}

	namespace Test // This could be called like Movement or like Combat. Whatever its just the type of variable its gonna be used for.
	{
		extern bool CheckboxBool;
	}

	namespace Test2
	{
		extern float FovSlider; // Just another example
	}

	namespace Settings
	{
		extern int CurrentSeletedTheme;
		extern const char* Themes[9];
		extern int MenuKeybind;
		extern const char* keyNames[];
		extern int keyValues[];
		extern int keyCount;
	}
}