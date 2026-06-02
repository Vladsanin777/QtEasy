#include <QtEasy/Widgets/QTempInfo.hpp>

namespace QtEasy {
    namespace Widgets {
        QTempInfo::QTempInfo(QWidget * parent) :
                QTempInfo{QString{}, parent} {}

        QTempInfo::QTempInfo(QString label, QWidget * parent) :
                QTempInfo{label, CLOSE | COPY, parent} {}

        QTempInfo::QTempInfo(QString label, int functions,
                QWidget * parent) : QWidget{parent} {
            setContentsMargins(0, 0, 0, 0);
            setFixedHeight(30);

            m_layout = new QHBoxLayout{this};
            m_layout->setSpacing(5);
            m_layout->setContentsMargins(0, 0, 0, 0);

            if (functions & CLOSE) {
                m_close = new QPushButton{"⨉", this};
                m_close->setFixedSize(30, 30);
                m_close->setStyleSheet("close");
                m_close->setContentsMargins(0, 0, 0, 0);
                connect(m_close, &QPushButton::clicked, this, &QTempInfo::close);
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
                connect(m_copy, &QPushButton::clicked, this, &QTempInfo::copy);
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

            const char * tempInfo = qPrintable(m_label->text());

            clipboard->setText(tempInfo);
        }

        void QTempInfo::paintEvent(QPaintEvent *event) {
            QStyleOption opt = QStyleOption{};
            opt.initFrom(this);
            QPainter p(this);
            style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        }
    }
}
