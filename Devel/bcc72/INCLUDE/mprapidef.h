/****************************************************************************
*                                                                           *
* mprapidef.h -- MPR definitions shared between user and kernel mode        *
*                                                                           *
* Copyright (c) Microsoft Corporation. All rights reserved.                 *
*                                                                           *
****************************************************************************/

#ifndef _MPRAPIDEF_
#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#define _MPRAPIDEF_

#include <lmcons.h>

#define MAX_INTERFACE_NAME_LEN  256
#define MAX_TRANSPORT_NAME_LEN  40
#define MAX_MEDIA_NAME          16
#define MAX_PORT_NAME           16
#define MAX_DEVICE_NAME         128
#define MAX_PHONE_NUMBER_LEN    128
#define MAX_DEVICETYPE_NAME     16


#pragma option pop /*P_O_Pop*/
#endif // _MPRAPIDEF_