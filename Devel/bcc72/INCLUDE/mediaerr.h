//------------------------------------------------------------------------------
// File: MediaErr.h
//
// Desc: Shell error codes
//
// Copyright (c) 1999 - 2001, Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------


#ifndef _MEDIAERR_H_
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define _MEDIAERR_H_
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#define DMO_E_INVALIDSTREAMINDEX 0x80040201
#define DMO_E_INVALIDTYPE        0x80040202
#define DMO_E_TYPE_NOT_SET       0x80040203
#define DMO_E_NOTACCEPTING       0x80040204
#define DMO_E_TYPE_NOT_ACCEPTED  0x80040205
#define DMO_E_NO_MORE_ITEMS      0x80040206


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma option pop /*P_O_Pop*/
#endif _MEDIAERR_H_
