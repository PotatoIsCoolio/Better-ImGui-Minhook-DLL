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
			printf("WARNING!! This console is made for Developers only! \nIf you do not want users to see this then please go to Globals.cpp and make DllDeveloperMode false please.\n");
		ImGuiProject::Render::Styles::PurpleStyle();
    }
}

void ImGuiProject::Render::GUI()
{
    ImGui::Begin("ImGui Project | PotatoIsCool"); // Title of the menu

    ImGui::BeginChild("SidePanel", ImVec2(150, 0), true); 

    ImGui::Text("Tabs");
    ImGui::Separator();

    // These are the buttons that are on the left tab.
    if (ImGui::Selectable("Main", ImGuiProject::Globals::Render::CurrentSection == 0, ImGuiSelectableFlags_None, ImVec2(0, 30))) 
    {
        ImGuiProject::Globals::Render::CurrentSection = 0;
    }

    if (ImGui::Selectable("Settings", ImGuiProject::Globals::Render::CurrentSection == 1, ImGuiSelectableFlags_None, ImVec2(0, 30))) 
    {
        ImGuiProject::Globals::Render::CurrentSection = 1;
    }

    ImGui::Dummy(ImVec2(0, ImGui::GetContentRegionAvail().y - 30));
    ImGui::Separator();
    ImGui::Text("ImGui Template");

    ImGui::EndChild();

    ImGui::SameLine();
    
    ImGui::BeginChild("ContentPanel", ImVec2(0, 0), true);

    if (ImGuiProject::Globals::Render::CurrentSection == 0) // Main Panel
    {
        ImGui::Text("Main");
        ImGui::Separator();
        ImGui::Text("Thxxx for using this template <33");

        if (ImGui::CollapsingHeader("Main Features"))
        {
            ImGui::Indent();
            ImGui::Checkbox("##CheckboxToggle", &ImGuiProject::Globals::Test::CheckboxBool);
            ImGui::SameLine();
            ImGui::Text("Feature Toggle");

            ImGui::Unindent();
        }

        if (ImGui::CollapsingHeader("Credits"))
        {
            ImGui::Indent();
            if (ImGui::BeginTable("CreditsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
            {
                ImGui::TableNextColumn();
                ImGui::Text("Developer:");

                ImGui::TableNextColumn();
                ImGui::Text("PotatoIsCool");

                ImGui::TableNextColumn();
                ImGui::Text("Version");

                ImGui::TableNextColumn();
                ImGui::Text("v1.0");

                ImGui::EndTable();
            }
            ImGui::Unindent();
        }
    }

    else if (ImGuiProject::Globals::Render::CurrentSection == 1) // Settings Panel
    {
        ImGui::Text("Settings");
        ImGui::Separator();

        ImGui::Text("Visual Settings");
        ImGui::PushItemWidth(200);
        if (ImGui::Combo("Select Theme", &Globals::Settings::CurrentSeletedTheme, Globals::Settings::Themes, 9))
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
        ImGui::PopItemWidth();

        ImGui::Text("\Keybind");
        int CurrentKeyIndex = 0;
        for (int i = 0; i < Globals::Settings::keyCount; ++i) {
            if (Globals::Settings::keyValues[i] == Globals::Settings::MenuKeybind) {
                CurrentKeyIndex = i;
                break;
            }
        }
        ImGui::PushItemWidth(200);
        if (ImGui::Combo("Toggle Menu Key", &CurrentKeyIndex, Globals::Settings::keyNames, Globals::Settings::keyCount)) {
            Globals::Settings::MenuKeybind = Globals::Settings::keyValues[CurrentKeyIndex];
        }
        ImGui::PopItemWidth();

        ImGui::Dummy(ImVec2(0, 10));
        ImGui::Separator();

        if (ImGui::Button("Exit Game"))
            exit(0);
    }

    ImGui::EndChild();
    ImGui::End();
}