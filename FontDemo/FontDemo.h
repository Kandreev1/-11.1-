
// FontDemo.h: основной файл заголовка для приложения FontDemo
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CFontDemoApp:
// Сведения о реализации этого класса: FontDemo.cpp
//

class CFontDemoApp : public CWinApp
{
public:
	CFontDemoApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFontDemoApp theApp;
