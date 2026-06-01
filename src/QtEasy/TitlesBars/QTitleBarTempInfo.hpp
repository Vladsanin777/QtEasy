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
#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QPushButton>


namespace QtEasy {
    namespace Widgets {
        class QSystemsButtons : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QPushButton * m_min{nullptr};
            QPushButton * m_max{nullptr};
            QPushButton * m_close{nullptr};

        public:
            enum Functions {
                NONE = 0,
                MIN = 1,
                MAX = 2,
                CLOSE = 4,
            };

            QSystemsButtons(QWidget * parent = nullptr) :
                QSystemsButtons{MIN | MAX | CLOSE, parent};

            QSystemsButtons(Functions functions = {MIN | MAX | CLOSE},
                    QWidget * parent = nullptr) : QWidget{parent};
        };
    }
}
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QtEasy/Widgets/QTempInfo.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QTempInfo;

        class QLabelTempInfo : public QWidget {
            Q_OBJECT

        private:
            QLabel * m_label{nullptr};
            QTempInfo * m_tempInfo{nullptr};
            Mode m_mode{NONE};

        public:
            enum Mode {
                LABEL,
                TEMP_INFO,
            };

            QLabelTempInfo(QWidget * parent = nullptr) :
                    QLabelTempInfo{Title, parent};

            QLabelTempInfo(Mode mode = {Title}, QWidget * parent = nullptr) :
                    QLabelTempInfo{QString{}, mode, parent};

            QLabelTempInfo(QString label = {}, Mode mode = {TITLE},
                    QWidget * parent = nullptr) :
                    QLabelTempInfo{label, QString{}, mode, parent};

            QLabelTempInfo(QString label = {}, QString tempInfo = {},
                    Mode mode = {TITLE}, QWidget * parent = nullptr) :
                    QWidget{parent};

            void mode();

            QString tempInfo(void);

            QString text(void);

            void setMode(Mode mode);

        public slots:
            void switchLabel();

            void switchTempInfo(void);

            void setTempInfo(QString text);

            void setText(QString text);
        };
    }
}
#include <QString>
#include <QStyle>
#include <QLabel>
#include <QtEasy/Widgets/QLabelTempInfo.hpp>
#include <QtEasy/TitlesBars/QTitleBarEmpty.hpp>


namespace QtEasy {
    namespace TitlesBars {

        using QtEasy::Widgets::QLabelTempInfo;
        using QtEasy::TitlesBars::QTitleBarEmpty;

        class QTitleBarTempInfo : public QTitleBarEmpty {
            Q_OBJECT

        private:
            QLabelTempInfo * m_title{nullptr};

        public:
            QTitleBarTempInfo(QWidget * parent = nullptr) :
                    QTitleBarTempInfo{QString{}, parent};

            QTitleBarTempInfo(QString title = {}, QWidget * parent = nullptr) :
                    QTitleBarTempInfo{label, QString{}, parent};

            QTitleBarTempInfo( 
                    QString title = {}, QString tempInfo = {},
                    QWidget * parent = nullptr) : QTitleBarEmpty{parent};

            QString text(void) override;

            QString tempInfo(void);

        public slot:
            void setText(QString text) override;

            void setTempInfo(QString tempInfo);
        };
    }
}
