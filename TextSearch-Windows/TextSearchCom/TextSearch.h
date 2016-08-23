#pragma once
///////////////////////////////////////////////////////////////
//  TextSearch.h - Implementation of TextSearch Interface    //
//                                                           //
//  Platform:     Lenovo Y470, Core i3, Windows 7 SP1        //
//  Application:  Demonstration for CSE775 - Distrib. Objs   //
//  Authors:      Wei Sun, Computer Engineering,Syracuse Univ//
//                wsun13@syr.edu                             //
///////////////////////////////////////////////////////////////
// TextSearch.h : Declaration of the CTextSearch


#include "resource.h"       // main symbols



#include "TextSearchCom_i.h"

#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"
#include "../FileSystem/FileSystem.h"
#include "../Utilities/Utility.h"
#include <string>
#include <thread>
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace std;

// CTextSearch

class ATL_NO_VTABLE CTextSearch :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTextSearch, &CLSID_TextSearch>,
	public IDispatchImpl<ITextSearch, &IID_ITextSearch, &LIBID_TextSearchComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTextSearch()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TEXTSEARCH)

DECLARE_NOT_AGGREGATABLE(CTextSearch)

BEGIN_COM_MAP(CTextSearch)
	COM_INTERFACE_ENTRY(ITextSearch)
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
	STDMETHOD(enqueue)(BSTR filename);
	STDMETHOD(setupSearch)(LONG num, BSTR text);
	STDMETHOD(startSearch)();
	STDMETHOD(get)(BSTR* filename);
	STDMETHOD(stopSearch)();
	STDMETHOD(getNumRes)(LONG* num);
private:
	BlockingQueue<string>store;
	BlockingQueue<string>result;
	bool TxtSearch(const std::string&filespec, const std::string&TargetText);
	void textSearch(string text);
	bool _stop = false;
	vector<thread>threads;
	
};

OBJECT_ENTRY_AUTO(__uuidof(TextSearch), CTextSearch)
