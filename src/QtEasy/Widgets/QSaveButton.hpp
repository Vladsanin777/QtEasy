#pragma once

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QFileDialog>
#include <QtEasy/Widgets/QSaveAsButton.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QSaveAsButton;

        class QSaveButton : public QSaveAsButton {
            Q_OBJECT

        private:
            QString m_filePath{};

        public:
            QSaveButton(QWidget * parent = nullptr);

            QSaveButton(QString text = {}, QWidget * parent = nullptr);

            QSaveButton(QString text = {}, QString extention = {},
                    QWidget * parent = nullptr);

            QSaveButton(QString text = {}, QString extention = {},
                    QString directory = {}, QWidget * parent = nullptr);

        protected:
            void mouseReleaseEvent(QMouseEvent * event) override;
        };
    }
}
