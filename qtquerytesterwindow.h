#ifndef QTQUERYTESTERWINDOW_H
#define QTQUERYTESTERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtQueryTesterWindow; }
QT_END_NAMESPACE

class QtQueryTesterWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtQueryTesterWindow(QWidget *parent = nullptr);
    ~QtQueryTesterWindow();

private slots:
    void on_textQuery_textChanged();

    void on_textXml_textChanged();

private:
    void process();

    Ui::QtQueryTesterWindow *ui;
};
#endif // QTQUERYTESTERWINDOW_H
