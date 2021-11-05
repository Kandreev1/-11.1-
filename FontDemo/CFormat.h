#pragma once


// Диалоговое окно CFormat
enum { JUSTIFY_LEFT, JUSTIFY_CENTER, JUSTIFY_RIGHT };
enum { PITCH_VARIABLE, PITCH_FIXED };

class CFormat : public CDialog
{
	DECLARE_DYNAMIC(CFormat)
protected:
	RECT m_RectSample;

public:
	CFormat(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CFormat();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FORMAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Bold;
	BOOL m_Italic;
	BOOL m_Underline;
	int m_Justify;
	int m_Pitch;
	int m_Spacing;
	CEdit m_SpacingEdit;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBold();
	afx_msg void OnBnClickedItalic();
	afx_msg void OnBnClickedUnderline();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedCenter();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedVariable();
	afx_msg void OnBnClickedFixed();
	afx_msg void OnEnChangeSpacing();
};
