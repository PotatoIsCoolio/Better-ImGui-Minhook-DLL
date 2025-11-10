#include "Globals.h"

namespace ImGuiProject::Config
{
    bool DllDeveloperMode = true;
}

namespace ImGuiProject::Globals
{
	namespace Test // This could be called like Movement or like Combat. Whatever its just the type of variable its gonna be used for.
	{
		bool CheckboxBool;
	}

	namespace Test2
	{
		float FovSlider; // Just another example
	}

    namespace Settings
    {
        int CurrentSeletedTheme = 0;
        const char* Themes[9] =
        {
            "Purple",
            "Red",
            "Blue",
            "Green",
            "Orange",
            "Cyan",
            "Yellow",
            "Femboy Pink",
            "Mint"
        };

        int MenuKeybind = VK_DELETE;
        const char* keyNames[] = {
            "None",
            "Insert", "Delete", "Home", "End", "Page Up", "Page Down",
            "Arrow Up", "Arrow Down", "Arrow Left", "Arrow Right",
            "Tab", "Caps Lock", "Left Shift", "Right Shift",
            "Left Ctrl", "Right Ctrl", "Left Alt", "Right Alt",
            "Space", "Enter", "Escape",
            "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
            "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
            "U", "V", "W", "X", "Y", "Z",
            "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
        };

        int keyValues[] = {
            0,
            VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT,
            VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
            VK_TAB, VK_CAPITAL, VK_LSHIFT, VK_RSHIFT,
            VK_LCONTROL, VK_RCONTROL, VK_LMENU, VK_RMENU,
            VK_SPACE, VK_RETURN, VK_ESCAPE,
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
        };
        int keyCount = sizeof(keyNames) / sizeof(keyNames[0]);
    }
}