#include "listwindow.h"
#include "./ui_listwindow.h"
#include "product.h"

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

    // get the input data from the dialog
    QString itemName = itemNameEdit->text();
    double itemQuantity = itemQuantityEdit->text().toDouble();
    QString itemUnit = itemUnitComboBox->currentText();

    // create a new Product object with the input data
    Product newItem(itemName, itemQuantity, itemUnit);

    // add the new item to the list widget using QListWidgetItem
    QListWidgetItem *newItemWidget = new QListWidgetItem(ui->listWidget);
    newItemWidget->setText(QString("%1 %2 %3").arg(itemQuantity).arg(itemUnit).arg(itemName));
    newItemWidget->setData(Qt::UserRole, QVariant::fromValue(newItem));

}

void ListWindow::on_pushButton_clicked()
{
    addNewItem();
}

void ListWindow::listWidgetItemClicked(QListWidgetItem *item)
{
    // retrieve the Product data from the clicked item
    Product itemData = item->data(Qt::UserRole).value<Product>();

    // use the Product data to update the UI
    ui->nameLabel->setText(itemData.name());
    ui->quantityLabel->setText(QString::number(itemData.quantity()));
    ui->unitLabel->setText(itemData.unit());
}

