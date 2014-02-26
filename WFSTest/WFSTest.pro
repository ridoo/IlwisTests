#-------------------------------------------------
#
# Project created by QtCreator 2014-02-26T13:21:11
#
#-------------------------------------------------

QT       += testlib network xmlpatterns

QT       -= gui

include(../global.pri)

TARGET = wfstest

TEMPLATE = lib

DEFINES += WFSTEST_LIBRARY

DESTDIR = $$PWD/../../libraries/$$PLATFORM$$CONF/$$TARGET
DLLDESTDIR = $$PWD/../../output/$$PLATFORM$$CONF/bin/testcases

SOURCES += wfstest.cpp \
    wfsmoduletest.cpp \
    wfsconnectortest.cpp \
    wfscatalogconnectortest.cpp \
    webfeatureservicetest.cpp \
    qtxmlparsertest.cpp

HEADERS += wfstest.h\
        wfstest_global.h \
    wfsmoduletest.h \
    wfsconnectortest.h \
    wfscatalogconnectortest.h \
    webfeatureservicetest.h \
    qtxmlparsertest.h

unix|win32: LIBS += -L$$PWD/../../libraries/$$PLATFORM$$CONF/TestSuite/ -lTestSuite
unix|win32: LIBS += -L$$PWD/../../libraries/win32debug/wfsconnector/ -lwfsconnector

INCLUDEPATH += $$PWD/../TestSuite \
               $$PWD/../../IlwisConnectors/wfsconnector
DEPENDPATH += $$PWD/../TestSuite \
              $$PWD/../../IlwisConnectors/wfsconnector

OTHER_FILES += \
    testfiles/wfs_exceptionreport.xml \
    testfiles/wfs_capabilities.xml \
    testfiles/test_without_xml_header.xml \
    testfiles/test.xml \
    testfiles/quad100.xsd \
    testfiles/greenlevel_contours.xsd \
    testfiles/featurecollection.xml

testtarget.files = \
    testfiles/wfs_exceptionreport.xml \
    testfiles/wfs_capabilities.xml \
    testfiles/test_without_xml_header.xml \
    testfiles/test.xml \
    testfiles/quad100.xsd \
    testfiles/greenlevel_contours.xsd \
    testfiles/featurecollection.xml

testtarget.path = $$PWD/../../output/$$PLATFORM$$CONF/bin/extensions/testfiles

INSTALLS += testtarget