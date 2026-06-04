#pragma once

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

        public:
            QOpenButton(QWidget * parent = nullptr);

            QOpenButton(QString label = {}, QWidget * parent = nullptr);

            QOpenButton(QString label = {}, QString text = {}
                    QWidget * parent = nullptr);

            QOpenButton(QString label, QString text = {},
                    QString extention = {}, QWidget * parent = nullptr);

            QOpenButton(QString label = {}, QString text = {}, QString extention = {},
                    QString directory = {}, QWidget * parent = nullptr);

        public slots:
            QString read(void);

            void askUser(void) override;
        };
    }
}
