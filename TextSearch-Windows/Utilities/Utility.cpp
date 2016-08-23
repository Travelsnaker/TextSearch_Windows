////////////////////////////////////////////////////////////////////////////////
// Utility.cpp- Provides functions which convert BSTR to std::string and vice //
//              versa.                                                        //
//                                                                            //
// Platform:    Lenovo Y470, Core i3, Windows 7 SP1                           //
// Application: CSE775 - Distributed Object Project 1, 2016                   //
// Author:      Wei Sun, Computer Engineering, Syracuse University            //
//              wsun13@syr.edu												  //
////////////////////////////////////////////////////////////////////////////////
#include"Utility.h"
#include<iostream>
//-----< Convert wide character to multibyte >-----
std::string Utilities::ConvertWCSToMBS(const wchar_t* pstr, long wslen)
{
	int len = ::WideCharToMultiByte(CP_ACP, 0, pstr, wslen, NULL, 0, NULL, NULL);
	std::string dblstr(len, '\0');
	len = ::WideCharToMultiByte(CP_ACP, 0,
		pstr, wslen,
		&dblstr[0], len,
		NULL, NULL);

	return dblstr;
}
//-----< Convert BSTR to string >-----
std::string Utilities::ConvertBSTRToMBS(BSTR bstr)
{
	int wslen = ::SysStringLen(bstr);
	return ConvertWCSToMBS((wchar_t*)bstr, wslen);
}
//----< Convert string to BSTR >-----
BSTR Utilities::ConvertMBSToBSTR(const std::string& str)
{
	int wslen = ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
		str.data(), str.length(),
		NULL, 0);
	BSTR wsdata = ::SysAllocStringLen(NULL, wslen);
	::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
		str.data(), str.length(),
		wsdata, wslen);
	return wsdata;
}
//-----< Test stub >----
#ifdef TEST_UTILITY
int main()
{
	std::cout << "\n Demonstrate BSTR convert to std::string";
	BSTR bstr = ::SysAllocString(L"This is a bstr");
	std::wcout << "\n BSTR is: " << bstr;
	std::string str = Utilities::ConvertBSTRToMBS(bstr);
	std::cout << "\n convert to string: " << str<<std::endl;

	std::cout << "\n Demonstrate std::string convert to BSTR";
	std::string str2 = "This is a string";
	std::cout << "\n The std::string is: " << str2;
	BSTR bstr2 = Utilities::ConvertMBSToBSTR(str2);
	std::wcout << "\n BSTR is: " << bstr2 << std::endl;
	system("pause");
	return 0;
}
#endif
