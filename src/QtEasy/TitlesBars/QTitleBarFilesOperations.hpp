#pragma once

#include <QtQmlIntegration/qqmlintegration.h>
#include <QWidget>
#include <QString>
#include <QtEasy/Widgets/QFilesOperations.hpp>
#include <QtEasy/TitlesBars/QTitleBar.hpp>


namespace QtEasy {
    namespace TitlesBars {

        using QtEasy::Widgets::QFilesOperations;
        using QtEasy::TitlesBars::QTitleBar;

        class QTitleBarFilesOperations : public QTitleBar {
            Q_OBJECT
            QML_ELEMENT

        private:
            QFilesOperations * m_filesOperations{nullptr};

        public:
            QTitleBarFilesOperations(QWidget * parent = nullptr);

            QTitleBarFilesOperations(QString title,
                    QWidget * parent = nullptr);

            QTitleBarFilesOperations(QString title,
                    QString captionOpen, QString captionSave,
                    QString captionSaveAs, QWidget * parent = nullptr);

            QTitleBarFilesOperations(QString title,
                    QString captionOpen, QString captionSave,
                    QString captionSaveAs, QString extension,
                    QWidget * parent = nullptr);

            QTitleBarFilesOperations(QString title,
                    QString captionOpen, QString captionSave,
                    QString captinSaveAs, QString extension,
                    QString direction, QWidget * parent = nullptr);

            QString read(void);

            void write(QString text);
        signals:
            void opened(void);

            void saved(void);
        };
    }
}
