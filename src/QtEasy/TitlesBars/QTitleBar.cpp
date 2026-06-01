#include <QtEasy/TitlesBars/QTitleBar.hpp>

namespace QtEasy {
    namespace TitlesBars {
        QTitleBar::QTitleBar(QWidget * parent) :
                    QTitleBar{QString{}, parent} {}

        QTitleBar::QTitleBar(QString title, 
                QWidget * parent) : QTitleBarEmpty{parent} {
            m_title = new QLabel{title, this};

            m_title->setObjectName("title");
            
            addWidget(m_title);
            addStrach();
        }

        QString QTitleBar::text(void) {
            return m_title->text();
        }

        void QTitleBar::setText(QString text) {
            m_title->setText(text);
            QTitleBarEmpty::setText(text);
        }
    }
}
