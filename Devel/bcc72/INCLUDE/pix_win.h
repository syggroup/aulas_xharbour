#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
/*==========================================================================;
 *
 *  Copyright (C) Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       pix_win.h
 *  Content:    PIX implementation details
 *              Don't include this file directly - use pix.h
 *
 ****************************************************************************/

#pragma once

#ifndef _PIX_WIN_H_
#define _PIX_WIN_H_

#include <utility>

namespace DirectX
{
    namespace Detail
    {
        static const UINT PIX_EVENT_UNICODE_VERSION = 0;
        static const UINT PIX_EVENT_ANSI_VERSION = 1;
        static const size_t PIX_STRING_BUFFER_COUNT = 1024;
    }
}

// ----------------------------------------------------------------------------
// PIXSetMarker
// ----------------------------------------------------------------------------

inline void PIXSetMarker(UINT64 /*metadata*/, PCWSTR /*pFormat*/, ...)
{
    // Not implemented on Windows
}

inline void PIXSetMarker(UINT64 /*metadata*/, PCSTR /*pFormat*/, ...)
{
    // Not implemented on Windows
}

inline void PIXSetMarker(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCWSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandList->SetMarker(PIX_EVENT_UNICODE_VERSION, pFormat, (wcslen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXSetMarker(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCWSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandQueue->SetMarker(PIX_EVENT_UNICODE_VERSION, pFormat, (wcslen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXSetMarker(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCWSTR pFormat)
{
    pAnnotation->SetMarker(pFormat);
}

inline void PIXSetMarker(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCWSTR pFormat)
{
    pContext->SetMarkerInt(pFormat, 0);
}

inline void PIXSetMarker(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandList->SetMarker(PIX_EVENT_ANSI_VERSION, pFormat, (strlen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXSetMarker(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandQueue->SetMarker(PIX_EVENT_ANSI_VERSION, pFormat, (strlen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXSetMarker(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pFormat, -1, buf, ARRAYSIZE(buf));

    pAnnotation->SetMarker(buf);
}

inline void PIXSetMarker(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pFormat, -1, buf, ARRAYSIZE(buf));

    pContext->SetMarkerInt(buf, 0);
}

template <typename... TArgs>
inline void PIXSetMarker(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    int count = _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;
    
    pCommandList->SetMarker(PIX_EVENT_UNICODE_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXSetMarker(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    int count = _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pCommandQueue->SetMarker(PIX_EVENT_UNICODE_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXSetMarker(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    pAnnotation->SetMarker(buf);
}

template <typename... TArgs>
inline void PIXSetMarker(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    pContext->SetMarkerInt(buf, 0);
}

template <typename... TArgs>
inline void PIXSetMarker(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    int count = _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pCommandList->SetMarker(PIX_EVENT_ANSI_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXSetMarker(ID3D12CommandQueue* pQueue, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    int count = _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pQueue->SetMarker(PIX_EVENT_ANSI_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXSetMarker(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    wchar_t bufW[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, buf, -1, bufW, ARRAYSIZE(bufW));

    pAnnotation->SetMarker(bufW);
}

template <typename... TArgs>
inline void PIXSetMarker(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    wchar_t bufW[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, buf, -1, bufW, ARRAYSIZE(bufW));

    pContext->SetMarkerInt(bufW, 0);
}

// ----------------------------------------------------------------------------
// PIXBeginEvent
// ----------------------------------------------------------------------------

inline void PIXBeginEvent(UINT64 /*metadata*/, PCWSTR /*pFormat*/, ...)
{
    // Not implemented on Windows
}

inline void PIXBeginEvent(UINT64 /*metadata*/, PCSTR /*pFormat*/, ...)
{
    // Not implemented on Windows
}

inline void PIXBeginEvent(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCWSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandList->BeginEvent(PIX_EVENT_UNICODE_VERSION, pFormat, (wcslen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXBeginEvent(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCWSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandQueue->BeginEvent(PIX_EVENT_UNICODE_VERSION, pFormat, (wcslen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXBeginEvent(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCWSTR pFormat)
{
    pAnnotation->BeginEvent(pFormat);
}

inline void PIXBeginEvent(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCWSTR pFormat)
{
    pContext->BeginEventInt(pFormat, 0);
}

inline void PIXBeginEvent(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandList->BeginEvent(PIX_EVENT_ANSI_VERSION, pFormat, (strlen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXBeginEvent(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;
    pCommandQueue->BeginEvent(PIX_EVENT_ANSI_VERSION, pFormat, (strlen(pFormat) + 1) * sizeof(pFormat[0]));
}

inline void PIXBeginEvent(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pFormat, -1, buf, ARRAYSIZE(buf));

    pAnnotation->BeginEvent(buf);
}

inline void PIXBeginEvent(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCSTR pFormat)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pFormat, -1, buf, ARRAYSIZE(buf));

    pContext->BeginEventInt(buf, 0);
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    int count = _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pCommandList->BeginEvent(PIX_EVENT_UNICODE_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    int count = _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pCommandQueue->BeginEvent(PIX_EVENT_UNICODE_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    pAnnotation->BeginEvent(buf);
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCWSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    wchar_t buf[PIX_STRING_BUFFER_COUNT];
    _snwprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    pContext->BeginEventInt(buf, 0);
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3D12GraphicsCommandList* pCommandList, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    int count = _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pCommandList->BeginEvent(PIX_EVENT_ANSI_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3D12CommandQueue* pCommandQueue, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    int count = _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...) + 1;
    if (count == 0) // string was truncated
        count = PIX_STRING_BUFFER_COUNT;

    pCommandQueue->BeginEvent(PIX_EVENT_ANSI_VERSION, buf, count * sizeof(buf[0]));
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3DUserDefinedAnnotation* pAnnotation, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    wchar_t bufW[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, buf, -1, bufW, ARRAYSIZE(bufW));

    pAnnotation->BeginEvent(bufW);
}

template <typename... TArgs>
inline void PIXBeginEvent(ID3D11DeviceContext2* pContext, UINT64 /*metadata*/, PCSTR pFormat, TArgs&&... args)
{
    using namespace DirectX::Detail;

    char buf[PIX_STRING_BUFFER_COUNT];
    _snprintf_s(buf, _TRUNCATE, pFormat, std::forward<TArgs>(args)...);

    wchar_t bufW[PIX_STRING_BUFFER_COUNT];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, buf, -1, bufW, ARRAYSIZE(bufW));

    pContext->BeginEventInt(bufW, 0);
}

// ----------------------------------------------------------------------------
// PIXEndEvent
// ----------------------------------------------------------------------------

inline void PIXEndEvent()
{
    // Not implemented on Windows
}

inline void PIXEndEvent(ID3D12GraphicsCommandList* pCommandList)
{
    pCommandList->EndEvent();
}

inline void PIXEndEvent(ID3D12CommandQueue* pCommandQueue)
{
    pCommandQueue->EndEvent();
}

inline void PIXEndEvent(ID3DUserDefinedAnnotation* pAnnotation)
{
    pAnnotation->EndEvent();
}

inline void PIXEndEvent(ID3D11DeviceContext2* pContext)
{
    pContext->EndEvent();
}

#endif // _PIX_WIN_H_
#pragma option pop /*P_O_Pop*/
