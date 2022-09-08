#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
//  Copyright (c) Microsoft Corporation. All rights reserved.
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define __MTxSpm_LIBRARY_DEFINED__
#include "comsvcs.h"

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma option pop /*P_O_Pop*/
