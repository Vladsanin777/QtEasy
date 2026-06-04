#include <QWidget>
#include <QHBoxLayout>
#include <QtEasy/Widgets/QOpenButton.hpp>
#include <QtEasy/Widgets/QSaveButton.hpp>
#include <QtEasy/Widgets/QSaveAsButton.hpp>


namespace QtEasy {
    namespace Widgets {

        using QtEasy::Widgets::QOpenButton;
        using QtEasy::Widgets::QSaveButton;
        using QtEasy::Widgets::QSaveAsButton;

        class QFilesOperations : public QWidget {
            Q_OBJECT

        private:
            QHBoxLayout * m_layout{nullptr};
            QOpenButton * m_open{nullptr};
            QSaveButton * m_save{nullptr};
            QSaveAsButton * m_saveAs{nullptr};

        public:
            QFilesOperations(QWidget * parent = nullptr) :
                    QWidget{parent} {
                m_open = new QOpenButton{this};
                m_save = new QSaveButton{this};
                m_saveAs = new QSaveAsButton{this};

                m_layout = new QHBoxLayout{this};

                m_layout->addWidget(m_open);
                m_layout->addWidget(m_save);
                m_layout->addWidget(m_saveAs);
                
                setLayout(m_layout);
            }

            void setSpacing(int space) {
                m_layout->setSpacing(space);
            }

            int spacing(void) {
                return m_layout->spacing();
            }
        };
    }
}
