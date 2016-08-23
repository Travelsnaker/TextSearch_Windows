////////////////////////////////////////////////////////////////////////////////
//Test.cpp -    Used to test FileMgr component                                //
//                                                                            //
// Platform:    Lenovo Y470, Core i3, Windows 7 SP1                           //
// Application: CSE775 - Distributed Object Project 1, 2016                   //
// Author:      Wei Sun, Computer Engineering, Syracuse University            //
//              wsun13@syr.edu												  //
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "../FileMgrCom/FileMgrCom_i.h"
#include <iostream>
#include <atlsafe.h>
//----< FileMgr test stub >----
#ifdef TEST_FILEMGR
void test(IFileMgr*pFileMgr)
{
	std::cout << "\n Demonstrate file search" << std::endl;
	std::cout << "\n root=.., patterns={\"*.cpp\",\"*.h\"}" << std::endl;
	CComSafeArray<BSTR>patterns;
	patterns.Add(L"*.h");
	patterns.Add(L"*.cpp");
	BSTR root = SysAllocString(L"..");
	pFileMgr->SearchFile(root, patterns.Detach());
	SysFreeString(root);
	LONG num = 0; 
	pFileMgr->getNumFiles(&num);
	std::cout << "\n Get " << num << " qulified filename" << std::endl;
	while (num != 0)
	{
		BSTR rtn = 0;
		pFileMgr->get(&rtn);
		std::wcout << "Qualified filename: " << rtn << std::endl;
		--num;
		SysFreeString(rtn);
	}
}
int main()
{
	std::cout << "\n Demonstrate FileMgrCom " << std::endl;
	IFileMgr*pFileMgr;
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (!SUCCEEDED(hr))
	{
		std::wcout << L"\n  could not initialize COM\n\n";
		return 1;
	}
	CoCreateInstance(CLSID_FileMgr, NULL, CLSCTX_INPROC_SERVER, IID_IFileMgr, (void**)&pFileMgr);
	test(pFileMgr);
	pFileMgr->Release();
	CoUninitialize();
	system("pause");
	return 0;
}
#endif