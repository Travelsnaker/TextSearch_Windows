////////////////////////////////////////////////////////////////////////////////
//Test.cpp -    Used to test TextSearch component                             //
//                                                                            //
// Platform:    Lenovo Y470, Core i3, Windows 7 SP1                           //
// Application: CSE775 - Distributed Object Project 1, 2016                   //
// Author:      Wei Sun, Computer Engineering, Syracuse University            //
//              wsun13@syr.edu												  //
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "../TextSearchCom/TextSearchCom_i.h"
#include "../FileMgrCom/FileMgrCom_i.h"
#include <iostream>
#include <atlsafe.h>
#include <thread>
//-----< test stub >----
#ifdef TEST_TEXTSEARCH
void test(ITextSearch*pText,IFileMgr*pFileMgr)
{
	std::cout << "\n Demonstrate text search" << std::endl;
	std::cout << "\n Display all the file that root=.., patterns={\"*.cpp\",\"*.h\"}" << std::endl;
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
		pText->enqueue(rtn);
		--num;
		SysFreeString(rtn);
	}
}

void test2(ITextSearch*pText)
{
	std::cout << "\n Set number of threads to 4, searching string is \"main\"" << std::endl;
	BSTR text = SysAllocString(L"main");
	pText->setupSearch(4, text);
	pText->startSearch();
	LONG num = 0;
	pText->getNumRes(&num);
	std::cout << "Files that contains specified string: " << std::endl;
	while (num!=0)
	{
		BSTR res = 0;
		pText->get(&res);
		std::wcout << "Text search result: " << res<<std::endl;
		pText->getNumRes(&num);
	}
}
int main()
{
	std::cout << "\n Demonstrate TextSearch component" << std::endl;
	IFileMgr*pFileMgr;
	ITextSearch*pText;
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	CoCreateInstance(CLSID_FileMgr, NULL, CLSCTX_INPROC_SERVER, IID_IFileMgr, (void**)&pFileMgr);
	CoCreateInstance(CLSID_TextSearch, NULL, CLSCTX_INPROC_SERVER, IID_ITextSearch, (void**)&pText);
	test(pText, pFileMgr);
	test2(pText);
	pFileMgr->Release();
	pText->Release();
	CoUninitialize();
	system("pause");
	return 0;
}
#endif