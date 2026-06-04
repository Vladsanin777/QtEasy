#pragma once

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QFileDialog>
#include <QtEasy/Widgets/QSaveButton.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QSaveButton;

        class QSaveAsButton : public QSaveButton {
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

        protected:
            void mouseReleaseEvent(QMouseEvent * event) override;
        };
    }
}
