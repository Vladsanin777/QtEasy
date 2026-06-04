#include <QtEasy/TitlesBars/QTitleBarTempInfoFilesOperations.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarTempInfoFilesOperations::QTitleBarTempInfoFilesOperations(
                QWidget * parent) :
            QTitleBarTempInfoFilesOperations{QString{}, parent} {}

        QTitleBarTempInfoFilesOperations::QTitleBarTempInfoFilesOperations(
                QString title, QWidget * parent) :
            QTitleBarTempInfoFilesOperations{title, QString{}, parent} {}

        QTitleBarTempInfoFilesOperations::QTitleBarTempInfoFilesOperations(
                QString title, QString tempInfo, QWidget * parent) :
            QTitleBarTempInfoFilesOperations{title, tempInfo,
                QString{}, QString{}, QString{}, parent} {}

        QTitleBarTempInfoFilesOperations::QTitleBarTempInfoFilesOperations(
                QString title, QString tempInfo, QString captionOpen,
                QString captionSave, QString captionSaveAs, QWidget * parent) :
            QTitleBarTempInfoFilesOperations{title, tempInfo,
                captionOpen, captionSave, captionSaveAs,
                QString{}, parent} {}

        QTitleBarTempInfoFilesOperations::QTitleBarTempInfoFilesOperations(
                QString title, QString tempInfo, QString captionOpen,
                QString captionSave, QString captionSaveAs,
                QString extention, QWidget * parent) :
            QTitleBarTempInfoFilesOperations{title, tempInfo,
                captionOpen, captionSave, captionSaveAs,
                extention, QString{}, parent} {}

        QTitleBarTempInfoFilesOperations::QTitleBarTempInfoFilesOperations(
                QString title, QString tempInfo, QString captionOpen,
                QString captionSave, QString captionSaveAs, QString extention,
                QString direction, QWidget * parent) :
            QTitleBarTempInfo{title, tempInfo, parent} {
            m_filesOperations = new QFilesOperations{
                captionOpen, captionSave, captionSaveAs, extention, direction, this
            };

            addWidget(m_filesOperations);

            connect(m_filesOperations, &QFilesOperations::opened,
                    this, &QTitleBarTempInfoFilesOperations::opened);

            connect(m_filesOperations, &QFilesOperations::saved,
                    this, &QTitleBarTempInfoFilesOperations::saved);
        }
    }
}
