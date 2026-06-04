#pragma once

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QFileDialog>
#include <QtEasy/Widgets/QFileOperationButton.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QFileOperationButton;

        class QSaveAsButton : public QFileOperationButton {
            Q_OBJECT

        private:
            QString m_filePath{};

        public:
            QSaveAsButton(QWidget * parent = nullptr);

            QSaveAsButton(QString text = {}, QWidget * parent = nullptr);

            QSaveAsButton(QString text = {}, QString extention = {},
                    QWidget * parent = nullptr);

            QSaveAsButton(QString text = {}, QString extention = {},
                    QString directory = {}, QWidget * parent = nullptr);

        public slots:
            void write(QString text);

            void askUser(void) override;
        };
    }
}
