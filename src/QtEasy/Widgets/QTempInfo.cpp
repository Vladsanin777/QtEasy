#include <QtEasy/Widgets/QTempInfo.hpp>

namespace QtEasy {
    namespace Widgets {
        QTempInfo::QTempInfo(QWidget * parent) :
                QTempInfo{QString{}, parent} {}

        QTempInfo::QTempInfo(QString label, QWidget * parent) :
                QTempInfo{label, CLOSE | COPY, parent} {}

        QTempInfo::QTempInfo(QString label, int functions,
                QWidget * parent) : QWidget{parent} {
            setFixedHeight(40);

            m_layout = new QHBoxLayout{this};
            m_layout->setContentsMargins(5, 5, 5, 5);
            m_layout->setSpacing(5);
            setLayout(m_layout);

            if (functions & CLOSE) {
                m_close = new QPushButton{"⨉", this};
                m_close->setFixedSize(30, 30);
                m_close->setStyleSheet("close");
                m_close->setContentsMargins(0, 0, 0, 0);
                connect(m_close, SIGNAL(QPushButton::clicked), this, SLOT(Log::close));
                m_layout->addWidget(m_close);
            }

            m_label = new QLabel{label, this};
            m_label->setFixedHeight(30);
            m_label->setObjectName("label");
            m_label->setContentsMargins(0, 0, 0, 0);
            m_layout->addWidget(m_label);

            if (functions & COPY) {
                m_copy = new QPushButton{"⧉", this};
                m_copy->setFixedSize(30, 30);
                m_copy->setStyleSheet("copy");
                m_copy->setContentsMargins(0, 0, 0, 0);
                connect(m_copy, SIGNAL(QPushButton::clicked), this, SLOT(Log::copy));
                m_layout->addWidget(m_copy);
            }
        }

        QString QTempInfo::text() {
            return m_label->text();
        }

        void QTempInfo::setText(QString text) {
            m_label->setText(text);
        }

        void QTempInfo::close(void) {
            if (receivers(SIGNAL(closed())) == 0) {
                hide();
            } else {
                emit closed();
            }
        }

        void QTempInfo::copy() {
            QClipboard* clipboard = QApplication::clipboard();

            const char * errorMessage = qPrintable(m_label->text());

            clipboard->setText(errorMessage);
        }
    }
}
