#pragma once

#include <QWidget>
#include <QString>
#include <QStyle>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>


namespace QtEasy {
    namespace Widgets {
        class QTempInfo : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QLabel * m_label{nullptr};
            QPushButton * m_close{nullptr};
            QPushButton * m_copy{nullptr};

            enum Functions {
                NONE = 0,
                CLOSE = 1,
                COPY = 2,
            };

        public:
            QTempInfo(QWidget * parent = nullptr) : QTempInfo{QString{}, parent};

            QTempInfo(QString label = {}, QWidget * parent = nullptr) :
                    QLog{label, CLOSE | COPY, parent};

            QTempInfo(QString label = {}, Functions functions = {CLOSE | COPY},
                    QWidget * parent = nullptr) : QWidget{parent};

            QString text();

        signals:
            void closed(void);

        public slots:
            void setText(QString text);

        private slots:
            void close(void) override;

            void copy();
        };
    }
}
