#pragma once

#include <QtQmlIntegration/qqmlintegration.h>
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
            QML_ELEMENT

        private:
            QString m_filePath{};

        public:
            QSaveButton(QWidget * parent = nullptr);

            QSaveButton(QString caption, QWidget * parent = nullptr);

            QSaveButton(QString caption, QString extention,
                    QWidget * parent = nullptr);

            QSaveButton(QString caption, QString extention,
                    QString directory, QWidget * parent = nullptr);

        protected:
            void mouseReleaseEvent(QMouseEvent * event) override;
        };
    }
}
