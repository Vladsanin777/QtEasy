#pragma once

#include <QtQmlIntegration/qqmlintegration.h>
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
            QML_ELEMENT

        private:
            QString m_filePath{};

        public:
            QSaveAsButton(QWidget * parent = nullptr);

            QSaveAsButton(QString caption, QWidget * parent = nullptr);

            QSaveAsButton(QString caption, QString extention,
                    QWidget * parent = nullptr);

            QSaveAsButton(QString caption, QString extention,
                    QString directory, QWidget * parent = nullptr);

        public slots:
            void write(QString text);

            void askUser(void) override;
        };
    }
}
