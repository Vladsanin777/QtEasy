#include <QtEasy/TitlesBars/QTitleBarTempInfo.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarTempInfo::QTitleBarTempInfo(QWidget * parent) :
                QTitleBarTempInfo{QString{}, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo(
                QLabelTempInfo::Mode mode, QWidget * parent) :
                QTitleBarTempInfo{QString{}, mode, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo(
                QString title, QWidget * parent) :
                QTitleBarTempInfo{title, QString{}, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo(
                QString title, QString tempInfo, QWidget * parent) :
                QTitleBarTempInfo{title, tempInfo,
                    QLabelTempInfo::Mode::LABEL, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo(QString title,
                QLabelTempInfo::Mode mode, QWidget * parent) :
                QTitleBarTempInfo{title, QString{}, mode, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo(QString title,
                QString tempInfo, QLabelTempInfo::Mode mode, QWidget * parent) :
                QTitleBarEmpty{title, parent} {
            m_title = new QLabelTempInfo{title, tempInfo, mode, this};
            m_title->setObjectName("title");

            connect(m_title, &QLabelTempInfo::showText,
                    this, &QTitleBarTempInfo::upShowText);
            connect(m_title, &QLabelTempInfo::showTempInfo,
                    this, &QTitleBarTempInfo::upShowTempInfo);

            addWidget(m_title);
            addStretch();
        }

        QString QTitleBarTempInfo::text(void) {
            return m_title->text();
        }

        QString QTitleBarTempInfo::tempInfo(void) {
            return m_title->tempInfo();
        }

        void QTitleBarTempInfo::switchText(void) {
            m_title->switchText();
            emit showText();
        }

        void QTitleBarTempInfo::switchTempInfo(void) {
            m_title->switchTempInfo();
            emit showTempInfo();
        }

        void QTitleBarTempInfo::setText(QString text) {
            m_title->setText(text);
            QTitleBarEmpty::setText(text);
        }

        void QTitleBarTempInfo::setTempInfo(QString tempInfo) {
            m_title->setTempInfo(tempInfo);
        }

        void QTitleBarTempInfo::upShowText(void) {
            emit showText();
        }

        void QTitleBarTempInfo::upShowTempInfo(void) {
            emit showTempInfo();
        }
    }
}
