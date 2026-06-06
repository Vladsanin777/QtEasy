#pragma once

#include <QImage>
#include <QPoint>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <QRectF>
#include <QQuickItem>
#include <QQuickPaintedItem>

namespace QtEasy {
    namespace Widgets {
        class QPaintArea : public QQuickPaintedItem {
            Q_OBJECT
            QML_ELEMENT

        private:
            QImage m_image;
            QPoint m_lastPoint;
            bool m_drawing;
            QPen m_pen;

        public:
            QPaintArea(QQuickItem * parent = nullptr);

            void paint(QPainter * painter) override;

        protected:
            void mousePressEvent(QMouseEvent * event) override;

            void mouseMoveEvent(QMouseEvent * event) override;

            void mouseReleaseEvent(QMouseEvent * event) override;

            void geometryChange(const QRectF & newGeometry,
                    const QRectF & oldGeometry) override;

        private:
            void drawLineTo(const QPoint & endPoint);
        };
    }
}
