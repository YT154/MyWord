#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<mychildwnd.h>
#include<QMdiArea>
#include<QPrintDialog>
#include<QPrinter>
#include<QPrintPreviewDialog>
#include <QSignalMapper>
#include<QWidget>
#include<QFileInfo>
#include<QFileDialog>
#include<QTextDocumentWriter>
#include<QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyChildWnd;
class QMdiSubWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initMainWindow();//初始化
    void docNew();//新建文档
    void docOpen();//打开文档
    void docSave();//保存文档
    void docSaveAs();//文档另存为
    void docUndo();//撤销
    void docRedo();//重做
    void docCut();//剪切
    void docCopy();//复制
    void docPaste();//粘贴
    void textBold();//加粗
    void textItalic();//倾斜
    void textUnderline();//加下画线
    void textFamily(const QString & fmly);//字体
    void textSize(const QString & ps);//字号
    void textAlign(QAction* act);//对齐方式
    void textColor();//设置颜色
    void paraStyle(int sidx);//段落标号和编号
    void docPrint();
    void docPrintPreview();
    void printPreview(QPrinter* pter);
private slots:
    void on_aboutQtAction_triggered();

    void on_aboutAction_triggered();

    void on_newAction_triggered();
    void refreshMenus();//刷新菜单的槽函数

    void on_openAction_triggered();

    void on_saveAction_triggered();

    void on_saveAsAction_triggered();

    void on_undoAction_triggered();

    void on_copyAction_triggered();

    void on_pasteAction_triggered();

    void on_boldAction_triggered();

    void on_italicAction_triggered();

    void on_underlineAction_triggered();

    void on_leftAlignAction_triggered();

    void on_centerAction_triggered();

    void on_rightAlignAction_triggered();

    void on_justifyAction_triggered();

    void on_colorAction_triggered();

    void on_comboBox_activated(int index);

    void on_printAction_triggered();

    void on_printPreviewAction_triggered();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_sizeComboBox_editTextChanged(const QString &arg1);

    void addSubWndListMenu();//往“窗口”主菜单下添加子窗口菜单项列表

    void on_closeAction_triggered();

    void on_closeAllAction_triggered();

    void on_tileAction_triggered();

    void on_cascadeAction_triggered();

    void on_nextAction_triggered();

    void on_previousAction_triggered();
protected:
    void closeEvent(QCloseEvent* event);

private:
    Ui::MainWindow *ui;
    void formatEnabled();
    MyChildWnd* activateChildWnd();//活动文档子窗口
    QMdiSubWindow* findChildWnd(const QString &docName);//查找特定子窗口文档
    QSignalMapper* myWndMapper;//子窗口信号映射
};
#endif // MAINWINDOW_H
