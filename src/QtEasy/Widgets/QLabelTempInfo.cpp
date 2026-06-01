#include <QtEasy/Widgets/QLabelTempInfo.hpp>


namespace QtEasy {
    namespace Widgets {
        QLabelTempInfo::QLabelTempInfo(
                QWidget * parent) : QLabelTempInfo{LABEL, parent} {}

        QLabelTempInfo::QLabelTempInfo(
                Mode mode, QWidget * parent) :
                    QLabelTempInfo{QString{}, mode, parent} {}

        QLabelTempInfo::QLabelTempInfo(
                QString label, QWidget * parent) :
                    QLabelTempInfo{label, QString{}, 
                        QLabelTempInfo::Mode::LABEL, parent} {}

        QLabelTempInfo::QLabelTempInfo(
                QString label, Mode mode, QWidget * parent) :
                    QLabelTempInfo{label, QString{}, mode, parent} {}

        QLabelTempInfo::QLabelTempInfo(
                QString label, QString tempInfo, QWidget * parent) :
                    QLabelTempInfo{label, tempInfo, 
                        QLabelTempInfo::Mode::LABEL, parent} {}

        QLabelTempInfo::QLabelTempInfo(QString label, QString tempInfo,
                Mode mode, QWidget * parent) : QWidget{parent} {
            m_label = new QLabel{label, this};
            m_label->setObjectName("label");

            m_tempInfo = new QTempInfo{tempInfo, this};
            m_tempInfo->setObjectName("tempInfo");
            
            connect(m_tempInfo, SIGNAL(Log::closed), this, SLOT(TitleOrLog::title));
            setMode(mode);
        }

        QLabelTempInfo::Mode QLabelTempInfo::mode(void) {
            return m_mode;
        }

        QString QLabelTempInfo::tempInfo(void) {
            return m_tempInfo->text();
        }

        QString QLabelTempInfo::text(void) {
            return m_label->text();
        }

        void QLabelTempInfo::setMode(Mode mode) {
            switch (mode) {
                case LABEL:
                    switchLabel();
                    break;
                case TEMP_INFO:
                    switchTempInfo();
                    break;
                default:
                    return;
            }
            m_mode = mode;
        }

        void QLabelTempInfo::switchLabel(void) {
            m_label->show();
            m_tempInfo->hide();
            m_mode = LABEL;
        }

        void QLabelTempInfo::switchTempInfo(void) {
            m_label->hide();
            m_tempInfo->show();
            m_mode = TEMP_INFO;
        }

        void QLabelTempInfo::setTempInfo(QString text) {
            m_tempInfo->setText(text);
        }

        void QLabelTempInfo::setText(QString text) {
            m_label->setText(text);
        }
    }
}
