// -------------------------------------------------------------
// This file is auto-generated, GenASMThunks.exe.
// Manual changes may be overwritten! 
//                                        5/25/2013 8:43:08 PM
// -------------------------------------------------------------
#if !defined(System_thunks_h)
#define System_thunks_h

#if !defined(__clang__) || defined(_CLANG_WIN32)
// @System@@LStrAsg$qqrr27System@%AnsiStringT$us$i0$%x27System@%AnsiStringT$us$i0$%
// System::__linkproc__ __fastcall LStrAsg(System::AnsiStringT<0>&, const System::AnsiStringT<0>)
extern "C" void __fastcall _System__LStrAsg();

// @System@@LStrCat$qqrr27System@%AnsiStringT$us$i0$%x27System@%AnsiStringT$us$i0$%
// System::__linkproc__ __fastcall LStrCat(System::AnsiStringT<0>&, const System::AnsiStringT<0>)
extern "C" void __fastcall _System__LStrCat();

// @System@@LStrCat3$qqrr27System@%AnsiStringT$us$i0$%x27System@%AnsiStringT$us$i0$%t2
// System::__linkproc__ __fastcall LStrCat3(System::AnsiStringT<0>&, const System::AnsiStringT<0>, const System::AnsiStringT<0>)
extern "C" void __fastcall _System__LStrCat3();

// @System@@LStrClr$qqrpv
// System::__linkproc__ __fastcall LStrClr(void *)
extern "C" void __fastcall _System__LStrClr();

// @System@@LStrCmp$qqrv
// System::__linkproc__ __fastcall LStrCmp()
extern "C" void __fastcall _System__LStrCmp();

// @System@@LStrDelete$qqrr27System@%AnsiStringT$us$i0$%ii
// System::__linkproc__ __fastcall LStrDelete(System::AnsiStringT<0>&, int, int)
extern "C" void __fastcall _System__LStrDelete();

// @System@@LStrFromArray$qqrr27System@%AnsiStringT$us$i0$%pcius
// System::__linkproc__ __fastcall LStrFromArray(System::AnsiStringT<0>&, char *, int, unsigned short)
extern "C" void __fastcall _System__LStrFromArray();

// @System@@LStrFromPChar$qqrr27System@%AnsiStringT$us$i0$%pcus
// System::__linkproc__ __fastcall LStrFromPChar(System::AnsiStringT<0>&, char *, unsigned short)
extern "C" void __fastcall _System__LStrFromPChar();

// @System@@LStrFromUStr$qqrr27System@%AnsiStringT$us$i0$%x20System@UnicodeStringus
// System::__linkproc__ __fastcall LStrFromUStr(System::AnsiStringT<0>&, const System::UnicodeString, unsigned short)
extern "C" void __fastcall _System__LStrFromUStr();

#if !defined(__APPLE__)
// @System@@LStrFromWChar$qqrr27System@%AnsiStringT$us$i0$%bus
// System::__linkproc__ __fastcall LStrFromWChar(System::AnsiStringT<0>&, wchar_t, unsigned short)
extern "C" void __fastcall _System__LStrFromWChar();
#else
// @System@@LStrFromWChar$qqrr27System@%AnsiStringT$us$i0$%Csus
// System::__linkproc__ __fastcall LStrFromWChar(System::AnsiStringT<0>&, char16_t, unsigned short)
extern "C" void __fastcall _System__LStrFromWChar();
#endif

// @System@@LStrFromWStr$qqrr27System@%AnsiStringT$us$i0$%x17System@WideStringus
// System::__linkproc__ __fastcall LStrFromWStr(System::AnsiStringT<0>&, const System::WideString, unsigned short)
extern "C" void __fastcall _System__LStrFromWStr();

// @System@@LStrInsert$qqrx27System@%AnsiStringT$us$i0$%r27System@%AnsiStringT$us$i0$%i
// System::__linkproc__ __fastcall LStrInsert(const System::AnsiStringT<0>, System::AnsiStringT<0>&, int)
extern "C" void __fastcall _System__LStrInsert();

// @System@@LStrSetLength$qqrr27System@%AnsiStringT$us$i0$%ius
// System::__linkproc__ __fastcall LStrSetLength(System::AnsiStringT<0>&, int, unsigned short)
extern "C" void __fastcall _System__LStrSetLength();

