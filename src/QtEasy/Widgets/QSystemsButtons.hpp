#pragma once

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QPushButton>


namespace QtEasy {
    namespace Widgets {
        class QSystemsButtons : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QPushButton * m_min{nullptr};
            QPushButton * m_max{nullptr};
            QPushButton * m_close{nullptr};

        public:
            enum Functions {
                NONE = 0,
                MIN = 1,
                MAX = 2,
                CLOSE = 4,
            };

            QSystemsButtons(QWidget * parent = nullptr);

            QSystemsButtons(int functions = {MIN | MAX | CLOSE},
                    QWidget * parent = nullptr);
        };
    }
}
