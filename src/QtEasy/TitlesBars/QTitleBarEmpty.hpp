#pragma once

#include <QtQmlIntegration/qqmlintegration.h>
#include <QWidget>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
#include <QWindow>
#include <QHBoxLayout>
#include <QtEasy/Widgets/QSystemsButtons.hpp>


namespace QtEasy {
    namespace TitlesBars {

        using QtEasy::Widgets::QSystemsButtons;

        class QTitleBarEmpty : public QWidget {
            Q_OBJECT
            QML_ELEMENT

        private:
            QHBoxLayout * m_layout{nullptr};
            QSystemsButtons * m_systemsButtons{nullptr};
            Qt::Edges m_resizeEdge{Qt::Edges{}};
            const int m_borderWidth{8};

        public:
            QTitleBarEmpty(QWidget * parent = nullptr);

            QTitleBarEmpty(int functions, QWidget * parent = nullptr);

            QTitleBarEmpty(QString title, QWidget * parent = nullptr);

            QTitleBarEmpty(QString title, int functions,
                    QWidget * parent = nullptr);

            virtual QString text(void);

        public slots:
            virtual void setText(QString text);

            void addStretch(void);

            void addWidget(QWidget * widget);

        protected:
            void mousePressEvent(QMouseEvent *event) override;

            void mousePressEventWindow(QMouseEvent *event);

            void mouseDoubleClickEvent(QMouseEvent *event) override;

            void mouseMoveEventWindow(QMouseEvent *event);

            void paintEvent(QPaintEvent *event) override;

            bool eventFilter(QObject *watched, QEvent *event) override;
        };
    }
}
