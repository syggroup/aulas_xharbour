/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

//-----------------------------------------------------------------------------
// File:		adoid.h
//
// Contents:	ADO Guids.	
//-----------------------------------------------------------------------------

#ifndef _ADOID_H_
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define _ADOID_H_
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#include "adodef.h"
#include "ADOGuids.h"

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma option pop /*P_O_Pop*/
#endif // _ADOID_H_
