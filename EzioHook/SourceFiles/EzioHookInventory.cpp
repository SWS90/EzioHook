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
    size_t PlayerInventoryBaseAddr = 0x022134B4;

    size_t PlayerMoneyOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0x00, 0x10 };
    size_t PlayerHiddenBladePoisonOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0x10, 0x10 };
    size_t PlayerPistolBulletsOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0x14, 0x10 };
    size_t PlayerMedicineOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0xC, 0x10 };
    size_t PlayerSmokeBombsOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0x04, 0x10 };
    size_t PlayerThrowingKnivesOffsets[] = { 0x20, 0x18, 0x00, 0x10, 0x58, 0xC, 0x10, 0x20, 0x1E };

    size_t PlayerMoneyResult = GetPointer(PlayerInventoryBaseAddr, PlayerMoneyOffsets, _countof(PlayerMoneyOffsets));
    size_t PlayerHiddenBladePoisonResult = GetPointer(PlayerInventoryBaseAddr, PlayerHiddenBladePoisonOffsets, _countof(PlayerHiddenBladePoisonOffsets));
    size_t PlayerPistolBulletsResult = GetPointer(PlayerInventoryBaseAddr, PlayerPistolBulletsOffsets, _countof(PlayerPistolBulletsOffsets));
    size_t PlayerMedicineResult = GetPointer(PlayerInventoryBaseAddr, PlayerMedicineOffsets, _countof(PlayerMedicineOffsets));
    size_t PlayerSmokeBombsResult = GetPointer(PlayerInventoryBaseAddr, PlayerSmokeBombsOffsets, _countof(PlayerSmokeBombsOffsets));
    size_t PlayerThrowingKnivesResult = GetPointer(PlayerInventoryBaseAddr, PlayerThrowingKnivesOffsets, _countof(PlayerThrowingKnivesOffsets));
    
    if (PlayerMoneyResult == 0)
    {
        ImGui::BeginDisabled(true);
        ImGui::InputInt("Florins(Money)", &EHIntCannotRead, 0, 0);
        ImGui::EndDisabled();
    }

    if (PlayerMoneyResult != 0)
    {
        ImGui::InputInt("Florins(Money)", (int*)PlayerMoneyResult, EHPlayerMoneyAdjustAmount, EHPlayerMoneyAdjustAmountFast);
        *((int*)PlayerMoneyResult) = std::clamp(*(int*)PlayerMoneyResult, 20, 2000000000);
    }

    if (PlayerHiddenBladePoisonResult == 0)
    {
        ImGui::BeginDisabled(true);
        ImGui::SliderInt("Hidden Blade Poison", &EHIntCannotRead, 0, 0);
        ImGui::EndDisabled();
    }

    if (PlayerHiddenBladePoisonResult != 0)
    {
        ImGui::SliderInt("Hidden Blade Poison", (int*)PlayerHiddenBladePoisonResult, 0, 99, NULL, ImGuiSliderFlags_AlwaysClamp);
    }

    if (PlayerPistolBulletsResult == 0)
    {
        ImGui::BeginDisabled(true);
        ImGui::SliderInt("Pistol Bullets", &EHIntCannotRead, 0, 0);
        ImGui::EndDisabled();
    }

    if (PlayerPistolBulletsResult != 0)
    {
        ImGui::SliderInt("Pistol Bullets", (int*)PlayerPistolBulletsResult, 0, 99, NULL, ImGuiSliderFlags_AlwaysClamp);
    }

    if (PlayerMedicineResult == 0)
    {
        ImGui::BeginDisabled(true);
        ImGui::SliderInt("Medicine", &EHIntCannotRead, 0, 0);
        ImGui::EndDisabled();
    }

    if (PlayerMedicineResult != 0)
    {
        ImGui::SliderInt("Medicine", (int*)PlayerMedicineResult, 0, 99, NULL, ImGuiSliderFlags_AlwaysClamp);
    }
    
    if (PlayerSmokeBombsResult == 0)
    {
        ImGui::BeginDisabled(true);
        ImGui::SliderInt("Smoke Bombs", &EHIntCannotRead, 0, 0);
        ImGui::EndDisabled();
    }

    if (PlayerSmokeBombsResult != 0)
    {
        ImGui::SliderInt("Smoke Bombs", (int*)PlayerSmokeBombsResult, 0, 99, NULL, ImGuiSliderFlags_AlwaysClamp);
    }

    if (PlayerThrowingKnivesResult == 0)
    {
        ImGui::BeginDisabled(true);
        ImGui::SliderInt("Throwing Knives", &EHIntCannotRead, 0, 0);
        ImGui::EndDisabled();
    }

    if (PlayerThrowingKnivesResult != 0)
    {
        const uint8_t MinThrowingKnives = 0;
        const uint8_t MaxThrowingKnives = 15;
        ImGui::SliderScalar("Throwing Knives", ImGuiDataType_U8, (uint8_t*)PlayerThrowingKnivesResult, &MinThrowingKnives, &MaxThrowingKnives, "%u", ImGuiSliderFlags_AlwaysClamp);
    }
}