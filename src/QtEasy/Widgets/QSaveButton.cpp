#include <QtEasy/Widgets/QSaveButton.hpp>

namespace QtEasy {
    namespace Widgets {
        QSaveButton::QSaveButton(QWidget * parent) :
                QSaveButton{QString{}, parent} {}

        QSaveButton::QSaveButton(QString caption, QWidget * parent) :
                QSaveButton{caption, QString{}, parent} {}

        QSaveButton::QSaveButton(QString caption, QString extention, QWidget * parent) :
                QSaveButton{caption, extention, QString{}, parent} {}

        QSaveButton::QSaveButton(QString caption, QString extention,
                QString directory, QWidget * parent) :
                QSaveAsButton{caption, extention, directory, parent} {
            setText("🖫");
            setFixedSize(30, 30);
        }

        void QSaveButton::mouseReleaseEvent(QMouseEvent * event) {
            if (!isFilePath()) {
                askUser();
            }
            
            if (isFilePath()) {
                emit clicked();
            }
        }
    }
}
