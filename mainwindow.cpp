#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QtSql/qsqldatabase.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui ->listWidget->addItem(ui ->lineEdit->text());
    if (ui ->lineEdit->text() != "") {
        ui ->lineEdit->setText("");
    }
}


void MainWindow::on_listWidget_itemActivated(QListWidgetItem *item)
{
    ui ->listWidget_2->addItem(ui->listWidget->currentItem()->text());
    delete ui->listWidget->currentItem();
}


void MainWindow::on_listWidget_2_itemActivated(QListWidgetItem *item)
{
    ui ->listWidget_3->addItem(ui->listWidget_2->currentItem()->text());
    delete ui->listWidget_2->currentItem();
}


void MainWindow::on_listWidget_3_itemActivated(QListWidgetItem *item)
{
    delete ui->listWidget_3->currentItem();
}


void MainWindow::on_action_4_triggered()
{
    ui->listWidget->clear();
}


void MainWindow::on_action_5_triggered()
{
    ui->listWidget_2->clear();
}


void MainWindow::on_action_6_triggered()
{
    ui->listWidget_3->clear();
}


void MainWindow::on_action_7_triggered()
{
    on_action_4_triggered();
    on_action_5_triggered();
    on_action_6_triggered();
}


void MainWindow::on_action_3_triggered()
{
    QApplication::quit();
}


void MainWindow::on_action_triggered()
{
    openFile();
}

void MainWindow::openFile(){
    int count = 0;
    QString filenameIn = QFileDialog::getOpenFileName();
    if (!filenameIn.isEmpty()) {
        QFile fileIn(filenameIn);
        if (fileIn.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&fileIn);
            while(!in.atEnd()) {
                QString line = in.readLine();
                if (line == "$$$"){
                    count++;
                    continue;
                }
                switch(count){
                    case 1:
                        ui->listWidget->addItem(line);
                        break;
                    case 2:
                        ui->listWidget_2->addItem(line);
                        break;
                    case 3:
                        ui->listWidget_3->addItem(line);
                        break;
                }


            }
            fileIn.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file.");
        }
    }
}

void MainWindow::on_action_2_triggered()
{
    QString filenameOut = QFileDialog::getSaveFileName();

    saveFile(ui->listWidget, filenameOut);
    saveFile(ui->listWidget_2, filenameOut);
    saveFile(ui->listWidget_3, filenameOut);
}

void MainWindow::saveFile(QListWidget *list, QString filenameOut){
    QFile fileOut(filenameOut);
    if (list == ui->listWidget)
        fileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    else
        fileOut.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&fileOut);
    out << "$$$\n";
    for (int i = 0; i < list->count(); ++i)
        out << list->item(i)->text() + "\n";
    fileOut.close();
}
