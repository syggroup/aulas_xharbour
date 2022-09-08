/*++

Copyright (c) 2014 Microsoft Corporation

Abstract:

    This module contains the software restriction policy (SRP)
    APIs and the associated data structures.

--*/

#ifndef INC_SRPAPI
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define INC_SRPAPI

#if _MSC_VER > 1000
#pragma once
#endif

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#if (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD)

typedef struct HTHREAD_NETWORK_CONTEXT
{
    DWORD ThreadId;
    HANDLE ThreadContext;
} HTHREAD_NETWORK_CONTEXT;

STDAPI
SrpCreateThreadNetworkContext(
    _In_ PCWSTR enterpriseId,
    _Out_ HTHREAD_NETWORK_CONTEXT* threadNetworkContext
    );

STDAPI
SrpCloseThreadNetworkContext(
    _Inout_ HTHREAD_NETWORK_CONTEXT* threadNetworkContext
    );

STDAPI
SrpSetTokenEnterpriseId (
    _In_ HANDLE tokenHandle,
    _In_opt_ PCWSTR enterpriseId
    );

HRESULT
SrpGetProcessFQBNAttributeValue(
    _In_ DWORD ProcessId,
    _Outptr_result_maybenull_ PWSTR* FQBNAttributeValue
    );

#endif /* _WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD */

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


#pragma option pop /*P_O_Pop*/
#endif INC_SRPAPI