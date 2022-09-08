#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/


/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0611 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __hrtfapoapi_h__
#define __hrtfapoapi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IXAPOHrtfParameters_FWD_DEFINED__
#define __IXAPOHrtfParameters_FWD_DEFINED__
typedef interface IXAPOHrtfParameters IXAPOHrtfParameters;

#endif 	/* __IXAPOHrtfParameters_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_hrtfapoapi_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#include <float.h>
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define HRTF_2PI                             6.283185307f
#define HRTF_MAX_GAIN_LIMIT                  12.0f
#define HRTF_MIN_GAIN_LIMIT                  -96.0f
#define HRTF_MIN_UNITY_GAIN_DISTANCE         0.05f
#define HRTF_DEFAULT_UNITY_GAIN_DISTANCE     1.0f
#define HRTF_DEFAULT_CUTOFF_DISTANCE         FLT_MAX
typedef struct _HrtfPosition
    {
    float x;
    float y;
    float z;
    } 	HrtfPosition;

typedef struct _HrtfOrientation
    {
    float o[ 9 ];
    } 	HrtfOrientation;

typedef 
enum _HrtfDirectivityType
    {
        OmniDirectional	= 0,
        Cardioid	= ( OmniDirectional + 1 ) ,
        Cone	= ( Cardioid + 1 ) 
    } 	HrtfDirectivityType;

typedef 
enum _HrtfEnvironment
    {
        Small	= 0,
        Medium	= ( Small + 1 ) ,
        Large	= ( Medium + 1 ) ,
        Outdoors	= ( Large + 1 ) ,
        Count	= ( Outdoors + 1 ) 
    } 	HrtfEnvironment;

typedef struct _HrtfDirectivity
    {
    HrtfDirectivityType type;
    float scaling;
    } 	HrtfDirectivity;

typedef struct _HrtfDirectivityCardioid
    {
    HrtfDirectivity directivity;
    float order;
    } 	HrtfDirectivityCardioid;

typedef struct _HrtfDirectivityCone
    {
    HrtfDirectivity directivity;
    float innerAngle;
    float outerAngle;
    } 	HrtfDirectivityCone;

typedef 
enum _HrtfDistanceDecayType
    {
        NaturalDecay	= 0,
        CustomDecay	= ( NaturalDecay + 1 ) 
    } 	HrtfDistanceDecayType;

typedef struct _HrtfDistanceDecay
    {
    HrtfDistanceDecayType type;
    float maxGain;
    float minGain;
    float unityGainDistance;
    float cutoffDistance;
    } 	HrtfDistanceDecay;

typedef struct _HrtfApoInit
    {
    HrtfDistanceDecay *pDistanceDecay;
    HrtfDirectivity *pDirectivity;
    } 	HrtfApoInit;

STDAPI CreateHrtfApo(_In_ const HrtfApoInit* pInit, _Outptr_ IXAPO** ppXapo);


extern RPC_IF_HANDLE __MIDL_itf_hrtfapoapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_hrtfapoapi_0000_0000_v0_0_s_ifspec;

#ifndef __IXAPOHrtfParameters_INTERFACE_DEFINED__
#define __IXAPOHrtfParameters_INTERFACE_DEFINED__

/* interface IXAPOHrtfParameters */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXAPOHrtfParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15B3CD66-E9DE-4464-B6E6-2BC3CF63D455")
    IXAPOHrtfParameters : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSourcePosition( 
            /* [in] */ HrtfPosition position) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSourceOrientation( 
            /* [in] */ __RPC__in const HrtfOrientation *pOrientation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSourceGain( 
            /* [in] */ float gain) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnvironment( 
            /* [in] */ HrtfEnvironment environment) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXAPOHrtfParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXAPOHrtfParameters * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXAPOHrtfParameters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXAPOHrtfParameters * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSourcePosition )( 
            __RPC__in IXAPOHrtfParameters * This,
            /* [in] */ HrtfPosition position);
        
        HRESULT ( STDMETHODCALLTYPE *SetSourceOrientation )( 
            __RPC__in IXAPOHrtfParameters * This,
            /* [in] */ __RPC__in const HrtfOrientation *pOrientation);
        
        HRESULT ( STDMETHODCALLTYPE *SetSourceGain )( 
            __RPC__in IXAPOHrtfParameters * This,
            /* [in] */ float gain);
        
        HRESULT ( STDMETHODCALLTYPE *SetEnvironment )( 
            __RPC__in IXAPOHrtfParameters * This,
            /* [in] */ HrtfEnvironment environment);
        
        END_INTERFACE
    } IXAPOHrtfParametersVtbl;

    interface IXAPOHrtfParameters
    {
        CONST_VTBL struct IXAPOHrtfParametersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXAPOHrtfParameters_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXAPOHrtfParameters_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXAPOHrtfParameters_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXAPOHrtfParameters_SetSourcePosition(This,position)	\
    ( (This)->lpVtbl -> SetSourcePosition(This,position) ) 

#define IXAPOHrtfParameters_SetSourceOrientation(This,pOrientation)	\
    ( (This)->lpVtbl -> SetSourceOrientation(This,pOrientation) ) 

#define IXAPOHrtfParameters_SetSourceGain(This,gain)	\
    ( (This)->lpVtbl -> SetSourceGain(This,gain) ) 

#define IXAPOHrtfParameters_SetEnvironment(This,environment)	\
    ( (This)->lpVtbl -> SetEnvironment(This,environment) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXAPOHrtfParameters_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_hrtfapoapi_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_hrtfapoapi_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_hrtfapoapi_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


#pragma option pop /*P_O_Pop*/
