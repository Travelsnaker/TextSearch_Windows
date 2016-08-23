///////////////////////////////////////////////////////////////
//  cppClient.cpp - Build a console application that search all//
//                the files that contain a specified string //
//                                                           //
//  Platform:     Lenovo Y470, Core i3, Windows 7 SP1        //
//  Application:  Demonstration for CSE775 - Distrib. Objs   //
//  Authors:      Wei Sun, Computer Engineering,Syracuse Univ//
//                wsun13@syr.edu                             //
///////////////////////////////////////////////////////////////
#include "cppClient.h"
#include "stdafx.h"
#include "../FileMgrCom/FileMgrCom_i.h"
#include "../TextSearchCom/TextSearchCom_i.h"
#include <iostream>
#include <atlsafe.h>
#include <thread>
//-----< Default constructor of cppClient >----
cppClient::cppClient()
{
	HRESULT hr= CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (!SUCCEEDED(hr))
	{
		std::wcout << L"\n  could not initialize COM\n\n";
		return;
	}
	CoCreateInstance(CLSID_FileMgr, NULL, CLSCTX_INPROC_SERVER, IID_IFileMgr, (void**)&pFileMgr);
	CoCreateInstance(CLSID_TextSearch, NULL, CLSCTX_INPROC_SERVER, IID_ITextSearch, (void**)&pText);
}
//-----< destructor >-----
cppClient::~cppClient()
{
	pFileMgr->Release();
	pText->Release();
	CoUninitialize();
}
//----< set up all the search parameters >----
void cppClient::setupSearch(const std::string&_root, const std::string&_text, int _numOfThreads, std::vector<std::string>&_patterns,long long time)
{
	if (pFileMgr != 0 && pText != 0)
	{
		timeLimit = time;
		stop = false;
		root = Utilities::ConvertMBSToBSTR(_root);
		text = Utilities::ConvertMBSToBSTR(_text);
		for (size_t i = 0; i < _patterns.size(); ++i)
		{
			BSTR pattern = Utilities::ConvertMBSToBSTR(_patterns[i]);
			patterns.Add(pattern);
			SysFreeString(pattern);
		}
		numOfThreads = _numOfThreads;
		std::wcout << L"\n Root=" << root << L" Text=" << text << L" NumOfthreads=" << numOfThreads << std::endl;
	}
}
//----< start asychronous text search >-----
void cppClient::startSearch()
{
	if(pFileMgr != 0 && pText != 0)
	{
		std::thread t([&]() {
			pFileMgr->SearchFile(root, patterns.Detach());
			pText->setupSearch(numOfThreads, text);
			pText->startSearch();
			LONG num = 0;
			pFileMgr->getNumFiles(&num);
			std::cout << "\n Qualified files is: " << std::endl;
			while (num != 0)
			{
				BSTR rtn = 0;
				pFileMgr->get(&rtn);
				std::wcout << "Qulified file:" << rtn << std::endl;
				pText->enqueue(rtn);
				--num;
				SysFreeString(rtn);
			}
			std::wcout << L"\n File that contains string \"" <<text<<L"\""<< std::endl;
			while (true)
			{
				if (stop)
				{
					pText->stopSearch()	;
					break;
				}
				CComBSTR res;
				pText->get(&res);
				std::wcout << "Text search result: " << res.Detach() << std::endl;
			}});
		t.detach();
		std::this_thread::sleep_for(std::chrono::seconds(timeLimit));
	}
}
//----<stop search >----
void cppClient::stopSearch()
{
	stop = true;
}
// ---< test stub >-----
// ----< convert number from array of char to int >----
int toInt(char*ch)
{
	int res = 0;
	while (*ch != '\0')
	{
		res = 10 * res + (*ch - '0');
		++ch;
	}
	return res;
}
//----< main>-----
#ifdef TEST_CPPCLIENT
int main(int argc,char*argv[])
{
	std::cout << "\n Demonstrate parallel search component" << std::endl;
	std::cout << "\n The command line format is: [root] [SearchString] [Number of threads] \n[pattern1] [pattern2]...\n";
	if (argc < 5)
	{
		std::cout << "\n Lack of commandline arguments \n\n";
		return 1;
	}
	std::vector<std::string>patterns;
	for (int i = 4; i < argc; ++i)
		patterns.push_back(argv[i]);
	cppClient app;
	app.setupSearch(argv[1], argv[2], toInt(argv[3]), patterns,5);
	app.startSearch();	
	app.stopSearch();
	return 0;
}
#endif