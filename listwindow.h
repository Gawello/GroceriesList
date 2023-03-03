#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ListWindow; }
QT_END_NAMESPACE

class ListWindow : public QMainWindow
{
    Q_OBJECT

public:
    ListWindow(QWidget *parent = nullptr);
    ~ListWindow();

    void addNewItem();
    void listWidgetItemClicked(QListWidgetItem *item);


private slots:
    void on_pushButton_clicked();

private:
    Ui::ListWindow *ui;
};
#endif // LISTWINDOW_H
