/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusMem.h
*
* Abstract:
*
*   GDI+ Private Memory Management APIs
*
\**************************************************************************/

#ifndef _GDIPLUSMEM_H
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define _GDIPLUSMEM_H
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#ifdef __cplusplus
extern "C" {
#endif

#define WINGDIPAPI __stdcall

//----------------------------------------------------------------------------
// Memory Allocation APIs
//----------------------------------------------------------------------------

void* WINGDIPAPI
GdipAlloc(size_t size);

void WINGDIPAPI
GdipFree(void* ptr);

#ifdef __cplusplus
}
#endif


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma option pop /*P_O_Pop*/
#endif // !_GDIPLUSMEM_H
