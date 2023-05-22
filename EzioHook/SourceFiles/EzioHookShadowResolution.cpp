#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <imgui.h>
#include <windows.h>
#include <MemoryHelpers.h>
#include <stdint.h>
#include <algorithm>
static int ShadowResItemOptions = 0;
const char* ShadowResOptions[] = { "512 (Game Low/Med)", "1024 (Game High)", "2048", "3072","4096","Custom" };
void ShadowResolutionAC2()
{
    ImGui::Combo("Shadow Resolution", &ShadowResItemOptions, ShadowResOptions, IM_ARRAYSIZE(ShadowResOptions));
    if (ShadowResItemOptions == 0) // 512 (Game Low/Med)
    {
        WRITE_MEMORY(0x021D0278, int, 512); // Shadow Res 1
        WRITE_MEMORY(0x02243CF0, int, 512); // Shadow Res 2
        WRITE_MEMORY(0x022441D0, int, 512); // Shadow Res 3
    }
    if (ShadowResItemOptions == 1) // 1024 (Game High)
    {
        WRITE_MEMORY(0x021D0278, int, 1024); // Shadow Res 1
        WRITE_MEMORY(0x02243CF0, int, 1024); // Shadow Res 2
        WRITE_MEMORY(0x022441D0, int, 1024); // Shadow Res 3
    }
    else if (ShadowResItemOptions == 2) // 2048
    {
        WRITE_MEMORY(0x021D0278, int, 2048); // Shadow Res 1
        WRITE_MEMORY(0x02243CF0, int, 2048); // Shadow Res 2
        WRITE_MEMORY(0x022441D0, int, 2048); // Shadow Res 3
    }
    else if (ShadowResItemOptions == 3) // 3072
    {
        WRITE_MEMORY(0x021D0278, int, 3072); // Shadow Res 1
        WRITE_MEMORY(0x02243CF0, int, 3072); // Shadow Res 2
        WRITE_MEMORY(0x022441D0, int, 3072); // Shadow Res 3
    }
    else if (ShadowResItemOptions == 4) // 4096
    {
        WRITE_MEMORY(0x021D0278, int, 4096); // Shadow Res 1
        WRITE_MEMORY(0x02243CF0, int, 4096); // Shadow Res 2
        WRITE_MEMORY(0x022441D0, int, 4096); // Shadow Res 3
    }
    else if (ShadowResItemOptions == 5) // Custom
    {
        ImGui::SliderInt("Custom Shadow Resolution", &ShadowResValueAC2, 1, 4096);
        ShadowResValueAC2 = std::clamp(ShadowResValueAC2, 1, 4096);
        WRITE_MEMORY(0x021D0278, int, ShadowResValueAC2); // Shadow Res 1
        WRITE_MEMORY(0x02243CF0, int, ShadowResValueAC2); // Shadow Res 2
        WRITE_MEMORY(0x022441D0, int, ShadowResValueAC2); // Shadow Res 3
    }
}