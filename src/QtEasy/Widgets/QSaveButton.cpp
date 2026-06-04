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
                QSaveAsButton{text, extention, directory, this} {
            setFixedSize(30, 30);
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
