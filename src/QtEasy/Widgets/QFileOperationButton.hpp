#pragma once

#include <QtQmlIntegration/qqmlintegration.h>
#include <QPushButton>
#include <QString>
#include <QWidget>


namespace QtEasy {
    namespace Widgets {
        class QFileOperationButton : public QPushButton {
            Q_OBJECT
            QML_ELEMENT

        private:
            QString m_filePath{};
            QString m_caption{};
            QString m_extention{};
            QString m_directory{};

        public:
            QFileOperationButton(QWidget * parent = nullptr);

            QFileOperationButton(QString caption, QWidget * parent = nullptr);

            QFileOperationButton(QString caption, QString extention,
                    QWidget * parent = nullptr);

            QFileOperationButton(QString caption, QString extention,
                    QString directory, QWidget * parent = nullptr);

            bool isFilePath(void);

            QString filePath(void);

            QString caption(void);

            QString extention(void);

            QString directory(void);

        public slots:
            void setFilePath(QString filePath);

            void setCaption(QString text);

            void setExtention(QString extention);

            void setDirectory(QString directory);

            virtual void askUser(void) = 0;

        protected:
            void mouseReleaseEvent(QMouseEvent *event);
        };
    }
}
