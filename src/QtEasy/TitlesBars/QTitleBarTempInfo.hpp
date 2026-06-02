#pragma once

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
            QTitleBarTempInfo(QWidget * parent = nullptr);

            QTitleBarTempInfo(QLabelTempInfo::Mode mode =
                    {QLabelTempInfo::Mode::LABEL}, QWidget * parent = nullptr);

            QTitleBarTempInfo(QString title = {}, QWidget * parent = nullptr);

            QTitleBarTempInfo(QString title = {}, QString tempInfo = {},
                    QWidget * parent = nullptr);

            QTitleBarTempInfo(QString title = {}, QLabelTempInfo::Mode mode =
                    {QLabelTempInfo::Mode::LABEL}, QWidget * parent = nullptr);

            QTitleBarTempInfo( 
                    QString title = {}, QString tempInfo = {},
                    QLabelTempInfo::Mode mode = {QLabelTempInfo::Mode::LABEL},
                    QWidget * parent = nullptr);

            QString text(void) override;

            QString tempInfo(void);

            void switchText(void);

            void switchTempInfo(void);

        public slots:
            void setText(QString text) override;

            void setTempInfo(QString tempInfo);
        };
    }
}
