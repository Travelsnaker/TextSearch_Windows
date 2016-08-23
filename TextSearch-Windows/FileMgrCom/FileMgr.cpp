////////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp -Provides functions which search files residing in a directory //
//	            root at specified path and matching one or more patterns.     //
//                                                                            //
// Platform:    Lenovo Y470, Core i3, Windows 7 SP1                           //
// Application: CSE775 - Distributed Object Project 1, 2016                   //
// Author:      Wei Sun, Computer Engineering, Syracuse University            //
//              wsun13@syr.edu												  //
////////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp : Implementation of CFileMgr

#include "stdafx.h"
#include "FileMgr.h"

#include "../Utilities/Utility.h"


// CFileMgr


//----< Search files according to given root directory and one or more patterns >-----
STDMETHODIMP CFileMgr::SearchFile(BSTR root, SAFEARRAY*patterns)
{
	// TODO: Add your implementation code here
	string root_ = Utilities::ConvertBSTRToMBS(root);
	if (!searchFile(root_, patterns)) {
		return S_FALSE;
	}
	return S_OK;
}
//-----< Help function of SearchFile(BSTR root, SAFEARRAY*patterns) >---- 
bool CFileMgr::searchFile(std::string&root, SAFEARRAY*patterns)
{
	FileInfo fn(root);
	CComSafeArray<BSTR> patterns_(patterns);
	if (fn.isDirectory())
	{
		if (patterns_.GetCount() == 0)
			return false;
		std::vector<std::string>currFiles;
		std::string pattern;
		for (size_t i = 0; i < patterns_.GetCount(); ++i)
		{
			pattern= Utilities::ConvertBSTRToMBS(patterns_.GetAt(i));
			vector<string>currFilesTemp = Directory::getFiles(root,pattern);
			currFiles.insert(currFiles.end(), currFilesTemp.begin(), currFilesTemp.end());
		}
		for (size_t i = 0; i < currFiles.size(); ++i) {
			++numOfFiles;
			store.enQ(root + "/" + currFiles[i]);
		}
		std::vector<std::string>currDirs = Directory::getDirectories(root);
		for (size_t i = 0; i < currDirs.size(); ++i)
			if (currDirs[i] != "." && currDirs[i] != "..")
				searchFile(root + "/" + currDirs[i], patterns);
		return true;
	}
	else
		return false;
}
//----< Get filename of search result >-----
STDMETHODIMP CFileMgr::get(BSTR* filespec)
{
	// TODO: Add your implementation code here
	BSTR file = Utilities::ConvertMBSToBSTR(store.deQ());
	*filespec = file;
	return S_OK;
}

//-----< Get the number of results >----- 
STDMETHODIMP CFileMgr::getNumFiles(LONG* num)
{
	// TODO: Add your implementation code here
	*num = numOfFiles;
	return S_OK;
}
