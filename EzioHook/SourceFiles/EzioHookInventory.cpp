#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <imgui.h>
#include <windows.h>
#include <MemoryHelpers.h>
#include <GetPointer.h>
#include <algorithm>
#include <stdint.h>
#include <EzioHookOtherWindows.h>
void InventoryAC2()
{
    size_t PlayerMoneyBaseAddr = 0x022134B4;
    size_t PlayerMoneyOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0x00, 0x10 };
    size_t PlayerMoneyResult = GetPointer(PlayerMoneyBaseAddr, PlayerMoneyOffsets, _countof(PlayerMoneyOffsets));
    if (PlayerMoneyResult == 0)
    {
        ImGui::Checkbox("Show Adjustment Amount Config", &ShowPlayerInventoryAdjustAmountWindowAC2); 
        ImGui::BeginDisabled(true);
        ImGui::InputInt("Florins(Money)", &EHIntCannotRead, 1, 0);
        if (ShowPlayerInventoryAdjustAmountWindowAC2)
        {
            EzioHookAC2PlayerInventoryAdjustAmountWindow();
        }
        ImGui::EndDisabled();
    }
    if (PlayerMoneyResult != 0)
    {
        ImGui::Checkbox("Show Adjustment Amount Config", &ShowPlayerInventoryAdjustAmountWindowAC2);
        ImGui::InputInt("Florins(Money)", (int*)PlayerMoneyResult, EHPlayerMoneyAdjustAmount, EHPlayerMoneyAdjustAmountFast);
        *((int*)PlayerMoneyResult) = std::clamp(*(int*)PlayerMoneyResult, 20, 2000000000);
        if (ShowPlayerInventoryAdjustAmountWindowAC2)
        {
            EzioHookAC2PlayerInventoryAdjustAmountWindow();
        }
    }
}