#include "qtquerytesterwindow.h"
#include "./ui_qtquerytesterwindow.h"

#include <QBuffer>
#include <QtXmlPatterns/QXmlQuery>
#include <QtXmlPatterns/QXmlSerializer>
#include <QSettings>

#include <QDebug>


QtQueryTesterWindow::QtQueryTesterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtQueryTesterWindow)
{
    ui->setupUi(this);

    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());

    ui->textQuery->setPlainText(settings.value("xquery", QString()).toString());
    ui->textXml->setPlainText(settings.value("xml", QString()).toString());
}

QtQueryTesterWindow::~QtQueryTesterWindow()
{
    delete ui;
}


void QtQueryTesterWindow::on_textQuery_textChanged()
{
    process();
}

void QtQueryTesterWindow::on_textXml_textChanged()
{
    process();
}

void QtQueryTesterWindow::process()
{
    QXmlQuery query;
    query.setFocus(ui->textXml->toPlainText());
    query.setQuery(ui->textQuery->toPlainText());

    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    QXmlSerializer serializer(query, &buffer);

    query.evaluateTo(&serializer);

    ui->textResult->setPlainText(QString::fromUtf8(buffer.data()));
}

void QtQueryTesterWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("xml", ui->textXml->toPlainText());
    settings.setValue("xquery", ui->textQuery->toPlainText());
    QWidget::closeEvent(event);
}
