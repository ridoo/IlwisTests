#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <QString>
#include <QTest>
#include <QDir>
#include "kernel.h"
#include "testmacros.h"
#include "ilwistestclass.h"

class Classification : public IlwisTestCase
{
     Q_OBJECT

public:
    Classification();

private slots:
    void boxclassification();
private:

 NEW_TEST(Classification);

};

#endif // CLASSIFICATION_H
