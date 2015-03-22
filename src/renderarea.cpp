#include "includes/renderarea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent):QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(1);
    setMaximumHeight(100);
    setMinimumHeight(100);
}
