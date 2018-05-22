//该文件实现IUnknown三个函数

#pragma once
typedef LPVOID*  PPVOID;
#define IMPLEMENT_NESTED_IUNKNOWN(outerclass, innerclass)				\
	STDMETHODIMP_(ULONG)												\
	outerclass::X##innerclass::AddRef()									\
	{																	\
		METHOD_PROLOGUE(outerclass, innerclass)							\
		return pThis->ExternalAddRef();									\
	}																	\
	STDMETHODIMP_(ULONG)												\
	outerclass::X##innerclass::Release()								\
	{																	\
		METHOD_PROLOGUE(outerclass, innerclass)							\
		return pThis->ExternalRelease();								\
	}																	\
	STDMETHODIMP														\
	outerclass::X##innerclass::QueryInterface(REFIID riid, PPVOID ppv)	\
	{																	\
		METHOD_PROLOGUE(outerclass, innerclass)							\
		return pThis->ExternalQueryInterface(&riid, ppv);				\
	}	
