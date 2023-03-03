#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
public:
    Product(const QString& name, double quantity, const QString& unit);

    QString name() const;
    double quantity() const;
    QString unit() const;

private:
    QString m_name;
    double m_quantity;
    QString m_unit;
};

#endif // PRODUCT_H
