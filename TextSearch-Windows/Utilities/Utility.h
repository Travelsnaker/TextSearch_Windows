#pragma once
////////////////////////////////////////////////////////////////////////////////
// Utility.h -  Provides functions which convert BSTR to std::string and vice //
//              versa.                                                        //
//                                                                            //
// Platform:    Lenovo Y470, Core i3, Windows 7 SP1                           //
// Application: CSE775 - Distributed Object Project 1, 2016                   //
// Author:      Wei Sun, Computer Engineering, Syracuse University            //
//              wsun13@syr.edu												  //
////////////////////////////////////////////////////////////////////////////////
/*
*  Package Operation:
*  ===================
*  This package provides class Utilities. It provides functions that convert BSTR
*  to std::string and std::string to BSTR.
*
*  Public Interface:
*  ===================
*  static std::string ConvertBSTRToMBS(BSTR bstr);
*  static std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);
*  static BSTR ConvertMBSToBSTR(const std::string& str);
*   
*  Required File:
*  ===================
*  Utility.h, Utility.cpp
*
*  Build Command
*  ===================
*  cl /EHa /DUTILITY_TEST Utility.cpp
*
*  Maintenance History:
*  ===================
*  Ver 1.0 : 16 Mar 6
*  - first release
*/
#include <wtypes.h>
#include<string>
class Utilities
{
public:
	static std::string ConvertBSTRToMBS(BSTR bstr);
	static std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);
	static BSTR ConvertMBSToBSTR(const std::string& str);
};
