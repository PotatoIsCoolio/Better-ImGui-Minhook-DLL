#include "Hooks.h"
// This might seem like a lot to new people but I promise you it isnt.

void (*Old_ExampleHooker)(void* Param);
void ExampleHook(void* Param)
{
    if (ImGuiProject::Globals::Test::CheckboxBool) // This makes it so the hook will do whatever if the ImGui bool is turned on.
    {
        if (ImGuiProject::Config::DllDeveloperMode)
            printf("Offset called!");
        return Old_ExampleHooker(Param);
    }

    // Put the hooks functionality in here.
    return Old_ExampleHooker(Param);
}

void ImGuiProject::Cheat::StartHooks()
{
    HMODULE GameAssembly = GetModuleHandleA("GameAssembly.dll");
    uintptr_t base = reinterpret_cast<uintptr_t>(GameAssembly);
    
    // Debug log.
    if (ImGuiProject::Config::DllDeveloperMode)
        printf("Base address: 0x%p\n", reinterpret_cast<void*>(base));



    // This is the only thing you need to focus on here
    MH_CreateHook((LPVOID)(base + /* OFFSET HERE!! */ 0x0), &ExampleHook, reinterpret_cast<LPVOID*>(&Old_ExampleHooker));





    auto MinHookStatus = MH_EnableHook(MH_ALL_HOOKS);
    if (MinHookStatus != MH_OK) 
    {
        if (ImGuiProject::Config::DllDeveloperMode)
            printf("Failed to enable hooks! %d\n", MinHookStatus);
    }
}