#include "qtquerytesterwindow.h"
#include "./ui_qtquerytesterwindow.h"

#include <QBuffer>
#include <QtXmlPatterns/QXmlQuery>
#include <QtXmlPatterns/QXmlSerializer>

#include <QDebug>


QtQueryTesterWindow::QtQueryTesterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtQueryTesterWindow)
{
    ui->setupUi(this);
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
