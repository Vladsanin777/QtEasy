#pragma once

#include <QWidget>
#include <QStyle>
#include <QHBoxLayout>
#include <QtEasy/Widgets/QSystemsButtons.hpp>


namespace QtEasy {
    namespace TitlesBars {

        using QtEasy::Widgets::QSystemsButtons;

        class QTitleBarEmpty : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QSystemsButtons * m_systemsButtons{nullptr};

        public:
            QTitleBarEmpty(QWidget * parent = nullptr);

            QTitleBarEmpty(
                    int function = {
                        QSystemsButtons::Functions::MIN |
                        QSystemsButtons::Functions::MAX |
                        QSystemsButtons::Functions::CLOSE
                    },
                    QWidget * parent = nullptr);

            virtual QString text(void);

        public slots:
            virtual void setText(QString text);

            void addStretch(void);

            void addWidget(QWidget * widget);
        };
    }
}
