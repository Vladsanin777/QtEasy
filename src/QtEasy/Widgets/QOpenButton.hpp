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

        private:
            QString m_filePath{};

        public:
            QOpenButton(QWidget * parent = nullptr);

            QOpenButton(QString text = {}, QWidget * parent = nullptr);

            QOpenButton(QString text = {}, QString extention = {},
                    QWidget * parent = nullptr);

            QOpenButton(QString text = {}, QString extention = {},
                    QString directory = {}, QWidget * parent = nullptr);

            QString getFilePath(void);

            QString read(void);

        protected:
            void mouseReleaseEvent(QMouseEvent * event) override;
        };
    }
}
