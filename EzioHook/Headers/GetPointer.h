#pragma once
 inline size_t GetPointer(size_t address, const size_t* offsets, size_t numOffsets)
 {
     if (address == 0)
         return 0;

     size_t result = *(size_t*)(address);

     if (result == 0)
         return 0;

     if (numOffsets > 0)
     {
         for (size_t i = 0; i < numOffsets - 1; i++)
         {
             result = (size_t)((char*)(result)+offsets[i]);
             result = *(size_t*)(result);
             if (result == 0)
                 return 0;
         }

         return result + offsets[numOffsets - 1];
     }

     return result;
 }
