#include "Gui.h"

void ImGuiProject::Render::Setup()
{
	MH_Initialize();
    {
        if (ImGuiProject::Config::DllDeveloperMode)
            AllocConsole();
            freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
            freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
			SetConsoleTitleA("Potatos Console");
			printf("WARNING!! This console is made for Developers only! \nIf you do not want users to see this then please go to Globals.cpp and make DllDeveloperMode false please.");
		ImGuiProject::Render::Styles::PurpleStyle();
    }
}

void ImGuiProject::Render::GUI()
{
    ImGui::Begin("ImGui Project | PotatoIsCool"); // Title of the imgui
    if (ImGui::BeginTabBar("Tabs")) // Makes the tabs for the imgui so you can have Main and Settings add more if you want
    {
        if (ImGui::BeginTabItem("Main")) // adds the main tab
        {
            ImGui::Text("Thx for using this template <33");
            ImGui::Checkbox("CheckBox", &ImGuiProject::Globals::Test::CheckboxBool);
            ImGui::SliderFloat("Slider", &ImGuiProject::Globals::Test2::FovSlider, 1.0f, 100.0f, "%.1f");

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Settings")) // Adds the setting tab
        {
			ImGui::Text("Settings go here");
			ImGui::Text("Select Theme: ");
			if (ImGui::Combo("##Themes", &Globals::Settings::CurrentSeletedTheme, Globals::Settings::Themes, 9))
			{
				switch (Globals::Settings::CurrentSeletedTheme)
				{
					case 0: Render::Styles::PurpleStyle();
						break;
					case 1: Render::Styles::RedStyle();
						break;
					case 2: Render::Styles::BlueStyle();
						break;
					case 3: Render::Styles::GreenStyle();
						break;
					case 4: Render::Styles::OrangeStyle();
						break;
					case 5: Render::Styles::CyanStyle();
						break;
					case 6: Render::Styles::YellowStyle();
						break;
					case 7: Render::Styles::PinkStyle();
						break;
					case 8: Render::Styles::MintStyle();
						break;
				}
			}
			int CurrentKeyIndex = 0;
			for (int i = 0; i < Globals::Settings::keyCount; ++i) {
				if (Globals::Settings::keyValues[i] == Globals::Settings::MenuKeybind) {
					CurrentKeyIndex = i;
					break;
				}
			}
			if (ImGui::Combo("Toggle Menu Key", &CurrentKeyIndex, Globals::Settings::keyNames, Globals::Settings::keyCount)) {
				Globals::Settings::MenuKeybind = Globals::Settings::keyValues[CurrentKeyIndex];
			}

            if (ImGui::Button("Close game"))
                exit(0);

            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();
}