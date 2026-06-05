#include <QtEasy/TitlesBars/QTitleBarFilesOperations.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarFilesOperations::QTitleBarFilesOperations(
                QWidget * parent) :
            QTitleBarFilesOperations{QString{}, parent} {}

        QTitleBarFilesOperations::QTitleBarFilesOperations(
                QString title, QWidget * parent) :
            QTitleBarFilesOperations{title, QString{},
                QString{}, QString{}, parent} {}

        QTitleBarFilesOperations::QTitleBarFilesOperations(
                QString title, QString captionOpen, QString captionSave,
                QString captionSaveAs, QWidget * parent) :
            QTitleBarFilesOperations{title, captionOpen, captionSave,
                captionSaveAs, QString{}, parent} {}

        QTitleBarFilesOperations::QTitleBarFilesOperations(
                QString title, QString captionOpen, QString captionSave,
                QString captionSaveAs, QString extension, QWidget * parent) :
            QTitleBarFilesOperations{title, captionOpen,
                captionSave, captionSaveAs, extension,
                QString{}, parent} {}

        QTitleBarFilesOperations::QTitleBarFilesOperations(
                QString title, QString captionOpen, QString captionSave,
                QString captionSaveAs, QString extension,
                QString direction, QWidget * parent) :
            QTitleBar{title, parent} {
            m_filesOperations = new QFilesOperations{
                captionOpen, captionSave, captionSaveAs, extension, direction, this
            };

            addWidget(m_filesOperations);

            connect(m_filesOperations, &QFilesOperations::opened,
                    this, &QTitleBarFilesOperations::opened);

            connect(m_filesOperations, &QFilesOperations::saved,
                    this, &QTitleBarFilesOperations::saved);
        }

        QString QTitleBarFilesOperations::read(void) {
            return m_filesOperations->read();
        }

        void QTitleBarFilesOperations::write(QString text) {
            m_filesOperations->write(text);
        }
    }
}
