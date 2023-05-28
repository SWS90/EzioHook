# EzioHook
EzioHook is a WIP in-game Trainer/Cheat menu for the Assassins Creed Ezio games on PC.  
EzioHook was created by [SWS90](https://github.com/SWS90) with additional help from [Sajid](https://github.com/Sajidur78)  

EzioHook was made using:  
[Ocornuts Dear ImGui](https://github.com/ocornut/imgui)  
[TsudaKageyus MinHook](https://github.com/TsudaKageyu/minhook")  
[Furkankadirguzeloglus DX9 DearImgui base](https://github.com/furkankadirguzeloglu/ImGuiHook-DirectX9)    
EzioHooks Credits Menu was made using code from [SSSiyans BayoHook](https://github.com/SSSiyan/BayoHook)    

Additional code usage and references:  
[Skyths DllMods MemoryHelpers](https://github.com/blueskythlikesclouds/DllMods/blob/3407e53ea9c0cd8dac513d8dab07a283cc932a88/Dependencies/Helpers.h")  
[Praydogs REFramework](https://github.com/praydog/REFramework) (Dinput8Create code)   
[CasualCoder91s DirectInput Hook](https://github.com/CasualCoder91/DirectInputYT) (MinHookHooks hookGetDeviceState function)  
[user-grinchs ImGuiRedux](https://github.com/user-grinch/ImGuiRedux) (MinHookHooks GetDinputDevice bool and MinHook hooking code)  
[Sajid](https://github.com/Sajidur78) for [GetPointer](https://github.com/thesupersonic16/HedgeModManager/blob/rewrite/HedgeModManager/Resources/MemoryService.cs#L58) code   

EzioHooks current features are:  
Assassins Creed 2:  
Force HQ LODS: Based on [Bucket5s Assassins Creed 2 Visual Fixup Mod](https://www.moddb.com/mods/assassins-creed-2-visual-fixup-mod), this will force all buildings to use the highest level-of-detail models available.  
Realtime Time Of Day editing.  
Realtime Shadow Resolution editing.  
Realtime Camera Field-Of-View editing.  
Realtime Player Position Information.   
Realtime Player Speed Information.  
Realtime Player Scale editing.  
Player Money editing.  

Usage:  
Grab dinput8.dll in the Release folder and drop it next to the game .exe  

Known bugs:  
Alt-Tabbing back into game will immediately crash the game.  
[AC2] - Having a different scale other than the default of 1 when entering certain events (for example crowd blending) will automatically resize the player to default.    
However leaving the event will resize the player to the previous set scale. Attemping to scale the player down after this will result in a incorrect looking/acting player.    
You must return to the title screen and reload your save to fix this!  

Game compatibility:  
Ezio Hooks memory addresses were made using the Steam version of each game.     
Assassins Creed 2 Steam version MD5: 7d6b866eeacfc7a69a00f800a529bf8e  
Assassins Creed Brotherhood Steam version MD5: (will generate once development on Brotherhood support begins)  
Assassins Creed Revelations Steam version MD5: (will generate once development on Revelations support begins)  
Any other versions of the games may have crashes/other issues.  
