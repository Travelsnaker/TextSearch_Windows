// dllmain.h : Declaration of module class.

class CTextSearchComModule : public ATL::CAtlDllModuleT< CTextSearchComModule >
{
public :
	DECLARE_LIBID(LIBID_TextSearchComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEXTSEARCHCOM, "{AFBC7427-6564-4503-8A7D-BC1E3FDE4D23}")
};

extern class CTextSearchComModule _AtlModule;
