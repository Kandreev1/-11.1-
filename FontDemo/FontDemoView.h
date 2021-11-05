
// FontDemoView.h: интерфейс класса CFontDemoView
//

#pragma once


class CFontDemoView : public CView
{
protected: // создать только из сериализации
	CFontDemoView() noexcept;
	DECLARE_DYNCREATE(CFontDemoView)

// Атрибуты
public:
	CFontDemoDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CFontDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в FontDemoView.cpp
inline CFontDemoDoc* CFontDemoView::GetDocument() const
   { return reinterpret_cast<CFontDemoDoc*>(m_pDocument); }
#endif

