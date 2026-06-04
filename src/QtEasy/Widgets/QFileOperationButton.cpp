#include <QtEasy/Widgets/QFileOperationButton.hpp>


namespace QtEasy {
    namespace Widgets {
        QFileOperationButton::QFileOperationButton(QWidget * parent) :
                QFileOperationButton{QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString caption, QWidget * parent) :
                QFileOperationButton{caption, QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString caption, QString extention, QWidget * parent) :
                QFileOperationButton{caption, extention, QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString caption, QString extention,
                QString directory, QWidget * parent) :
                QPushButton{this}, m_caption{caption}, m_extention{extention},
                m_directory{directory} {
            setFixedSize(30, 30);
        }

        bool QFileOperationButton::isFilePath(void) {
            return !m_filePath.isEmpty();
        }

        QString QFileOperationButton::filePath(void) {
            return m_filePath;
        }

        QString QFileOperationButton::caption(void) {
            return m_caption;
        }

        QString QFileOperationButton::extention(void) {
            return m_extention;
        }

        QString QFileOperationButton::directory(void) {
            return m_directory;
        }

        void QFileOperationButton::setFilePath(QString filePath) {
            m_filePath = filePath;
        }

        void QFileOperationButton::setCaption(QString caption) {
            m_caption = caption;
        }

        void QFileOperationButton::setExtention(QString extention) {
            m_extention = extention;
        }

        void QFileOperationButton::setDirectory(QString directory) {
            m_directory = directory;
        }

        void QFileOperationButton::mouseReleaseEvent(QMouseEvent *event) {
            askUser();
            
            if (isFilePath()) {
                QPushButton::mouseReleaseEvent(event); 
            }
        }
    }
}
