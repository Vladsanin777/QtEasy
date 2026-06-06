#include <QtEasy/Widgets/QPaintArea.hpp>


namespace QtEasy {
    namespace Widgets {
        QPaintArea::QPaintArea(QQuickItem *parent)
            : QQuickPaintedItem(parent), m_drawing(false) 
        {
            setAcceptedMouseButtons(Qt::LeftButton);
            
            m_pen.setColor(Qt::black);
            m_pen.setWidth(4);
            m_pen.setCapStyle(Qt::RoundCap);
            m_pen.setJoinStyle(Qt::RoundJoin);
        }

        void QPaintArea::geometryChange(
                const QRectF &newGeometry,
                const QRectF &oldGeometry) {
            QQuickPaintedItem::geometryChange(newGeometry, oldGeometry);
            
            if (m_image.size() != newGeometry.size().toSize()) {
                QImage newImage(newGeometry.size().toSize(), QImage::Format_ARGB32);
                newImage.fill(Qt::white);
                
                if (!m_image.isNull()) {
                    QPainter p(&newImage);
                    p.drawImage(0, 0, m_image);
                }
                m_image = newImage;
            }
        }

        void QPaintArea::paint(QPainter *painter) {
            painter->drawImage(0, 0, m_image);
        }

        void QPaintArea::mousePressEvent(QMouseEvent *event) {
            if (event->button() == Qt::LeftButton) {
                m_lastPoint = event->position().toPoint();
                m_drawing = true;
            }
        }

        void QPaintArea::mouseMoveEvent(QMouseEvent *event) {
            if ((event->buttons() & Qt::LeftButton) && m_drawing) {
                drawLineTo(event->position().toPoint());
            }
        }

        void QPaintArea::mouseReleaseEvent(QMouseEvent *event) {
            if (event->button() == Qt::LeftButton && m_drawing) {
                drawLineTo(event->position().toPoint());
                m_drawing = false;
            }
        }

        void QPaintArea::drawLineTo(const QPoint &endPoint) {
            QPainter painter(&m_image);
            painter.setPen(m_pen);
            painter.setRenderHint(QPainter::Antialiasing, true);
            
            painter.drawLine(m_lastPoint, endPoint);
            
            m_lastPoint = endPoint;
            
            update(); 
        }
    }
}
