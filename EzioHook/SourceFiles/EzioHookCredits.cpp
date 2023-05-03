#include <imgui.h>
#include<array>
#include <string>
#include <Windows.h>
#include <shellapi.h>
#include <WinUser.h>
#include <LicenseStrings.hpp>
void under_line(const ImColor& col)
{
    ImVec2 min = ImGui::GetItemRectMin();
    ImVec2 max = ImGui::GetItemRectMax();
    min.y = max.y;
    ImGui::GetWindowDrawList()->AddLine(min, max, col, 1.0f);
}
struct ImGuiURL
{
    std::string text;
    std::string url;
    const ImVec4 color_hover{ 0.356f, 0.764f, 0.960f, 1.00f };
    const ImVec4 color_regular{ 0.950f, 0.960f, 0.980f, 1.00f };

    void draw()
    {
        ImGui::TextColored(color_regular, text.c_str());
        if (ImGui::IsItemHovered())
        {
            under_line(color_hover);
        }
        if (ImGui::IsItemClicked())
        {
            ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
        }
    }
};
void EzioHookCredits()
{
    ImGui::SetWindowSize(ImVec2(615, 500));
    ImGui::BeginChild("EHCreditsChild");
    ImGui::Text("EzioHook was made by SWS90, with additional help from Sajid");
    static std::array<ImGuiURL, 1> links1
    {
        ImGuiURL { "SWS90's GitHub", "https://github.com/SWS90/" }
        
    };
    for (auto& link : links1)
    {
        link.draw();
    }
    ImGui::Separator();
    static std::array<ImGuiURL, 2> links2
    {
        ImGuiURL { "Sajid's GitHub", "https://github.com/Sajidur78" },
        ImGuiURL { "Sajid's Twitter", "https://twitter.com/Sajidur78" }
    };
    for (auto& link : links2)
    {
        link.draw();
    }
    ImGui::Separator();
    ImGui::Text("EzioHook was made using:");
    static std::array<ImGuiURL, 4> links3
    {
        ImGuiURL { "Ocornut's Dear ImGui", "https://github.com/ocornut/imgui" },
        ImGuiURL { "TsudaKageyu's MinHook", "https://github.com/TsudaKageyu/minhook" },
        ImGuiURL { "Furkankadirguzeloglu's DX9 DearImgui base", "https://github.com/furkankadirguzeloglu/ImGuiHook-DirectX9" },
        ImGuiURL { "This Credits Menu was made using code from SSSiyan's BayoHook", "https://github.com/SSSiyan/BayoHook" },
    };
    for (auto& link : links3)
    {
        link.draw();
    }
    ImGui::Separator();
    ImGui::Text("Additonal code references:");
    static std::array<ImGuiURL, 4> links4
    {
        ImGuiURL { "Skyth's DllMods MemoryHelpers", "https://github.com/blueskythlikesclouds/DllMods/blob/3407e53ea9c0cd8dac513d8dab07a283cc932a88/Dependencies/Helpers.h" },
        ImGuiURL { "Praydog's REFramework (Dinput8Create code)", "https://github.com/praydog/REFramework" },
        ImGuiURL { "CasualCoder91's DirectInput Hook (MinHookHooks' hookGetDeviceState function", "https://github.com/CasualCoder91/DirectInputYT" },
        ImGuiURL { "user-grinch's ImGuiRedux (MinHookHooks' GetDinputDevice bool and MinHook hooking code", "https://github.com/user-grinch/ImGuiRedux" }
    };
    for (auto& link : links4)
    {
        link.draw();
    }
    ImGui::Separator();
    ImGui::Text("Licenses:");
    struct License
    {
        std::string name;
        std::string text;
    };
    static std::array<License, 2> licenses
    {
        License{ "ImGui", license::ImGui },
        License{ "MinHook", license::MinHook },
    };
    for (const auto& license : licenses)
    {
        if (ImGui::CollapsingHeader(license.name.c_str())) 
        {
            ImGui::TextWrapped(license.text.c_str());
        }
    }
    ImGui::Separator();
    ImGui::EndChild();
    ImGui::EndTabItem();
    ImGui::EndTabBar();

}
