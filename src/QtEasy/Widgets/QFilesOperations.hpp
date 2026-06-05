#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QtEasy/Widgets/QOpenButton.hpp>
#include <QtEasy/Widgets/QSaveButton.hpp>
#include <QtEasy/Widgets/QSaveAsButton.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QOpenButton;
        using QtEasy::Widgets::QSaveButton;
        using QtEasy::Widgets::QSaveAsButton;

        class QFilesOperations : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QOpenButton * m_open{nullptr};
            QSaveButton * m_save{nullptr};
            QSaveAsButton * m_saveAs{nullptr};

        public:
            QFilesOperations(QWidget * parent = nullptr);

            QFilesOperations(QString captionOpen, QString captionSave,
                    QString captionSaveAs, QWidget * parent = nullptr);

            QFilesOperations(QString captionOpen, QString captionSave,
                    QString captionSaveAs, QString extention,
                    QWidget * parent = nullptr);

            QFilesOperations(QString captionOpen, QString captionSave,
                    QString captionSaveAs, QString extention,
                    QString directory, QWidget * parent = nullptr);

        public:
            void setSpacing(int space);

            int spacing(void);

            QString read(void);

            void write(QString text);

        signals:
            void opened();

            void saved();

        private slots:
            void onClickOpen(void);

            void onClickSave(void);

            void onClickSaveAs(void);
        };
    }
}
