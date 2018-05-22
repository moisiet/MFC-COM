//该文件为调用COM组件部分代码
//调用时将生成的COM dll放在调用程序当前目录下，然后导入接口头文件就可以使用了。

#include "IFunction.h"

CString dllPath(_T("C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\M\\x64\\Debug\\DCOM.dll"));//注意是双\\
	HINSTANCE hModule = LoadLibrary(dllPath);
	if (hModule==NULL)
	{
		AfxMessageBox(_T("DLL Load Failed"));
		return FALSE;
	}
	FARPROC pFunc = ::GetProcAddress(hModule, "DllRegisterServer");//类型为FARPROC
	if (pFunc==NULL)
	{
		AfxMessageBox(_T("Register Failed"));
		return FALSE;
	}
	(*pFunc)();//注册成功

	IFunction* pFuncs;
	GUID clsGuid;
  CoInitialize(NULL);//初始化COM环境，也可以在App文件中调用AfxOleInit()
	CLSIDFromString(_T("DCOM.Math"), &clsGuid);//通过CMath的ProgID获得它的GUID
	HRESULT hResult = CoCreateInstance(clsGuid, NULL, CLSCTX_INPROC_SERVER,IID_IFunction,(LPVOID*)&pFuncs);
	pFuncs->showStr(_T("this is successful"));
	pFuncs->Release();
  CoUniinitialize();
  
  //以下为扩展，不是该部分内容：
  往往情况是，我们很难记住COM类的ProgID,更别说它的GUID了，那么我们将GUID值以字符串的形式保存在dll的字符串变量中，然后调用
  ：：LoadString(hDll,IDS_GUID,(lPTSTR)achData,1024)读出该guid值，然后CLSIDFromString就可以了。
  同时也可以保存图片资源，利用：
  hIcon=::LoadIcon(hDll,MAKEINTRESOURCE(ID_ICON))获取图片句柄。
