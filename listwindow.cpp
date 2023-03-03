#include "listwindow.h"
#include "./ui_listwindow.h"

ListWindow::ListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListWindow)

{
    ui->setupUi(this);
    // create the "Add Item" action and connect it to the "addNewItem" slot
    QAction *addItemAction = new QAction("Add", this);
    connect(addItemAction, SIGNAL(triggered()), this, SLOT(addNewItem()));

    // add the "Add Item" action to a menu or toolbar in the main window
    QMenu *editMenu = menuBar()->addMenu("Edit");
    editMenu->addAction(addItemAction);
}

ListWindow::~ListWindow()
{
    delete ui;
}
