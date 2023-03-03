#include "product.h"

Product::Product(const QString& name, double quantity, const QString& unit)
    : m_name(name), m_quantity(quantity), m_unit(unit)
{
}

QString Product::name() const
{
    return m_name;
}

double Product::quantity() const
{
    return m_quantity;
}

QString Product::unit() const
{
    return m_unit;
}
