// -----------------------------------------------------------------------------------
// SystemUITypes.h C++ declarations from the System.UITypes unit
//
// $Rev: 78199 $
//
// Copyright(c) 2012 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------------
#ifndef SystemUitypes_H
#define SystemUitypes_H

#if !defined(System_UitypesHPP) 
#error Do not include this file directly.  Include 'System.UITypes.hpp'.
#endif

#if defined(_PLAT_IOS) || defined(_PLAT_ANDROID)

#include <System.Rtti.hpp> 

// Generate _TValueDataHlpr template specialization for TAlphaColor.
namespace System { 
namespace Rtti {
 
  template <> 
  struct _TValueDataHlpr<System::Uitypes::TAlphaColor> 
  { 
    static unsigned* get(const System::Uitypes::TAlphaColor &Value)
    { return const_cast<unsigned*>(&Value); } 
  }; 

// Generate _TValueRTTIHlpr template specialization for TAlphaColor.
  template <>
  struct _TValueRTTIHlpr<System::Uitypes::TAlphaColor>
  {
    static System::Typinfo::PTypeInfo get()
    { return _TRTTIGetter<TypeInfoIndex::tiiTAlphaColor>::get(); }
  };

  } // namespace Rtti
} // namespace System

#endif //defined(_PLAT_IOS) || defined(_PLAT_ANDROID)

#endif // SystemUitypes_H