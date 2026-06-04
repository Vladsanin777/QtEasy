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

        QString QOpenButton::read(void) {
            if (isFilePath()) {
                QFile file(filePath());
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&file);
                    return in.readAll();
                }
            }
            return QString{};
        }

        void QOpenButton::askUser(void) {
            QString filePath = QFileDialog::getOpenFileName(
                    this, info(), directory(), extention());

            setFilePath(filePath);
        }
    }
}
