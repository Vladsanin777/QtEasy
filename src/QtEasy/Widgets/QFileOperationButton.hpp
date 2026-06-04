#pragma once

#include <QPushButton>
#include <QString>
#include <QWidget>


namespace QtEasy {
    namespace Widgets {
        class QFileOperationButton : public QPushButton {
            Q_OBJECT

        private:
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

            QString getInfo(void);

            QString getExtention(void);

            QString getDirectory(void);

            virtual QString getFilePath(void) = 0;

        public slots:
            void setInfo(QString text);

            void setExtention(QString extention);

            void setDirectory(QString directory);
        };
    }
}
