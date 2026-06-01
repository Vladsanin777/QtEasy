#pragma once

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
