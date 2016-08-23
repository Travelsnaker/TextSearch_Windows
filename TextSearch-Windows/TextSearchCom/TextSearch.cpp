///////////////////////////////////////////////////////////////
//  TextSearch.cpp - Implementation of TextSearch Interface  //
//                                                           //
//  Platform:     Lenovo Y470, Core i3, Windows 7 SP1        //
//  Application:  Demonstration for CSE775 - Distrib. Objs   //
//  Authors:      Wei Sun, Computer Engineering,Syracuse Univ//
//                wsun13@syr.edu                             //
///////////////////////////////////////////////////////////////
// TextSearch.cpp : Implementation of CTextSearch

#include "stdafx.h"
#include "TextSearch.h"

// CTextSearch


//-----< enqueue the fully specified file name for text search >-----
STDMETHODIMP CTextSearch::enqueue(BSTR filename)
{
	// TODO: Add your implementation code here
	string _filename = Utilities::ConvertBSTRToMBS(filename);
 	store.enQ(_filename);
	return S_OK;
}
//-----< Specify the number of threads and target text>-----
STDMETHODIMP CTextSearch::setupSearch(LONG num,BSTR text)
{
	// TODO: Add your implementation code here
	_stop = false;
	string txt = Utilities::ConvertBSTRToMBS(text);
	for (int i = 0; i <num; ++i)
	{
		threads.push_back(thread(&CTextSearch::textSearch, this, txt));
	}
	return S_OK;
}

//-----< Start asychronously text search >-----
STDMETHODIMP CTextSearch::startSearch()
{
	// TODO: Add your implementation code here	
	for (auto& t : threads)
		t.detach();
	return S_OK;
}
//-----< Search target text in a single file >-----
bool CTextSearch::TxtSearch(const std::string&file, const std::string&TargetText)
{
	std::ostringstream temp;
	std::ifstream in(file);
	if (in.good())
	{
		temp << in.rdbuf();
		std::string& contents = temp.str();
		size_t pos = contents.find(TargetText);
		if (pos != std::string::npos)
			return true;
	}
	return false;
}
//----< Search text >----
void CTextSearch::textSearch(string txt)
{
	while (true)
	{
		if (_stop)
			break;
		string filename = store.deQ();
		if (TxtSearch(filename, txt))
		{
			result.enQ(filename);
		}		
	}
}

//----< get search results >----
STDMETHODIMP CTextSearch::get(BSTR* filename)
{
	// TODO: Add your implementation code here
	string file = result.deQ();
	BSTR _file = Utilities::ConvertMBSToBSTR(file);
	*filename = _file;
	SysFreeString(_file);
	return S_OK;
}

//----< stop asychronous search >----
STDMETHODIMP CTextSearch::stopSearch()
{
	// TODO: Add your implementation code here
	_stop = true;
	return S_OK;
}

//----< Get the number of searching results >-----
STDMETHODIMP CTextSearch::getNumRes(LONG* num)
{
	// TODO: Add your implementation code here
	*num = result.size();
	return S_OK;
}

