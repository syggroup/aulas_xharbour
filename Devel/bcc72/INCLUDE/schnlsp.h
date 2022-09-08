//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992-1999.
//
//  File:       schnlsp.h
//
//  Contents:   Public Definitions for SCHANNEL Security Provider
//
//  Classes:
//
//  Functions:
//
//----------------------------------------------------------------------------

#ifndef __SCHNLSP_H__
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define __SCHNLSP_H__

#if _MSC_VER > 1000
#pragma once
#endif
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#include <schannel.h>



#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma option pop /*P_O_Pop*/
#endif //__SCHNLSP_H__
