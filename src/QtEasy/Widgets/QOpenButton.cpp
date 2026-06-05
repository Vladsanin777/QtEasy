#include <QtEasy/Widgets/QOpenButton.hpp>

namespace QtEasy {
    namespace Widgets {
        QOpenButton::QOpenButton(QWidget * parent) :
                QOpenButton{QString{}, parent} {}

        QOpenButton::QOpenButton(QString caption, QWidget * parent) :
                QOpenButton{caption, QString{}, parent} {}

        QOpenButton::QOpenButton(QString caption, QString extention, QWidget * parent) :
                QOpenButton{caption, extention, QString{}, parent} {}

        QOpenButton::QOpenButton(QString caption, QString extention,
                QString directory, QWidget * parent) :
                QFileOperationButton{caption, extention, directory, parent} {
            setText("🗁");
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
                    this, caption(), directory(), extention());

            setFilePath(filePath);
        }
    }
}
