// dllmain.h : Declaration of module class.

class CFileMgrComModule : public ATL::CAtlDllModuleT< CFileMgrComModule >
{
public :
	DECLARE_LIBID(LIBID_FileMgrComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FILEMGRCOM, "{3F94E004-B3FF-4C75-AEF6-B4D1507C090E}")
};

extern class CFileMgrComModule _AtlModule;
