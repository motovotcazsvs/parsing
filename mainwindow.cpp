#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QWebElementCollection>
//#include <QWebElement>
//#include <QWebPage>
#include <QWebEngineView>
#include <QWebEnginePage>
//#include <QWebFrame>
#include <QTextDocument>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*
    QWebPage page;
    page.mainFrame()->load(url);


    QWebFrame * frame = page.mainFrame();
    QWebElementCollection collection = frame->findAllElements("div");
    foreach (QWebElement element, collection)
    {
        //qDebug() << element.attribute("name");
        if (element.attribute("class") == "LvJXZ-tmO_091qVzXsrAA") {
            //element.setAttribute("value","test");
        qDebug() << element.toPlainText().toUtf8();
        }
    }
    */

    QWebEngineView *view = new QWebEngineView(parent);
    view->load(QUrl("https://www.radiorecord.ru/"));
    view->show();


    //QXmlQuery query;

    //query.setQuery(html, QUrl("https://www.radiorecord.ru/"));

    //QString r;
    //query.evaluateTo(&r);
    //QString::toHtmlEscaped("https://www.radiorecord.ru/");

    QTextDocument document;
    //document.setHtml(QUrl("https://www.radiorecord.ru/"));
    document.toPlainText();

    QWebEngineView webview;
    webview.setUrl(QUrl("https://www.radiorecord.ru/"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QWebEnginePage *page4 = new QWebEnginePage;
    //QString s = webview.page()->mainFrame()->toHtml();
    page4->load(QUrl("https://www.radiorecord.ru/"));

    page4->toPlainText(
                [] (const QString &result) {
                   qDebug()<<"txt:";
                   qDebug()<<result;
             });

    QString html;
    page4->toHtml([&html](const QString &result){ html = result; });

     qDebug() << html; // is still empty
}

