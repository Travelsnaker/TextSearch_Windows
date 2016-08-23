// dllmain.h : Declaration of module class.

class CTextSearchModule : public ATL::CAtlDllModuleT< CTextSearchModule >
{
public :
	DECLARE_LIBID(LIBID_TextSearchLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEXTSEARCH, "{8FB53F51-3798-4F85-8469-96CE7676C325}")
};

extern class CTextSearchModule _AtlModule;
