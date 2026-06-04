#pragma once

#include <QWidget>
#include <QString>
#include <QtEasy/Widgets/QFilesOperations.hpp>
#include <QtEasy/TitlesBars/QTitleBarTempInfo.hpp>


namespace QtEasy {
    namespace TitlesBars {

        using QtEasy::TitlesBars::QTitleBarTempInfo;
        using QtEasy::Widgets::QFilesOperations;

        class QTitleBarTempInfoFilesOperations : public QTitleBarTempInfo {
            Q_OBJECT

        private:
            QFilesOperations * m_filesOperations{nullptr};

        public:
            QTitleBarTempInfoFilesOperations(
                    QWidget * parent = nullptr);

            QTitleBarTempInfoFilesOperations(QString title,
                    QWidget * parent = nullptr);

            QTitleBarTempInfoFilesOperations(QString title,
                    QString tempInfo, QWidget * parent = nullptr);

            QTitleBarTempInfoFilesOperations(
                    QString title, QString tempInfo, QString captionOpen,
                    QString captionSave, QString captionSaveAs,
                    QWidget * parent = nullptr);

            QTitleBarTempInfoFilesOperations(
                    QString title, QString tempInfo, QString captionOpen,
                    QString captionSave, QString captionSaveAs,
                    QString extention, QWidget * parent = nullptr);

            QTitleBarTempInfoFilesOperations(
                    QString title, QString tempInfo, QString captionOpen,
                    QString captionSave, QString captionSaveAs, QString extention,
                    QString direction, QWidget * parent = nullptr);

        signals:
            void opened(void);

            void saved(void);
        };
    }
}
