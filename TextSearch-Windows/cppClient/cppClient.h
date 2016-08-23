#pragma once
///////////////////////////////////////////////////////////////
//  cppClient.h - Build a console application that search all//
//                the files that contain a specified string //
//                                                           //
//  Platform:     Lenovo Y470, Core i3, Windows 7 SP1        //
//  Application:  Demonstration for CSE775 - Distrib. Objs   //
//  Authors:      Wei Sun, Computer Engineering,Syracuse Univ//
//                wsun13@syr.edu                             //
///////////////////////////////////////////////////////////////
/*
*  Package Operation:
*  ===================
*  Provide class cppClient. It uses FileMgr and TextSearch component
*  to search all the files that contain a specified string given a root
*  directory.
*
*  Public Interface:
*  ===================
*  cppClient();
*  ~cppClient();
*  void setupSearch(const std::string&root,
*                   const std::string&text,
*                   int numOfThreads,
*                   std::vector<std::string>&patterns,
*                   long long time=3);
*  std::vector<std::string>patterns={"*.cpp","*.h"};
*  setupSearch("D:/Graduate","main",4,patterns);
*  void startSearch();
*  void stopSearch();
*
*  Required Files
*  ===================
*  cppClient.h, cppClient.cpp, targetver.h, stdafx.h, stafx.cpp, Utiltiy.h, Utility.cpp
*  FileMgrCom_i.c, TextSearch_i.c
*
*  Build Command:
*  ===================
*  devenv TextSearch.sln /rebuild debug
*
*  Maintenance History:
*  ===================
*  Ver 1.0 : 15 Feb 6
*  - first release
*/
#include "stdafx.h"
#include "../FileMgrCom/FileMgrCom_i.h"
#include "../TextSearchCom/TextSearchCom_i.h"
#include <iostream>
#include <atlsafe.h>
#include <vector>
#include <thread>
#include <mutex>
#include "../Utilities/Utility.h"
class cppClient
{
public:
	cppClient();
	~cppClient();
	void setupSearch(const std::string&root,const std::string&text,int numOfThreads,std::vector<std::string>&patterns,long long time=1);
	void startSearch();
	void stopSearch();
private:
	IFileMgr*pFileMgr;
	ITextSearch*pText;
	BSTR root;
	BSTR text;
	int numOfThreads;
	CComSafeArray<BSTR>patterns;
	long numOfFiles;
	bool stop;
	long long timeLimit;
};