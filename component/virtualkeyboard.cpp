#include "virtualkeyboard.h"

#include <QObject>
#include <qpushbutton.h>
#include <qlayout.h>
#include <QMessageBox>

char VirtualKeyboard::keyCode[VirtualKeyboard::KEY_NUM] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z',
    '\b',
    ' ',
    ' ',
    '\r',
    ' ',
//    KEY_BACK,  //删除
//    KEY_SPACE, //空格
//    KEY_RETURN,//退出
//    KEY_ENTER, //回车
//    KEY_UPPER, //
};

#define  KEY_INTERVAL_COL_WIDTH           10
#define  KEY_INTERVAL_ROW_HEIGHT          5
#define  KEY_TOP_MARGIN                   3
#define  KEY_LEFT_MARGIN                  5
#define  SPECIAL_ROW_OFFSET               35

VirtualKeyboard::VirtualKeyboard(QWidget *parent) : QWidget(parent)//, Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint
{
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框,不可改变大小
//    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setStyleSheet("QPushButton{background-color: rgba(0,0,0,50);    color: rgba(255,255,255,255);   border:1px solid white;}");
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, QColor(50,50,50,255)); //设置背景黑色 Qt::black
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    for (int i = 0; i < KEY_NUM; i++){
        ppbKey[i] = new QPushButton(this);
        ppbKey[i]->setFocusPolicy(Qt::NoFocus);
        ppbKey[i]->setFlat(true);
        ppbKey[i]->setMaximumSize(300,100);
        ppbKey[i]->setMinimumSize(50,50);
        connect(ppbKey[i], SIGNAL(clicked()), this, SLOT(rxClicked()));
    }

    QHBoxLayout *phLayout = new QHBoxLayout;
    QVBoxLayout *pvLayout = new QVBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_1]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_2]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_3]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_4]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_5]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_6]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_7]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_8]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_9]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_0]);
    phLayout->setSpacing(0);

    pvLayout->addSpacing(KEY_TOP_MARGIN);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_Q]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_W]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_E]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_R]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_T]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_Y]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_U]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_I]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_O]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_P]);
    phLayout->setSpacing(0);

    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    //phLayout->addSpacing(SPECIAL_ROW_OFFSET);
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_A]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_S]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_D]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_F]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_G]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_H]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_J]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_K]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_L]);
    //phLayout->addSpacing(SPECIAL_ROW_OFFSET);
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_UPPER]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_Z]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_X]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_C]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_V]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_B]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_N]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_M]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_BACK]);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_RETURN]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_SPACE]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_ENTER]);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);

    pvLayout->setSpacing(0);
    setLayout(pvLayout);

    updateKeyText();
    bUpper=false;
    show();
}


void VirtualKeyboard::rxClicked()
{
    QObject *pObj = sender();//返回发送信号的对象的指针，返回类型为QObject*          =qobject_cast<QTimeEdit *>(sender());
    for (int i = 0; i < KEY_NUM; i++){
        if (ppbKey[i] == pObj){
            if(i==KEY_UPPER){
                bUpper = !bUpper;
                updateAlphaKeyText(bUpper);
            } else{
                get_value(i);
            }
        }
    }
}

#include <QApplication>
#include <QChar>
#include <QKeyEvent>

void VirtualKeyboard::get_value(int i)//QChar character
{
    QWidget *pFocusWidget = QApplication::focusWidget();
    if (pFocusWidget != NULL)
    {
        switch (i)
        {
            case KEY_RETURN://退出
            this->close();
            break;
            case KEY_BACK://删除
            {
                QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, QString());
                QCoreApplication::sendEvent(pFocusWidget, &keyPress);
                QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier, QString());
                QCoreApplication::sendEvent(pFocusWidget, &keyRelease);
            }
            break;
            case KEY_ENTER://回车
            {
                QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, QString());
                QCoreApplication::sendEvent(pFocusWidget, &keyPress);
                QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Enter, Qt::NoModifier, QString());
                QCoreApplication::sendEvent(pFocusWidget, &keyRelease);
            }
            break;
            default://KEY_BACK)//数字 英文     KEY_SPACE://空格
            {
                int keyValue = keyCode[i];
                if ((!bUpper)&&(i>=KEY_A))
                {
                    keyValue += 32;
                }
                QChar ch=keyValue;
                QKeyEvent keyPress(QEvent::KeyPress, ch.unicode(), Qt::NoModifier, QString(ch));
                QCoreApplication::sendEvent(pFocusWidget, &keyPress);
                QKeyEvent keyRelease(QEvent::KeyRelease, ch.unicode(), Qt::NoModifier, QString());
                QCoreApplication::sendEvent(pFocusWidget, &keyRelease);
            }
            break;
        }
    }
}



