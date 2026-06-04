#include <QtEasy/Widgets/QSaveAsButton.hpp>

namespace QtEasy {
    namespace Widgets {
        QSaveAsButton::QSaveAsButton(QWidget * parent) :
                QSaveAsButton{QString{}, parent} {}

        QSaveAsButton::QSaveAsButton(QString text, QWidget * parent) :
                QSaveAsButton{text, QString{}, parent} {}

        QSaveAsButton::QSaveAsButton(QString text, QString extention, QWidget * parent) :
                QSaveAsButton{text, extention, QString{}, parent} {}

        QSaveAsButton::QSaveAsButton(QString text, QString extention,
                QString directory, QWidget * parent) :
                QSaveButton{text, extention, directory, this} {
            setFixedSize(30, 30);
        }

        void QSaveAsButton::mouseReleaseEvent(QMouseEvent * event) {
            askUser();
            
            if (isFilePath()) {
                QPushButton::mouseReleaseEvent(event); 
            }
        }
    }
}
