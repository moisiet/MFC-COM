//该类是COM组件类，实现了IFunction接口
#pragma once
#include "IFunction.h"
#include "stdafx.h"//该头文件包含了MFC所定义的所有类和宏，若该文件中使用了MFC类和宏，必须包含该头文件

class CMath : public CCmdTarget
{
	DECLARE_DYNCREATE(CMath)

public:
	CMath();
	virtual ~CMath();
	virtual void OnFinalRelease();

//定义一个嵌套类CInnerFunction，用来实现IFunction接口
//CInnerFunction是CMath的嵌套类，继承自IFunction。
//宏BEGIN_INTERFACE_PART声明了IUnknown的三个函数（AddRef等，并将CInnerFunction更名为XCInnerFunction(在前面添加了符号X，易于理解）
//宏END_INTERFACE_PART则构建了一个XCInnerFunction对象，并将XCInnerFunction设为CMath的友元类。
//两个宏的意义就是：声明一个实现接口的类。
public:
	BEGIN_INTERFACE_PART(CInnerFunction,IFunction)
    public:
	XCInnerFunction();
	virtual ~XCInnerFunction();
    public:
	STDMETHOD(showStr)(CString name);//自定义的函数和变量定义在此处。
  int a;
	END_INTERFACE_PART(CInnerFunction)

protected:
  DECLARE_OLECREATE(CMath)//声明该类支持动态创建，并支持OLE,在.cpp文件中必须有相应的IMPLEMENT_OLECRATE宏
	DECLARE_MESSAGE_MAP()//声明消息映射，没有消息可以不要
	DECLARE_INTERFACE_MAP()//声明接口映射，与.cpp后面的BEGIN_INTERFACE_MAP和END_INTERFACE_MAP相对应。

};

