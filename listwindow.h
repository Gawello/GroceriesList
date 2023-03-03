#ifndef LISTWINDOW_H
#define LISTWINDOW_H

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

private:
    Ui::ListWindow *ui;
};
#endif // LISTWINDOW_H
