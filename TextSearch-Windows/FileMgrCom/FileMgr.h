////////////////////////////////////////////////////////////////////////////////
// FileMgr.h -  Provides functions which search files residing in a directory //
//	            root at specified path and matching one or more patterns.     //
//                                                                            //
// Platform:    Lenovo Y470, Core i3, Windows 7 SP1                           //
// Application: CSE775 - Distributed Object Project 1, 2016                   //
// Author:      Wei Sun, Computer Engineering, Syracuse University            //
//              wsun13@syr.edu												  //
////////////////////////////////////////////////////////////////////////////////
// FileMgr.h : Declaration of the CFileMgr
/*
*  Operations:
*  ===================
*  Provides class CFileMgr which implements the interface. 
*  Provides functions which search files residing in a directory 
*  root at specified path and matching one or more patterns.
*
*  Public Interface:
*  ===================
*  HRESULT SearchFile(BSTR root, SAFEARRAY(BSTR)files); 
*  HRESULT get(BSTR* filespec);		//Get search results.
*  HRESULT getNumFiles(LONG* num);  //Get the number of results.
*
*  Required files:
*  ===================
*  FileMgr.h, FileMgr.cpp, Cpp11-BlockingQueue.h, Cpp11-BlockingQueue.cpp
*  FileSystem.h,FileSystem.cpp, Utility.h, Utility.cpp
*	
*  Maintenance History:
*  ===================
*  Ver 1.0 : 16 Mar 6
*  - first release
*
*/
#pragma once
#include "resource.h"       // main symbols



#include "FileMgrCom_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif
#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"
#include "../FileSystem/FileSystem.h"
#include <vector>
#include <atlsafe.h>
using namespace ATL;
using namespace FileSystem;
using namespace std;
// CFileMgr

class ATL_NO_VTABLE CFileMgr :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFileMgr, &CLSID_FileMgr>,
	public IDispatchImpl<IFileMgr, &IID_IFileMgr, &LIBID_FileMgrComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFileMgr()
	{
		numOfFiles = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FILEMGR)

DECLARE_NOT_AGGREGATABLE(CFileMgr)

BEGIN_COM_MAP(CFileMgr)
	COM_INTERFACE_ENTRY(IFileMgr)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(SearchFile)(BSTR root, SAFEARRAY*patterns);
	STDMETHOD(get)(BSTR* filespec);
	STDMETHOD(getNumFiles)(LONG* num);
private:
	BlockingQueue<string>store;
	long numOfFiles;
	bool searchFile(std::string&root, SAFEARRAY*patterns);	
};

OBJECT_ENTRY_AUTO(__uuidof(FileMgr), CFileMgr)
