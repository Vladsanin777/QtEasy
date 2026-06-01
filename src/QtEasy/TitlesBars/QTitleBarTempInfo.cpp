#include <QtEasy/TitlesBars/QTitleBarTempInfo.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarTempInfo::QTitleBarTempInfo(QWidget * parent)  :
                    QTitleBarTempInfo{QString{}, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo(
                QString title, QWidget * parent) :
                    QTitleBarTempInfo{title, QString{}, parent} {}

        QTitleBarTempInfo::QTitleBarTempInfo( 
                QString title, QString tempInfo, QWidget * parent) :
                QTitleBarEmpty{parent} {
            m_title = new QLabelTempInfo{title, tempInfo, this};
            m_title->setObjectName("title");

            addWidget(m_title);
            addStretch();
        }

        QString QTitleBarTempInfo::text(void) {
            return m_title->text();
        }

        QString QTitleBarTempInfo::tempInfo(void) {
            return m_title->tempInfo();
        }

        void QTitleBarTempInfo::setText(QString text) {
            m_title->setText(text);
            QTitleBarEmpty::setText(text);
        }

        void QTitleBarTempInfo::setTempInfo(QString tempInfo) {
            m_title->setTempInfo(tempInfo);
        }
    }
}
