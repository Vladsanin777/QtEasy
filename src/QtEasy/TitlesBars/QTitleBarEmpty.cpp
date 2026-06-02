#include <QtEasy/TitlesBars/QTitleBarEmpty.hpp>


namespace QtEasy {
    namespace TitlesBars {
        QTitleBarEmpty::QTitleBarEmpty(QWidget * parent) :
                QTitleBarEmpty{QString{}, parent} {}

        QTitleBarEmpty::QTitleBarEmpty(int functions, QWidget * parent) :
                QTitleBarEmpty{QString{}, functions, parent} {}

        QTitleBarEmpty::QTitleBarEmpty(QString title, QWidget * parent) :
                QTitleBarEmpty{title, QSystemsButtons::Functions::MIN |
                    QSystemsButtons::Functions::MAX | 
                    QSystemsButtons::Functions::CLOSE, parent} {}

        QTitleBarEmpty::QTitleBarEmpty(QString title,
                int functions, QWidget * parent) : QWidget{parent} {
            if (QWidget * currentWindow = window()) {
                currentWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                currentWindow->setMouseTracking(true); 
                
                currentWindow->installEventFilter(this);
                currentWindow->show(); 
            }
            setMouseTracking(true); 

            setWindowTitle(title);

            m_layout = new QHBoxLayout{this};
            m_layout->setDirection(QHBoxLayout::RightToLeft);

            m_systemsButtons = new QSystemsButtons{this};
            m_systemsButtons->setObjectName("systemsButtons");

            m_layout->addWidget(m_systemsButtons);
            m_layout->addStretch();
        }

        QString QTitleBarEmpty::text(void) {
            return window()->windowTitle();
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

        void QTitleBarEmpty::mousePressEventWindow(QMouseEvent *event) {
            QWindow * win = window()->windowHandle();
            if (event->button() == Qt::LeftButton) {
                if (m_resizeEdge != 0) {
                    if (win) {
                        win->startSystemResize(m_resizeEdge);
                        event->accept();
                        return;
                    }
                }
            
                if (win) {
                    win->startSystemMove();
                    event->accept();
                    return;
                }
            }

            QWidget::mousePressEvent(event);
        }

        void QTitleBarEmpty::mouseDoubleClickEvent(QMouseEvent *event) {
            if (event->button() == Qt::LeftButton) {
                QWidget * currentWindow = window();
                if (currentWindow->isMaximized()) {
                    currentWindow->showNormal();
                } else {
                    currentWindow->showMaximized();
                }
                event->accept();
            } else {
                QWidget::mouseDoubleClickEvent(event);
            }
        }

        bool QTitleBarEmpty::eventFilter(QObject *watched, QEvent *event) {
            if (watched == window()) {
                if (event->type() == QEvent::MouseMove) {
                    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                    
                    mouseMoveEventWindow(mouseEvent);
                } else if (event->type() == QEvent::MouseButtonPress) {
                    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                    
                    mousePressEventWindow(mouseEvent);
                }
            }
            
            return QWidget::eventFilter(watched, event);
        }

        void QTitleBarEmpty::mouseMoveEventWindow(QMouseEvent *event) {
            QPoint pos = event->position().toPoint();
            QWidget * currentWindow = window();

            m_resizeEdge = Qt::Edges{};

            if (pos.x() < m_borderWidth) {
                m_resizeEdge |= Qt::LeftEdge;
            }

            if (pos.x() > currentWindow->width() - m_borderWidth) {
                m_resizeEdge |= Qt::RightEdge;
            }

            if (pos.y() < m_borderWidth) {
                m_resizeEdge |= Qt::TopEdge;
            }

            if (pos.y() > currentWindow->height() - m_borderWidth) {
                m_resizeEdge |= Qt::BottomEdge;
            }

            if ((m_resizeEdge & Qt::LeftEdge && m_resizeEdge & Qt::TopEdge) \
                    || (m_resizeEdge & Qt::RightEdge && m_resizeEdge & Qt::BottomEdge)) {
                currentWindow->setCursor(Qt::SizeFDiagCursor);
            } else if ((m_resizeEdge & Qt::RightEdge && m_resizeEdge & Qt::TopEdge) \
                    || (m_resizeEdge & Qt::LeftEdge && m_resizeEdge & Qt::BottomEdge)) {
                currentWindow->setCursor(Qt::SizeBDiagCursor);
            } else if (m_resizeEdge & Qt::LeftEdge || m_resizeEdge & Qt::RightEdge) {
                currentWindow->setCursor(Qt::SizeHorCursor);
            } else if (m_resizeEdge & Qt::TopEdge || m_resizeEdge & Qt::BottomEdge) {
                currentWindow->setCursor(Qt::SizeVerCursor);
            } else {
                currentWindow->setCursor(Qt::ArrowCursor);
            }

            QWidget::mouseMoveEvent(event);
        }
    }
}
