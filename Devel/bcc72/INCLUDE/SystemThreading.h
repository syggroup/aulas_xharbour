// -----------------------------------------------------------------------------------
// SystemThreading.h C++ Declarations for the System.Threading unit
//
// $Rev: 84441 $
//
// Copyright(c) 2012 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------------

#ifndef SystemThreading_H
#define SystemThreading_H

#if !defined(System_ThreadingHPP)
#error Do not include this file directly. Include 'System.Threading.hpp'.
#endif

#include <assert.h>

namespace System {
namespace Threading {

template <typename T> class __declspec(delphiclass) TFuture__1;

#ifndef __clang__
#define override
#endif

template <typename T>
class TFutureBase : public TTask {
public:
  typedef TTask::TCreateFlags TCreateFlags;

protected:
  __fastcall TFutureBase() : FResult() {}

#if defined(__clang__)
  typedef TFunctionEvent__1<T> EventType;
#else
  typedef T __fastcall (__closure *EventType)(System::TObject* Sender);
#endif

  __fastcall TFutureBase(
      System::TObject* Sender,
      const System::Classes::TNotifyEvent& Event,
      const System::Sysutils::_di_TProc& AProc,
      TThreadPool* const APool,
      TTask* const AParent,
      TTask::TCreateFlags CreateFlags)
        : TTask(Sender, Event, AProc, APool, AParent, CreateFlags),
          FResult() {}

  __fastcall TFutureBase(
      System::TObject* Sender,
      const EventType& Event,
      const System::DelphiInterface<System::Sysutils::TFunc__1<T> >& Func,
      TThreadPool* APool)
        : TTask(Sender, &RunEvent, 0, APool, 0, TTask::TCreateFlags()),
          FEvent(Event),
          FFunc(Func),
          FResult() {}

  void __fastcall RunEvent(System::TObject* Sender) {
    if (FEvent) {
      FResult = FEvent(Sender);
    } else if (FFunc) {
      FResult = FFunc->Invoke();
    }
  }

  EventType FEvent;
  System::DelphiInterface<System::Sysutils::TFunc__1<T> > FFunc;

protected:
  T FResult;
};

template <typename T>
class TFuture__1 : public TFutureBase<T>, public IFuture__1<T> {
#if defined(__clang__)
  typedef TFunctionEvent__1<T> EventType;
 #if   defined(_PLAT_IOS32) || defined(_PLAT_ANDROID)
  typedef unsigned UnsignedTimeoutArgType;
  typedef const System::Timespan::TTimeSpan& TimespanTimeoutArgType;
 #elif defined(_PLAT_IOS64)
  typedef unsigned long UnsignedTimeoutArgType;
  typedef const System::Timespan::TTimeSpan& TimespanTimeoutArgType;
 #elif defined(_WIN64)
  typedef unsigned UnsignedTimeoutArgType;
  typedef const System::Timespan::TTimeSpan TimespanTimeoutArgType;
 #elif defined(_WIN32)
  typedef unsigned UnsignedTimeoutArgType;
  typedef const System::Timespan::TTimeSpan& TimespanTimeoutArgType;
 #endif
#else
  typedef T __fastcall (__closure *EventType)(System::TObject* Sender);
  typedef const System::Timespan::TTimeSpan& TimespanTimeoutArgType;
  typedef unsigned UnsignedTimeoutArgType;
#endif

public:
  operator IFuture__1<T>*() { return this; }

  virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void ** ppvObject) override {
    return TTask::QueryInterface(riid, ppvObject);
  }

  virtual ULONG STDMETHODCALLTYPE AddRef() override {
    return TTask::_AddRef();
  }

  virtual ULONG STDMETHODCALLTYPE Release() override {
    return TTask::_Release();
  }

  virtual bool __fastcall ShouldExecute() override {
    return TTask::ShouldExecute();
  }

  virtual void __fastcall ExecuteWork() override {
    TTask::ExecuteWork();
  }

  virtual bool __fastcall Wait(UnsignedTimeoutArgType Timeout = static_cast<UnsignedTimeoutArgType>(~0u)) override {
    return TTask::Wait();
  }

  virtual bool __fastcall Wait(TimespanTimeoutArgType Timeout) override {
    return TTask::Wait(Timeout);
  }

  virtual void __fastcall Cancel() override {
    TTask::Cancel();
  }

  virtual void __fastcall CheckCanceled() override {
    TTask::CheckCanceled();
  }

  virtual _di_ITask __fastcall Start() override {
    assert(this->RefCount != 0);  // May behave strangely if RefCount == 0
    return TTask::Start();
  }

  virtual TTaskStatus __fastcall GetStatus() override {
    return TTask::GetStatus();
  }

  virtual int __fastcall GetId() override {
    return TTask::GetId();
  }

