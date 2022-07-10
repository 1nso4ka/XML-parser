#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QWidget>
#include <QXmlStreamReader>
#include <QTreeWidgetItem>
#include <QStack>
#include <QDebug>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class XMLparser; }     //пространство имен UI
QT_END_NAMESPACE

class XMLparser : public QWidget {
   Q_OBJECT

public:
   XMLparser(QWidget *parent = nullptr);
   ~XMLparser();

private slots:
   void on_parse_clicked();          //декларация, ведущая на метод отвечающий за парсинг xml документа
   void on_importFile_clicked();     //декларация, ведущая на метод отвечающий за импорт xml документа
   void on_reset_clicked();          //декларация, ведущая на метод отвечающий за очистку рабочей области
   void on_quit_clicked();           //декларация, ведущая на метод отвечающий за выход из программы

private:
   Ui::XMLparser *ui;
};
#endif // XMLPARSER_H
