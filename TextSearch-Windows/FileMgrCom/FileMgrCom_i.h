

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Aug 23 15:46:27 2016
 */
/* Compiler settings for FileMgrCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FileMgrCom_i_h__
#define __FileMgrCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFileMgr_FWD_DEFINED__
#define __IFileMgr_FWD_DEFINED__
typedef interface IFileMgr IFileMgr;

#endif 	/* __IFileMgr_FWD_DEFINED__ */


#ifndef __FileMgr_FWD_DEFINED__
#define __FileMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileMgr FileMgr;
#else
typedef struct FileMgr FileMgr;
#endif /* __cplusplus */

#endif 	/* __FileMgr_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFileMgr_INTERFACE_DEFINED__
#define __IFileMgr_INTERFACE_DEFINED__

/* interface IFileMgr */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C97FBB34-48A6-4CEA-B53A-CD9B6C150B9F")
    IFileMgr : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SearchFile( 
            BSTR root,
            SAFEARRAY * files) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE get( 
            BSTR *filespec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getNumFiles( 
            LONG *num) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileMgr * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileMgr * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileMgr * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileMgr * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileMgr * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SearchFile )( 
            IFileMgr * This,
            BSTR root,
            SAFEARRAY * files);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *get )( 
            IFileMgr * This,
            BSTR *filespec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getNumFiles )( 
            IFileMgr * This,
            LONG *num);
        
        END_INTERFACE
    } IFileMgrVtbl;

    interface IFileMgr
    {
        CONST_VTBL struct IFileMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileMgr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileMgr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileMgr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileMgr_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileMgr_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileMgr_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileMgr_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileMgr_SearchFile(This,root,files)	\
    ( (This)->lpVtbl -> SearchFile(This,root,files) ) 

#define IFileMgr_get(This,filespec)	\
    ( (This)->lpVtbl -> get(This,filespec) ) 

#define IFileMgr_getNumFiles(This,num)	\
    ( (This)->lpVtbl -> getNumFiles(This,num) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileMgr_INTERFACE_DEFINED__ */



#ifndef __FileMgrComLib_LIBRARY_DEFINED__
#define __FileMgrComLib_LIBRARY_DEFINED__

/* library FileMgrComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FileMgrComLib;

EXTERN_C const CLSID CLSID_FileMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("BC25C535-C2D2-42F1-A379-734082F7B4B9")
FileMgr;
#endif
#endif /* __FileMgrComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


