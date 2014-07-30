#include <QUrl>

#include "ilwis.h"
#include "symboltable.h"
#include "testsuite.h"
#include "kernel.h"
#include "resource.h"
#include "ilwisdata.h"
#include "catalog.h"
#include "domain.h"
#include "datadefinition.h"
#include "columndefinition.h"
#include "table.h"
#include "attributerecord.h"
#include "geometries.h"
#include "feature.h"
#include "coordinatesystem.h"
#include "coverage.h"
#include "featurecoverage.h"

#include "postgrestest.h"

using namespace Ilwis;
using namespace Postgresql;

REGISTER_TEST(PostgresTest);

PostgresTest::PostgresTest() : IlwisTestCase("PostgresConnectorTest", "PostgresConnectorTest")
{
}

void PostgresTest::listNumberOfDriversAvailable() {
    QStringList lst = QSqlDatabase::drivers();
    qDebug() << lst.size();
}

void PostgresTest::initWithDatabaseConnectionString()
{
    QUrl connectionString("postgresql://localhost:5432/ilwis-pg-test");
    Resource dbResource(connectionString, itTABLE);
    prepareDatabaseConnection(dbResource);
    dbResource.prepare();

    ITable table;
    if ( !table.prepare(dbResource)) {
        QFAIL("Could not prepare table.");
    }
}

void PostgresTest::prepareDatabaseConnection(Resource &dbResource)
{
    dbResource.addProperty("pg.password", "postgres");
    dbResource.addProperty("pg.user", "postgres");
    dbResource.addProperty("pg.schema", "public");
    dbResource.prepare();
}

void PostgresTest::initCatalogItemsFromDatabase()
{
    QUrl connectionString("postgresql://localhost:5432/ilwis-pg-test");
    Resource dbCatalog(connectionString, itCATALOG);
    prepareDatabaseConnection(dbCatalog);
    dbCatalog.prepare();

    ICatalog cat(dbCatalog);
    std::vector<Resource> items = cat->items();
    if (items.size() == 0) {
        QFAIL("no catalog items found! Check if test db is initiated properly.");
    }

    std::for_each(items.begin(), items.end(),[](Resource &resource) {

        DOTEST2(resource.hasProperty("pg.user"), "pg resource does not contain db user");
        DOTEST2(resource.hasProperty("pg.password"), "pg resource does not contain db password");
        DOTEST2(resource.hasProperty("pg.schema"), "pg resource does not contain db schema");

        ITable table;
        //Resource tableResource(resource.url(), itTABLE);
        if ( !table.prepare(resource)) {
            QFAIL("Could not prepare table.");
        }

        DOTEST2(resource.url().toString().endsWith(table->name()), "");

//        IFeatureCoverage feature;
//        Resource featureResource(resource.url(), itFEATURE);
//        if ( !feature.prepare(featureResource)) {
//            QFAIL("Could not prepare feature.");
//        }
    });

    //Resource resource(items.front());


}


