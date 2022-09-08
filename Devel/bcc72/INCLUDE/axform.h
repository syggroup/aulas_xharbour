/////////////////////////////////////////////////////////////////////////////
// AXFORM.H - Base class used by Active Forms
//
// $Rev: 666 $
//
// Copyright(c) 1995-2009 Embarcadero Technologies, Inc.
/////////////////////////////////////////////////////////////////////////////
#ifndef __AXFORM_H
#define __AXFORM_H

#include <Forms.hpp>

// TActiveForm: Base class for a VCL Form exposed as an OCX Control
//
class TActiveForm : public Forms::TCustomActiveForm
{
  typedef Forms::TCustomActiveForm inherited;
public:
  __fastcall virtual TActiveForm(HWND ParentWindow): Forms::TCustomActiveForm(ParentWindow) {}
  __fastcall virtual TActiveForm(TComponent* AOwner): Forms::TCustomActiveForm(AOwner) {}
};


#endif	//	__AXFORM_H
