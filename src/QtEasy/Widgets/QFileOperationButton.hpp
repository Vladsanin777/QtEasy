#pragma once

#include <QPushButton>
#include <QString>
#include <QWidget>


namespace QtEasy {
    namespace Widgets {
        class QFileOperationButton : public QPushButton {
            Q_OBJECT

        private:
            QString m_filePath{};
            QString m_info{};
            QString m_extention{};
            QString m_directory{};

        public:
            QFileOperationButton(QWidget * parent = nullptr);

            QFileOperationButton(QString label = {}, QWidget * parent = nullptr);

            QFileOperationButton(QString label = {}, QString text = {},
                    QWidget * parent = nullptr);

            QFileOperationButton(QString label = {}, QString text = {},
                    QString extention = {}, QWidget * parent = nullptr);

            QFileOperationButton(QString label = {}, QString text = {}, QString extention = {},
                    QString directory = {}, QWidget * parent = nullptr);

            bool isFilePath(void);

            QString filePath(void);

            QString info(void);

            QString extention(void);

            QString directory(void);

        public slots:
            void setFilePath(QString filePath);

            void setInfo(QString text);

            void setExtention(QString extention);

            void setDirectory(QString directory);

            virtual void askUser(void) = 0;

        protected:
            void mouseReleaseEvent(QMouseEvent *event);
        };
    }
}
