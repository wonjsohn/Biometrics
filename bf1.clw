; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bf1.h"
LastPage=0

ClassCount=7
Class1=CBf1App
Class2=CBf1Doc
Class3=CBf1View
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_DIALOG_SETTINGS
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CSettingsDialog
Resource3=IDR_MAINFRAME
Class7=C1DCCSettings
Resource4=IDD_DIALOG_CCSETTINGS

[CLS:CBf1App]
Type=0
HeaderFile=bf1.h
ImplementationFile=bf1.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CBf1App

[CLS:CBf1Doc]
Type=0
HeaderFile=bf1Doc.h
ImplementationFile=bf1Doc.cpp
Filter=N

[CLS:CBf1View]
Type=0
HeaderFile=bf1View.h
ImplementationFile=bf1View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CBf1View


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_BF_STUDY
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=bf1.cpp
ImplementationFile=bf1.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_BF_STUDY
Command14=ID_CC_PRACTICE
Command15=ID_CC_STUDY1
Command16=ID_RC_PRACTICE
Command17=ID_RC_STUDY1
Command18=ID_SAMPLE_START
Command19=ID_SAMPLE_STOP
Command20=ID_MVC_RESET
Command21=ID_SETTINGS_DIALOG
Command22=ID_BF_OPEN
Command23=ID_BF_CLOSE
Command24=ID_BF_100
Command25=ID_BF_50
Command26=ID_BF_0
Command27=ID_BF_DRIVE_MEAN
Command28=ID_BF_DRIVE_BAYES
Command29=ID_CCSETTINGS_DIALOG
Command30=ID_APP_ABOUT
CommandCount=30

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG_SETTINGS]
Type=1
Class=CSettingsDialog
ControlCount=33
Control1=IDC_EMG_CHANNEL,edit,1350631554
Control2=IDC_EMG_SENS,edit,1350631554
Control3=IDC_EMG_PERIOD,edit,1350631554
Control4=IDC_BAYES_THRESH,edit,1350631554
Control5=IDC_BAYES_MAX,edit,1350631554
Control6=IDC_BAYES_DRIFT,edit,1350631554
Control7=IDC_BAYES_SWITCH,edit,1350631554
Control8=IDC_VIB_COM,edit,1350631554
Control9=IDC_VIB_BAY_MAX0,edit,1350631554
Control10=IDC_VIB_BAY_MIN100,edit,1350631554
Control11=IDC_VIB_MEAN_MAX0,edit,1350631554
Control12=IDC_VIB_MEAN_MIN100,edit,1350631554
Control13=IDOK,button,1342242817
Control14=IDCANCEL,button,1342242816
Control15=IDC_EMG_TITLE,static,1342177280
Control16=IDC_STATIC,static,1342177280
Control17=IDC_STATIC,static,1342177280
Control18=IDC_STATIC,static,1342177280
Control19=IDC_BAYES_TITLE,static,1342177280
Control20=IDC_STATIC,static,1342177280
Control21=IDC_STATIC,static,1342177280
Control22=IDC_STATIC,static,1342177280
Control23=IDC_STATIC,static,1342177280
Control24=IDC_VIB_TITLE,static,1342177280
Control25=IDC_STATIC,static,1342177280
Control26=IDC_STATIC,static,1342177280
Control27=IDC_STATIC,static,1342177280
Control28=IDC_VIB_TITLE2,static,1342177280
Control29=IDC_STATIC,static,1342177280
Control30=IDC_STATIC,static,1342177280
Control31=IDC_VIB_TITLE3,static,1342177280
Control32=IDC_VIB_MEAN_MVC,edit,1350631554
Control33=IDC_STATIC,static,1342177280

[CLS:CSettingsDialog]
Type=0
HeaderFile=SettingsDialog.h
ImplementationFile=SettingsDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CSettingsDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_CCSETTINGS]
Type=1
Class=C1DCCSettings
ControlCount=42
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EMG_SENS,edit,1350631554
Control4=IDC_EMG_PERIOD,edit,1350631554
Control5=IDC_BAYES_THRESH,edit,1350631554
Control6=IDC_BAYES_MAX,edit,1350631554
Control7=IDC_BAYES_DRIFT,edit,1350631554
Control8=IDC_BAYES_SWITCH,edit,1350631554
Control9=IDC_EMG_TITLE,static,1342177280
Control10=IDC_STATIC,static,1342177280
Control11=IDC_STATIC,static,1342177280
Control12=IDC_BAYES_TITLE,static,1342177280
Control13=IDC_STATIC,static,1342177280
Control14=IDC_STATIC,static,1342177280
Control15=IDC_STATIC,static,1342177280
Control16=IDC_STATIC,static,1342177280
Control17=IDC_STATIC,static,1342308352
Control18=IDC_BUTTON1,button,1342242816
Control19=IDC_RADIO1,button,1342308361
Control20=IDC_RADIO2,button,1342177289
Control21=IDC_RADIO3,button,1342177289
Control22=IDC_STATIC,button,1342177287
Control23=IDC_RADIO4,button,1342308361
Control24=IDC_RADIO5,button,1342177289
Control25=IDC_STATIC,button,1342177287
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_CC_STATDISPLAY,edit,1350631552
Control29=IDC_STATIC,static,1342308352
Control30=IDC_CC_STATREST,edit,1350631552
Control31=IDC_STATIC,static,1342308352
Control32=IDC_RADIO6,button,1342308361
Control33=IDC_RADIO7,button,1342177289
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_EDIT1,edit,1350631552
Control39=IDC_EDIT2,edit,1350631552
Control40=IDC_EDIT3,edit,1350631552
Control41=IDC_EDIT4,edit,1350631552
Control42=IDC_BUTTON2,button,1342242816

[CLS:C1DCCSettings]
Type=0
HeaderFile=1DCCSettings.h
ImplementationFile=1DCCSettings.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

