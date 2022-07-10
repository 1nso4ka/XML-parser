#include "xmlparser.h"
#include "./ui_xmlparser.h"

XMLparser::XMLparser(QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::XMLparser {
   ui->setupUi(this);

   QPixmap pix;                                                       //объявляем переменную типа QPixmap
   pix.load("C:/Users/MSI/Desktop/1.jpg");                            //загружаем картинку по определенному пути
   ui->pic->setPixmap(pix);                                           //отоброжаем картинку, с помощью метода Qlabel
   setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);     //запрещаем масштабирование окна
}

XMLparser::~XMLparser()
{
   delete ui;
}

void XMLparser::on_parse_clicked()
{
   QXmlStreamReader xml;                                              //объявлем переменную типа QXmlStreamReader
   xml.addData(ui->textEdit->toPlainText());                          //добавляем данные методом, вытакскиваем текстовые данные

   ui->treeWidget->clear();
   QStack<QTreeWidgetItem*> stack;                                    //контейнер QStack

   while (!xml.atEnd()) {                                             //пока мы не дошли до конца документа, мы:
       if (xml.isStartElement()) {                                    //проверка на стартовый элемент
           QStringList current;
           current << xml.name().toString();
           QTreeWidgetItem* item = new QTreeWidgetItem(current);      //добавляем в TreeWidget новый элемент
           if (stack.count() == 0) {                                  //проверка на корневой элемент
               ui->treeWidget->addTopLevelItem(item);                 //вывод корневого элемента
           } else {
               stack.top() -> addChild(item);                         //к верхнему элементу стека добавялем текущий элемент
           }
           stack.push(item);                                          //добавялем текущий элемент
       }
       if (xml.isEndElement()) {                                      //проверка на полседний элемент
           stack.pop();                                               //вытаскиваем верхний элемент
       }
       xml.readNext();                                                //перебор элементов
   }
}
void XMLparser::on_importFile_clicked() {
   QString path = QFileDialog::getOpenFileName(this, "Выбрать файл", "C:/",
                                               "XML file (*.ifsx);"); //открываем диалоговое окно, сохраняем путь в переменную path
   QFile file(path);
   QByteArray data;
   if (!file.open(QIODevice::ReadOnly)) {                              //проверка на открытие
       return;
   }
   data = file.readAll();                                              //считываем данные
   ui->textEdit->insertPlainText(data);                                //выводим полученную информацию в TextEdit
}
void XMLparser::on_reset_clicked() {
   ui->textEdit->clear();                                              //очитска рабочей области
} 
void XMLparser::on_quit_clicked() {   
exit(0);                                                            //закратие приложения
}
