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

        class QOpenButton : public QFileOperationButton {
            Q_OBJECT
            QML_ELEMENT

        public:
            QOpenButton(QWidget * parent = nullptr);

            QOpenButton(QString caption, QWidget * parent = nullptr);

            QOpenButton(QString caption, QString extention,
                    QWidget * parent = nullptr);

            QOpenButton(QString caption, QString extention,
                    QString directory, QWidget * parent = nullptr);

        public slots:
            QString read(void);

            void askUser(void) override;
        };
    }
}
