
#include "stdafx.h"
#include "Math.h"
#include "combase.h"//定义了宏IMPLEMENT_NESTED_IUNKNOWN，该宏是我定义的宏，用来实现IUnkown接口的三个函数。

IMPLEMENT_DYNCREATE(CMath, CCmdTarget)

CMath::CMath()
{
	EnableAutomation();
	AfxOleLockApp();
}

CMath::~CMath()
{
	AfxOleUnlockApp();
}

void CMath::OnFinalRelease()
{
	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMath, CCmdTarget)
END_MESSAGE_MAP()

//该宏表示该类可以通过类工厂动态创建，与.h文件的DECLARE_OLECREATE相对应。
//参数2是该类的ProgID,参数3是该类的GUID
IMPLEMENT_OLECREATE(CMath, "DCOM.Math", 0xa919e2a, 0x964f, 0x4f05, 0x9b, 0x71, 0x40, 0x11, 0xa5, 0x4f, 0x6, 0x7d)

//该宏表示接口IFunction的IID可以映射到类CMath和嵌入类XInnerFunction指定的类成员上，与.h文件中的DECLARE_INTERFACE_MAP()相对应
//如果该类实现了多个接口，就需要实现多个潜入类，添加多个INTERFACE_PART宏
BEGIN_INTERFACE_MAP(CMath, CCmdTarget)
	INTERFACE_PART(CMath, IID_IFunction, CInnerFunction)
END_INTERFACE_MAP()

//该宏为自定义宏，实现了IUnknown三个函数
IMPLEMENT_NESTED_IUNKNOWN(CMath,CInnerFunction)

//自定义的函数，返回值为HRESULT
STDMETHODIMP
CMath::XCInnerFunction::showStr(CString name)
{
	METHOD_PROLOGUE(CMath,CInnerFunction)//必须添加这句
	AfxMessageBox(_T("THIS IS COM BY MFC"));
	return NOERROR;
}

CMath::XCInnerFunction::XCInnerFunction()
{
  METHOD_PROLOGUE(CMath,CInnerFunction)
  a=5;
}
CMath::XCInnerFunction::~XCInnerFunction()
{
  METHOD_PROLOGUE(CMath,CInnerFunction)
}
