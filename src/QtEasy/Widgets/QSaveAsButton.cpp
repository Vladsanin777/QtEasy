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
                QFileOperationButton{text, extention, directory, this} {
            setFixedSize(30, 30);
        }

        void QSaveAsButton::write(QString text) {
            if (isFilePath()) {
                QFile file(filePath());
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    out << text;
                }
            }
        }

        void QSaveAsButton::askUser(void) {
            QString filePath = QFileDialog::getSaveFileName(
                    this, info(), directory(), extention());
            
            setFilePath(filePath);
        }
    }
}