  virtual System::DelphiInterface<IFuture__1<T> > __fastcall StartFuture() override {
    assert(this->RefCount != 0);  // May behave strangely if RefCount == 0
    TTask::Start();
    return this;
  }

  virtual T __fastcall GetValue() override {
    Wait();
    return this->FResult;
  }

protected:
  TFuture__1() {}

  __fastcall TFuture__1(
      System::TObject* Sender,
      const System::Classes::TNotifyEvent& Event,
      const System::Sysutils::_di_TProc& AProc,
      TThreadPool* const APool,
      TTask* const AParent,
      typename TFutureBase<T>::TCreateFlags CreateFlags)
        : TFutureBase<T>(Sender, Event, AProc, APool, AParent, CreateFlags) {}

  __fastcall TFuture__1(
      System::TObject* Sender,
      const EventType& Event,
      const System::DelphiInterface<System::Sysutils::TFunc__1<T> >& Func,
      TThreadPool* APool)
        : TFutureBase<T>(Sender, Event, Func, APool) {}

  friend class TTask;
};

#if !defined(__clang__)
template <typename T>
inline System::DelphiInterface<IFuture__1<T> > __fastcall TTask::Future(
    System::TObject* Sender,
    T __fastcall (__closure *Event)(System::TObject* Sender))
{
  System::DelphiInterface<IFuture__1<T> > di(new TFuture__1<T>(
      Sender, Event, 0, TThreadPool::Default));
  return di->StartFuture();
}

template <typename T>
inline System::DelphiInterface<IFuture__1<T> > __fastcall TTask::Future(
    System::TObject* Sender,
    T __fastcall (__closure *Event)(System::TObject* Sender),
    TThreadPool* APool)
{
  System::DelphiInterface<IFuture__1<T> > di(new TFuture__1<T>(
      Sender, Event, 0, APool));
  return di->StartFuture();
}

#else

template <typename T>
inline System::DelphiInterface<IFuture__1<T> > __fastcall TTask::Future(
    System::TObject* Sender,
    TFunctionEvent__1<T> Event)
{
  System::DelphiInterface<IFuture__1<T> > di(new TFuture__1<T>(
      Sender, Event, nullptr, TThreadPool::Default));
  return di->StartFuture();
}

template <typename T>
inline System::DelphiInterface<IFuture__1<T> > __fastcall TTask::Future(
    System::TObject* Sender,
    TFunctionEvent__1<T> Event,
    TThreadPool* APool)
{
  System::DelphiInterface<IFuture__1<T> > di(new TFuture__1<T>(
      Sender, Event, nullptr, APool));
  return di->StartFuture();
}

#endif

template <typename T>
inline System::DelphiInterface<IFuture__1<T> > __fastcall TTask::Future(
    const System::DelphiInterface<System::Sysutils::TFunc__1<T> > Func)
{
  typename TFuture__1<T>::EventType type = 0;
  System::DelphiInterface<IFuture__1<T> > di(new TFuture__1<T>(
    0, type, Func, TThreadPool::Default));
  return di->StartFuture();
}

template <typename T>
inline System::DelphiInterface<IFuture__1<T> > __fastcall TTask::Future(
    const System::DelphiInterface<System::Sysutils::TFunc__1<T> > Func,
    TThreadPool* APool)
{
  typename TFuture__1<T>::EventType type = 0;
  System::DelphiInterface<IFuture__1<T> > di(new TFuture__1<T>(
      0, type, Func, APool));
  return di->StartFuture();
}

#ifndef __clang__
#undef override
#endif  // #ifndef __clang__

// Convenience aliases 
#ifdef __clang__
template <typename A1>
using TProc1 = System::Sysutils::_di_TProc__1<A1>;

template <typename A1, typename A2>
using TProc2 = System::Sysutils::_di_TProc__2<A1, A2>;

template <typename A1, typename A2, typename A3>
using TProc3 = System::Sysutils::_di_TProc__3<A1, A2, A3>;

template <typename A1, typename A2, typename A3, typename A4>
using TProc4 = System::Sysutils::_di_TProc__4<A1, A2, A3, A4>;

template <typename R>
using TFunc1 = System::Sysutils::_di_TFunc__1<R>;

template <typename A1, typename R>
using TFunc2 = System::Sysutils::_di_TFunc__2<A1, R>;

template <typename A1, typename A2, typename R>
using TFunc3 = System::Sysutils::_di_TFunc__3<A1, A2, R>;

template <typename A1, typename A2, typename A3, typename R>
using TFunc4 = System::Sysutils::_di_TFunc__4<A1, A2, A3, R>;

template <typename A1, typename A2, typename A3, typename A4, typename R>
using TFunc5 = System::Sysutils::_di_TFunc__5<A1, A2, A3, A4, R>;
#endif  // #ifdef __clang__
}  // namespace Threading
}  // namespace System

#endif  // SystemThreading_H
