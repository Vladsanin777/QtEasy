#pragma once

#include <QWidget>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>
#include <QString>
#include <QLabel>
#include <QtEasy/Widgets/QTempInfo.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QTempInfo;

        class QLabelTempInfo : public QWidget {
            Q_OBJECT

        public:
            enum Mode {
                LABEL,
                TEMP_INFO,
            };

        private:
            QHBoxLayout * m_layout{nullptr};
            QLabel * m_label{nullptr};
            QTempInfo * m_tempInfo{nullptr};
            Mode m_mode{LABEL};

        public:
            QLabelTempInfo(QWidget * parent = nullptr);

            QLabelTempInfo(Mode mode = {LABEL}, QWidget * parent = nullptr);

            QLabelTempInfo(QString label = {}, QWidget * parent = nullptr);

            QLabelTempInfo(QString label = {}, Mode mode = {LABEL},
                    QWidget * parent = nullptr);

            QLabelTempInfo(QString label = {}, QString tempInfo = {},
                    QWidget * parent = nullptr);

            QLabelTempInfo(QString label = {}, QString tempInfo = {},
                    Mode mode = {LABEL}, QWidget * parent = nullptr);

            Mode mode(void);

            QString tempInfo(void);

            QString text(void);

            void setMode(Mode mode);

        public slots:
            void switchText(void);

            void switchTempInfo(void);

            void setTempInfo(QString text);

            void setText(QString text);

        protected:
            void paintEvent(QPaintEvent *event) override;
        };
    }
}
