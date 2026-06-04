#include <QtEasy/Widgets/QSaveButton.hpp>

namespace QtEasy {
    namespace Widgets {
        QSaveButton::QSaveButton(QWidget * parent) :
                QSaveButton{QString{}, parent} {}

        QSaveButton::QSaveButton(QString text, QWidget * parent) :
                QSaveButton{text, QString{}, parent} {}

        QSaveButton::QSaveButton(QString text, QString extention, QWidget * parent) :
                QSaveButton{text, extention, QString{}, parent} {}

        QSaveButton::QSaveButton(QString text, QString extention,
                QString directory, QWidget * parent) :
                QFileOperationButton{"🖫", text, extention, directory, this} {
            setFixedSize(30, 30);
        }

        QString QSaveButton::getFilePath(void) {
            return m_filePath;
        }

        void QSaveButton::write(QString text) {
            if (!m_filePath.isEmpty()) {
                QFile file(m_filePath);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    out << text;
                }
            }
        }

        void QSaveButton::askUser(void) {
            m_filePath = QFileDialog::getSaveFileName(
                    this, getInfo(), getDirectory(), getExtention());
        }

        bool QSaveButton::isFilePath(void) {
            return !m_filePath.isEmpty();
        }

        void QSaveButton::mouseReleaseEvent(QMouseEvent * event) {
            if (!isFilePath()) {
                askUser();
            }
            
            if (isFilePath()) {
                QPushButton::mouseReleaseEvent(event); 
            }
        }
    }
}
