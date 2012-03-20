#include "controlpanel.h"
#include "ui_controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);

    connect(ui->cornersSpinBox, SIGNAL(valueChanged(int)), parent, SLOT(changeCorners(int)));
    connect(ui->rotateSpinBox, SIGNAL(valueChanged(int)), parent, SLOT(changeRotate(int)));
}

ControlPanel::~ControlPanel()
{
    delete ui;
}
