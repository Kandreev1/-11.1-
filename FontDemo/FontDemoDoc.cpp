
// FontDemoDoc.cpp: реализация класса CFontDemoDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "FontDemo.h"
#endif

#include "FontDemoDoc.h"
#include "CFormat.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFontDemoDoc

IMPLEMENT_DYNCREATE(CFontDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CFontDemoDoc, CDocument)
	ON_COMMAND(ID_TEXT_FORMAT, &CFontDemoDoc::OnTextFormat)
END_MESSAGE_MAP()


// Создание или уничтожение CFontDemoDoc

CFontDemoDoc::CFontDemoDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора
	m_Bold = FALSE;
	m_Italic = FALSE;
	m_Justify = JUSTIFY_LEFT;
	m_Pitch = PITCH_VARIABLE;
	m_Spacing = 1;
	m_Underline = FALSE;

}

CFontDemoDoc::~CFontDemoDoc()
{
}

BOOL CFontDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CFontDemoDoc

void CFontDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CFontDemoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CFontDemoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CFontDemoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CFontDemoDoc

#ifdef _DEBUG
void CFontDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFontDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CFontDemoDoc


void CFontDemoDoc::OnTextFormat()
{
	// TODO: добавьте свой код обработчика команд
	// объявление объекта класса диалогового окна:
	CFormat FormatDlg;

	// инициализация переменных класса:
	FormatDlg.m_Bold = m_Bold;
	FormatDlg.m_Italic = m_Italic;
	FormatDlg.m_Justify = m_Justify;
	FormatDlg.m_Pitch = m_Pitch;
	FormatDlg.m_Spacing = m_Spacing;
	FormatDlg.m_Underline = m_Underline;
	// отображение диалогового окна:   
	if (FormatDlg.DoModal() == IDOK)
	{
		// сохранение установленных значений:
		m_Bold = FormatDlg.m_Bold;
		m_Italic = FormatDlg.m_Italic;
		m_Justify = FormatDlg.m_Justify;
		m_Pitch = FormatDlg.m_Pitch;
		m_Spacing = FormatDlg.m_Spacing;
		m_Underline = FormatDlg.m_Underline;

		// перерисовка текста:
		UpdateAllViews(NULL);
	}
}
