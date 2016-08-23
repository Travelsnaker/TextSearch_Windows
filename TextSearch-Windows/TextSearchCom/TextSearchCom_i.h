

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Aug 23 15:46:27 2016
 */
/* Compiler settings for TextSearchCom.idl:
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

#ifndef __TextSearchCom_i_h__
#define __TextSearchCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITextSearch_FWD_DEFINED__
#define __ITextSearch_FWD_DEFINED__
typedef interface ITextSearch ITextSearch;

#endif 	/* __ITextSearch_FWD_DEFINED__ */


#ifndef __TextSearch_FWD_DEFINED__
#define __TextSearch_FWD_DEFINED__

#ifdef __cplusplus
typedef class TextSearch TextSearch;
#else
typedef struct TextSearch TextSearch;
#endif /* __cplusplus */

#endif 	/* __TextSearch_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITextSearch_INTERFACE_DEFINED__
#define __ITextSearch_INTERFACE_DEFINED__

/* interface ITextSearch */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITextSearch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D7AB63B-53D2-418C-8401-8DCD4606A724")
    ITextSearch : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE enqueue( 
            BSTR filename) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setupSearch( 
            LONG num,
            BSTR text) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE startSearch( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE get( 
            BSTR *filename) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE stopSearch( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getNumRes( 
            LONG *num) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITextSearchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITextSearch * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITextSearch * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITextSearch * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITextSearch * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITextSearch * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITextSearch * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITextSearch * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *enqueue )( 
            ITextSearch * This,
            BSTR filename);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setupSearch )( 
            ITextSearch * This,
            LONG num,
            BSTR text);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *startSearch )( 
            ITextSearch * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *get )( 
            ITextSearch * This,
            BSTR *filename);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *stopSearch )( 
            ITextSearch * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getNumRes )( 
            ITextSearch * This,
            LONG *num);
        
        END_INTERFACE
    } ITextSearchVtbl;

    interface ITextSearch
    {
        CONST_VTBL struct ITextSearchVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITextSearch_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITextSearch_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITextSearch_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITextSearch_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITextSearch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITextSearch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITextSearch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITextSearch_enqueue(This,filename)	\
    ( (This)->lpVtbl -> enqueue(This,filename) ) 

#define ITextSearch_setupSearch(This,num,text)	\
    ( (This)->lpVtbl -> setupSearch(This,num,text) ) 

#define ITextSearch_startSearch(This)	\
    ( (This)->lpVtbl -> startSearch(This) ) 

#define ITextSearch_get(This,filename)	\
    ( (This)->lpVtbl -> get(This,filename) ) 

#define ITextSearch_stopSearch(This)	\
    ( (This)->lpVtbl -> stopSearch(This) ) 

#define ITextSearch_getNumRes(This,num)	\
    ( (This)->lpVtbl -> getNumRes(This,num) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITextSearch_INTERFACE_DEFINED__ */



#ifndef __TextSearchComLib_LIBRARY_DEFINED__
#define __TextSearchComLib_LIBRARY_DEFINED__

/* library TextSearchComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_TextSearchComLib;

EXTERN_C const CLSID CLSID_TextSearch;

#ifdef __cplusplus

class DECLSPEC_UUID("9CCEFC9A-7DDC-4A01-87C3-F12C08FB97A2")
TextSearch;
#endif
#endif /* __TextSearchComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