#if !defined(__APPLE__)
// @System@@LStrFromPWCharLen$qqrr27System@%AnsiStringT$us$i0$%pbius
// System::__linkproc__ __fastcall LStrFromPWCharLen(System::AnsiStringT<0>&, wchar_t *, int, unsigned short)
extern "C" void __fastcall _System__LStrFromPWCharLen();
#else
// @System@@LStrFromPWCharLen$qqrr27System@%AnsiStringT$us$i0$%pCsius
// System::__linkproc__ __fastcall LStrFromPWCharLen(System::AnsiStringT<0>&, char16_t *, int, unsigned short)
extern "C" void __fastcall _System__LStrFromPWCharLen();
#endif

// @System@@CheckAutoResult$qqrl
// System::__linkproc__ __fastcall CheckAutoResult(long)
extern "C" void __fastcall _System__CheckAutoResult();

// @System@@DynArrayRelease$qqrpv
// System::__linkproc__ __fastcall DynArrayRelease(void *)
extern "C" void __fastcall _System__DynArrayRelease();

// @System@@DynArrayAddRef$qqrpv
// System::__linkproc__ __fastcall DynArrayAddRef(void *)
extern "C" void __fastcall _System__DynArrayAddRef();

// @System@@AsgClosureObj$qqrr14System@TMethodpxvt2
// System::__linkproc__ __fastcall AsgClosureObj(System::TMethod&, const void *, const void *)
extern "C" void __fastcall _System__AsgClosureObj();

// @System@@ClosureAddWeakRef$qqrr14System@TMethod
// System::__linkproc__ __fastcall ClosureAddWeakRef(System::TMethod&)
extern "C" void __fastcall _System__ClosureAddWeakRef();

// @System@@ClosureArrayRemoveWeakRef$qqrr14System@TMethodi
// System::__linkproc__ __fastcall ClosureArrayRemoveWeakRef(System::TMethod&, int)
extern "C" void __fastcall _System__ClosureArrayRemoveWeakRef();

// @System@@ClosureRemoveWeakRef$qqrr14System@TMethod
// System::__linkproc__ __fastcall ClosureRemoveWeakRef(System::TMethod&)
extern "C" void __fastcall _System__ClosureRemoveWeakRef();

// @System@@CopyClosure$qqrr14System@TMethodrx14System@TMethod
// System::__linkproc__ __fastcall CopyClosure(System::TMethod&, System::TMethod&)
extern "C" void __fastcall _System__CopyClosure();

// @System@@InstAddRef$qqrxp14System@TObject
// System::__linkproc__ __fastcall InstAddRef(const System::TObject * const)
extern "C" void __fastcall _System__InstAddRef();

// @System@@InstClear$qqrrp14System@TObject
// System::__linkproc__ __fastcall InstClear(System::TObject *&)
extern "C" void __fastcall _System__InstClear();

// @System@@InstCopy$qqrrp14System@TObjectxp14System@TObject
// System::__linkproc__ __fastcall InstCopy(System::TObject *&, const System::TObject * const)
extern "C" void __fastcall _System__InstCopy();

// @System@@InstWeakArrayClear$qqrpvi
// System::__linkproc__ __fastcall InstWeakArrayClear(void *, int)
extern "C" void __fastcall _System__InstWeakArrayClear();

// @System@@InstWeakClear$qqrrp14System@TObject
// System::__linkproc__ __fastcall InstWeakClear(System::TObject *&)
extern "C" void __fastcall _System__InstWeakClear();

// @System@@InstWeakCopy$qqrrp14System@TObjectp14System@TObject
// System::__linkproc__ __fastcall InstWeakCopy(System::TObject *&, System::TObject *)
extern "C" void __fastcall _System__InstWeakCopy();

// @System@@IntfWeakArrayClear$qqrpvi
// System::__linkproc__ __fastcall IntfWeakArrayClear(void *, int)
extern "C" void __fastcall _System__IntfWeakArrayClear();

// @System@@IntfWeakClear$qqrr45System@%DelphiInterface$t17System@IInterface%
// System::__linkproc__ __fastcall IntfWeakClear(System::DelphiInterface<System::IInterface>&)
extern "C" void __fastcall _System__IntfWeakClear();

// @System@@IntfWeakCopy$qqrr45System@%DelphiInterface$t17System@IInterface%45System@%DelphiInterface$t17System@IInterface%
// System::__linkproc__ __fastcall IntfWeakCopy(System::DelphiInterface<System::IInterface>&, System::DelphiInterface<System::IInterface>)
extern "C" void __fastcall _System__IntfWeakCopy();

#endif

#endif
