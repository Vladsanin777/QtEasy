#include <QtEasy/Widgets/QSaveAsButton.hpp>

namespace QtEasy {
    namespace Widgets {
        QSaveAsButton::QSaveAsButton(QWidget * parent) :
                QSaveAsButton{QString{}, parent} {}

        QSaveAsButton::QSaveAsButton(QString caption, QWidget * parent) :
                QSaveAsButton{caption, QString{}, parent} {}

        QSaveAsButton::QSaveAsButton(QString caption,
                QString extention, QWidget * parent) :
                QSaveAsButton{caption, extention, QString{}, parent} {}

        QSaveAsButton::QSaveAsButton(QString caption, QString extention,
                QString directory, QWidget * parent) :
                QFileOperationButton{caption, extention, directory, this} {
            setText("🞢");
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
                    this, caption(), directory(), extention());
            
            setFilePath(filePath);
        }
    }
}
