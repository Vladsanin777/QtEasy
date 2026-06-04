#include <QtEasy/Widgets/QFilesOperations.hpp>


namespace QtEasy {
    namespace Widgets {
        QFilesOperations::QFilesOperations(QWidget * parent) :
                QFilesOperations{QString{}, QString{}, QString{}, parent} {}

        QFilesOperations::QFilesOperations(QString captionOpen,
                QString captionSave, QString captionSaveAs, QWidget * parent) :
                QWidget{captionOpen, captionSave, captionSaveAs, parent} {}

        QFilesOperations::QFilesOperations(QString captionOpen,
                QString captionSave, QString captionSaveAs,
                QString extention, QWidget * parent) :
                QSaveButton{text, extention, QString{}, parent} {}

        QFilesOperations::QFilesOperations(QString captionOpen,
                QString captionSave, QString captionSaveAs,
                QString extention, QString directory,
                QWidget * parent) : QWidget{parent} {
            m_open = new QOpenButton{captionOpen, extention, directory, this};
            m_save = new QSaveButton{captionSave, extention, directory, this};
            m_saveAs = new QSaveAsButton{captionSaveAs, extention, directory, this};

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
            emit opened();
        }

        void QFilesOperations::onClickSave(void) {
            QString filePath = m_save->filePath();
            m_open->setFilePath(filePath);
            m_saveAs->setFilePath(filePath);
            emit saved();
        }

        void QFilesOperations::onClickSaveAs(void) {
            QString filePath = m_saveAs->filePath();
            m_open->setFilePath(filePath);
            m_save->setFilePath(filePath);
            emit saved();
        }

        void QFilesOperations::setSpacing(int space) {
            m_layout->setSpacing(space);
        }

        int QFilesOperations::spacing(void) {
            return m_layout->spacing();
        }
    }
}
