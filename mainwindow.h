#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void saveFile(QListWidget *listWidget, QString filenameOut);

    void openFile();

    void on_listWidget_itemActivated(QListWidgetItem *item);

    void on_listWidget_2_itemActivated(QListWidgetItem *item);

    void on_listWidget_3_itemActivated(QListWidgetItem *item);

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_3_triggered();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_8_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
