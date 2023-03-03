#include "listwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListWindow w;
    w.show();
    return a.exec();
}

void addNewItem()
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
    connect(okButton, SIGNAL(clicked()), addItemDialog, SLOT(accept()));

    // show the dialog window and get the input from the user
    if (addItemDialog->exec() == QDialog::Accepted) {
        QString newItemName = itemNameEdit->text();
        addItemToList(newItemName);
    }
}
