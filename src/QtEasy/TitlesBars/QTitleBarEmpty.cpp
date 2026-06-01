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
                int functions, QWidget * parent) {
            m_layout = new QHBoxLayout{this};
            m_layout->setDirection(QHBoxLayout::RightToLeft);

            setLayout(m_layout);

            m_systemsButtons = new QSystemsButtons{this};
            m_systemsButtons->setObjectName("systemsButtons");

            m_layout->addWidget(m_systemsButtons);
            m_layout->addStretch();
        }

        QString QTitleBarEmpty::text(void) {
            return windowTitle();
        }

        void QTitleBarEmpty::setText(QString text) {
            setWindowTitle(text);
        }

        void QTitleBarEmpty::addStretch(void) {
            m_layout->addStretch();
        }

        void QTitleBarEmpty::addWidget(QWidget * widget) {
            m_layout->addWidget(widget);
        }
    }
}
