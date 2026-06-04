#include <QtEasy/Widgets/QFilesOperations.hpp>


namespace QtEasy {
    namespace Widgets {
        class QFilesOperations : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QOpenButton * m_open{nullptr};
            QSaveButton * m_save{nullptr};
            QSaveAsButton * m_saveAs{nullptr};

        public:
            QFilesOperations::QFilesOperations(QWidget * parent) :
                    QSaveButton{QString{}, parent} {}

            QFilesOperations::QFilesOperations(QString text,
                    QWidget * parent) : QSaveButton{text, QString{}, parent} {}

            QFilesOperations::QFilesOperations(QString text,
                    QString extention, QWidget * parent) :
                    QSaveButton{text, extention, QString{}, parent} {}

            QFilesOperations::QFilesOperations(QString text,
                    QString extention, QString directory,
                    QWidget * parent) : QWidget{parent} {
                m_open = new QOpenButton{text, extention, directory, this};
                m_save = new QSaveButton{text, extention, directory, this};
                m_saveAs = new QSaveAsButton{text, extention, directory, this};

                m_layout = new QHBoxLayout{this};

                m_layout->addWidget(m_open);
                m_layout->addWidget(m_save);
                m_layout->addWidget(m_saveAs);
                
                setLayout(m_layout);

                connect(m_open, &QPushButton::clicked, this, &QFilesOperations::onClickOpen)
                connect(m_save, &QPushButton::clicked, this, &QFilesOperations::onClickSave)
                connect(m_saveAs, &QPushButton::clicked, this, &QFilesOperations::onClickSaveAs)
            }

            void QFilesOperations::onClickOpen(void) {
                QString filePath = m_open->filePath();
                m_save->setFilePath(filePath);
                m_saveAs->setFilePath(filePath);
            }

            void QFilesOperations::onClickSave(void) {
                QString filePath = m_save->filePath();
                m_open->setFilePath(filePath);
                m_saveAs->setFilePath(filePath);
            }

            void QFilesOperations::onClickSaveAs(void) {
                QString filePath = m_saveAs->filePath();
                m_open->setFilePath(filePath);
                m_save->setFilePath(filePath);
            }

            void QFilesOperations::setSpacing(int space) {
                m_layout->setSpacing(space);
            }

            int QFilesOperations::spacing(void) {
                return m_layout->spacing();
            }
        };
    }
}
