//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//
//  Copyright (C) Microsoft Corporation, 1996-1999
//
//  File:       sipbase.h
//
//  Contents:   Generic SIP Provider Main Include File
//
//  History:    14-Feb-1997 pberkman   created
//
//--------------------------------------------------------------------------

#ifndef SIPBASE_H
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define SIPBASE_H

#if _MSC_VER > 1000
#pragma once
#endif
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


// all moved to mssip.h
#include <mssip.h>


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma option pop /*P_O_Pop*/
#endif // SIPBASE_H


