﻿
// MainFrameDlg.h: 头文件
//
#include "WBrowser.h"
#include "WEnergy.h"

#pragma once


// CMainFrameDlg 对话框
class CMainFrameDlg : public CDialogEx
{
// 构造
public:
	CMainFrameDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINFRAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
    WBrowser m_brw;
    WEnergy m_egy;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
