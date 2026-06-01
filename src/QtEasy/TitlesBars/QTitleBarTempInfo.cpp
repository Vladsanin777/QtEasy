#include <QtEasy/TitlesBars/QTitleBarTempInfo.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarTempInfo::QTitleBarTempInfo(QWidget * parent) {}

        QTitleBarTempInfo::QTitleBarTempInfo(
                QString title, QWidget * parent) {}

        QTitleBarTempInfo::QTitleBarTempInfo( 
                QString title, QString tempInfo, QWidget * parent) {
            m_title = new QLabelTempInfo{title, tempInfo, this}
            m_title->setObjectName("title")

            addWidget(m_title);
            addStrach();
        }

        QString QTitleBarTempInfo::text(void) {
            return m_labelTempInfo->text();
        }

        QString QTitleBarTempInfo::tempInfo(void) {
            return m_title->tempInfo();
        }

        void QTitleBarTempInfo::setText(QString text) {
            m_labelTempInfo->setText(text);
            QTitleBarEmpty::setText(text);
        }

        void QTitleBarTempInfo::setTempInfo(QString tempInfo) {
            m_labelTempInfo->setTempInfo(tempInfo);
        }
    }
}
