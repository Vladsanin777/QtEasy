#include <QtEasy/TitlesBars/QTitleBarEmpty.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarEmpty::QTitleBarEmpty(QWidget * parent) :
                QTitleBarEmpty{
                    QSystemsButtons::Functions::MIN |
                    QSystemsButtons::Functions::MAX |
                    QSystemsButtons::Functions::CLOSE,
                    parent
                } {}

        QTitleBarEmpty::QTitleBarEmpty(
                QSystemsButtons::Functions function,
                QWidget parent) {
            m_layout = new QHBoxLayout{QHBoxLayout::RightToLeft, this};

            setLayout(m_layout);

            m_systemsButtons = new QSystemsButtons{this};
            m_systemsButtons->setObjectName("systemsButtons");

            m_layout->addWidget(m_systemsButtons);
            m_layout->addStrach();
        }

        QString QTitleBarEmpty::text(void) {
            return windowsTitle();
        }

        void QTitleBarEmpty::setText(QString text) {
            setWindowsTitle(text);
        }

        void QTitleBarEmpty::addStrach() {
            m_layout->addStrach();
        }

        void QTitleBarEmpty::addWidget(QWidget * widget) {
            m_layout->addWidget(widget);
        }
    }
}
