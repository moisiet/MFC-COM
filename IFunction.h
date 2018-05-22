#pragma once
#include "afxtempl.h"//包含该头文件原因是其内部定义了宏DECLARE_INTERFACE_
static const IID IID_IFunction={ 0x520ed996, 0xf1bc, 0x4263,{ 0xb7, 0xa1, 0x3e, 0x10, 0x49, 0x91, 0x48, 0x79 } };//为接口定义GUID
DECLARE_INTERFACE_(IFunction, IUnknown)//定义接口IFunction
{
	STDMETHOD(showStr)(CString name);
};
