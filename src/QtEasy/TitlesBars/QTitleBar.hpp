#pragma once

#include <QWidget>
#include <QLabel>
#include <QtEasy/TitlesBars/QTitleBarEmpty.hpp>


namespace QtEasy {
    namespace TitlesBars {
        class QTitleBar : public QTitleBarEmpty {
            Q_OBJECT

        private:
            QLabel * m_title{nullptr};

        public:
            QTitleBar(QWidget * parent = nullptr);

            QTitleBar(QString title, QWidget * parent = nullptr);

            QString text(void) override;

        public slots:
            void setText(QString text) override;
        };
    }
}
