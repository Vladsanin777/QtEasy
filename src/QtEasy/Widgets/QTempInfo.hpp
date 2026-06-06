#pragma once

#include <QtQmlIntegration/qqmlintegration.h>
#include <QWidget>
#include <QString>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QClipboard>
#include <QApplication>


namespace QtEasy {
    namespace Widgets {
        class QTempInfo : public QWidget {
            Q_OBJECT
            QML_ELEMENT

        public:
            enum Functions {
                NONE = 0,
                CLOSE = 1,
                COPY = 2,
            };

        private:
            QHBoxLayout * m_layout{nullptr};
            QLabel * m_label{nullptr};
            QPushButton * m_close{nullptr};
            QPushButton * m_copy{nullptr};

        public:
            QTempInfo(QWidget * parent = nullptr);

            QTempInfo(QString label, QWidget * parent = nullptr);

            QTempInfo(QString label, int functions,
                    QWidget * parent = nullptr);

            QString text();

        signals:
            void closed(void);

        public slots:
            void setText(QString text);

        private slots:
            void close(void);

            void copy();

        protected:
            void paintEvent(QPaintEvent *event) override;
        };
    }
}
