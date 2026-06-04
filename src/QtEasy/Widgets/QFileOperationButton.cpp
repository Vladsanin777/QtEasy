#include <QtEasy/Widgets/QFileOperationButton.hpp>


namespace QtEasy {
    namespace Widgets {
        QFileOperationButton::QFileOperationButton(QWidget * parent) :
                QFileOperationButton{QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString label, QWidget * parent) :
                QFileOperationButton{label, QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString label, QString info, QWidget * parent) :
                QFileOperationButton{label, info, QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString label, QString info,
                QString extention, QWidget * parent) :
                QFileOperationButton{label, info, extention, QString{}, parent} {}

        QFileOperationButton::QFileOperationButton(
                QString label, QString info, QString extention,
                QString directory, QWidget * parent) :
                QPushButton{label, this}, m_info{info}, m_extention{extention},
                m_directory{directory} {
            setFixedSize(30, 30);
        }

        QString QFileOperationButton::getInfo(void) {
            return m_info;
        }

        QString QFileOperationButton::getExtention(void) {
            return m_extention;
        }

        QString QFileOperationButton::getDirectory(void) {
            return m_directory;
        }

        void QFileOperationButton::setInfo(QString info) {
            m_info = info;
        }

        void QFileOperationButton::setExtention(QString extention) {
            m_extention = extention;
        }

        void QFileOperationButton::setDirectory(QString directory) {
            m_directory = directory;
        }
    }
}
