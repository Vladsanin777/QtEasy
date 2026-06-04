#include <QtEasy/Widgets/QOpenButton.hpp>

namespace QtEasy {
    namespace Widgets {
        QOpenButton::QOpenButton(QWidget * parent) :
                QOpenButton{QString{}, parent} {}

        QOpenButton::QOpenButton(QString text, QWidget * parent) :
                QOpenButton{text, QString{}, parent} {}

        QOpenButton::QOpenButton(QString text, QString extention, QWidget * parent) :
                QOpenButton{text, extention, QString{}, parent} {}

        QOpenButton::QOpenButton(QString text, QString extention,
                QString directory, QWidget * parent) :
                QFileOperationButton{"🗁", text, extention, directory, this} {
            setFixedSize(30, 30);
        }

        QString QOpenButton::getFilePath(void) {
            return m_filePath;
        }

        QString QOpenButton::read(void) {
            if (!m_filePath.isEmpty()) {
                QFile file(m_filePath);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&file);
                    return in.readAll();
                }
            }
            return QString{};
        }

        void QOpenButton::mouseReleaseEvent(QMouseEvent *event) {
            if (m_filePath.isEmpty()) {
                m_filePath = QFileDialog::getOpenFileName(
                        this, getInfo(), getDirectory(), getExtention());
            }
            
            if (!m_filePath.isEmpty()) {
                QPushButton::mouseReleaseEvent(event); 
            }
        }
    }
}
