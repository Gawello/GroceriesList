#include "listwindow.h"
#include "./ui_listwindow.h"

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

ListWindow::ListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListWindow)

{
    ui->setupUi(this);

    // create the "Add Item" action and connect it to the "addNewItem" slot
    QAction *addItemAction = new QAction("Add Item", this);
    connect(addItemAction, &QAction::triggered, this, &ListWindow::addNewItem);

    // add the "Add Item" action to the "Edit" menu in the menu bar
    ui->menuEdit->addAction(addItemAction);

}

ListWindow::~ListWindow()
{
    delete ui;
}


void ListWindow::addNewItem()
{
    // create a new dialog window
    QDialog *addItemDialog = new QDialog(this);

    // add widgets to the dialog for getting input
    QLabel *itemNameLabel = new QLabel("Item name:", addItemDialog);
    QLineEdit *itemNameEdit = new QLineEdit(addItemDialog);
    QPushButton *okButton = new QPushButton("OK", addItemDialog);

    // create a layout for the widgets
    QVBoxLayout *dialogLayout = new QVBoxLayout(addItemDialog);
    dialogLayout->addWidget(itemNameLabel);
    dialogLayout->addWidget(itemNameEdit);
    dialogLayout->addWidget(okButton);

    // connect the OK button to a slot that will add the item to the list
    connect(okButton, &QPushButton::clicked, addItemDialog, &QDialog::accept);

    // show the dialog window and get the input from the user
    if (addItemDialog->exec() == QDialog::Accepted) {
        QString newItemName = itemNameEdit->text();
        ui->listWidget->addItem(newItemName);
    }
}

void ListWindow::on_pushButton_clicked()
{
    addNewItem();
}

