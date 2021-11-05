
// FontDemoDoc.h: интерфейс класса CFontDemoDoc 
//


#pragma once


class CFontDemoDoc : public CDocument
{
public:
	BOOL m_Bold;
	BOOL m_Italic;
	int m_Justify;
	int m_Pitch;
	int m_Spacing;
	BOOL m_Underline;

protected: // создать только из сериализации
	CFontDemoDoc() noexcept;
	DECLARE_DYNCREATE(CFontDemoDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CFontDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnTextFormat();
};
