/*==========================================================================;
 *
 *  Copyright (C) Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       d3d9types.h
 *  Content:    Direct3D capabilities include file
 *
 ***************************************************************************/


#pragma option push -b -a8 -pc -A- /*P_O_Push*/


#ifndef DIRECT3D_VERSION
#define DIRECT3D_VERSION         0x0900
#endif  //DIRECT3D_VERSION

#include <float.h>

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201) // anonymous unions warning
#if defined(_X86_) || defined(_IA64_)
#pragma pack(4)
#endif

typedef long LONG;

typedef struct _D3DVECTOR {
    float x;
    float y;
    float z;
} D3DVECTOR;

typedef struct _D3DCOLORVALUE {
    float r;
    float g;
    float b;
    float a;
} D3DCOLORVALUE;

typedef struct _D3DRECT {
    LONG x1;
    LONG y1;
    LONG x2;
    LONG y2;
} D3DRECT;

typedef struct _D3DMATRIX {
    union {
        struct {
            float        _11, _12, _13, _14;
            float        _21, _22, _23, _24;
            float        _31, _32, _33, _34;
            float        _41, _42, _43, _44;

        };
        float m[4][4];
    };
} D3DMATRIX;