void VirtualKeyboard::updateAlphaKeyText(bool bUpper)
{
    if (bUpper)
    {
        ppbKey[KEY_A]->setText(QString("A"));
        ppbKey[KEY_B]->setText("B");
        ppbKey[KEY_C]->setText("C");
        ppbKey[KEY_D]->setText("D");
        ppbKey[KEY_E]->setText("E");
        ppbKey[KEY_F]->setText("F");
        ppbKey[KEY_G]->setText("G");
        ppbKey[KEY_H]->setText("H");
        ppbKey[KEY_I]->setText("I");
        ppbKey[KEY_J]->setText("J");
        ppbKey[KEY_K]->setText("K");
        ppbKey[KEY_L]->setText("L");
        ppbKey[KEY_M]->setText("M");
        ppbKey[KEY_N]->setText("N");
        ppbKey[KEY_O]->setText("O");
        ppbKey[KEY_P]->setText("P");
        ppbKey[KEY_Q]->setText("Q");
        ppbKey[KEY_R]->setText("R");
        ppbKey[KEY_S]->setText("S");
        ppbKey[KEY_T]->setText("T");
        ppbKey[KEY_U]->setText("U");
        ppbKey[KEY_V]->setText("V");
        ppbKey[KEY_W]->setText("W");
        ppbKey[KEY_X]->setText("X");
        ppbKey[KEY_Y]->setText("Y");
        ppbKey[KEY_Z]->setText("Z");
        ppbKey[KEY_UPPER]->setText("大写");
    }
    else
    {
        ppbKey[KEY_A]->setText("a");
        ppbKey[KEY_B]->setText("b");
        ppbKey[KEY_C]->setText("c");
        ppbKey[KEY_D]->setText("d");
        ppbKey[KEY_E]->setText("e");
        ppbKey[KEY_F]->setText("f");
        ppbKey[KEY_G]->setText("g");
        ppbKey[KEY_H]->setText("h");
        ppbKey[KEY_I]->setText("i");
        ppbKey[KEY_J]->setText("j");
        ppbKey[KEY_K]->setText("k");
        ppbKey[KEY_L]->setText("l");
        ppbKey[KEY_M]->setText("m");
        ppbKey[KEY_N]->setText("n");
        ppbKey[KEY_O]->setText("o");
        ppbKey[KEY_P]->setText("p");
        ppbKey[KEY_Q]->setText("q");
        ppbKey[KEY_R]->setText("r");
        ppbKey[KEY_S]->setText("s");
        ppbKey[KEY_T]->setText("t");
        ppbKey[KEY_U]->setText("u");
        ppbKey[KEY_V]->setText("v");
        ppbKey[KEY_W]->setText("w");
        ppbKey[KEY_X]->setText("x");
        ppbKey[KEY_Y]->setText("y");
        ppbKey[KEY_Z]->setText("z");
        ppbKey[KEY_UPPER]->setText("小写");
    }
}

void VirtualKeyboard::updateKeyText()
{
    updateAlphaKeyText(false);
    ppbKey[KEY_0]->setText("0");
    ppbKey[KEY_1]->setText("1");
    ppbKey[KEY_2]->setText("2");
    ppbKey[KEY_3]->setText("3");
    ppbKey[KEY_4]->setText("4");
    ppbKey[KEY_5]->setText("5");

    ppbKey[KEY_6]->setText("6");
    ppbKey[KEY_7]->setText("7");
    ppbKey[KEY_8]->setText("8");
    ppbKey[KEY_9]->setText("9");
    ppbKey[KEY_BACK]->setText("删除");
    ppbKey[KEY_ENTER]->setText("确定");
    ppbKey[KEY_SPACE]->setText("空格");
    ppbKey[KEY_RETURN]->setText("退出");
}

