#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPen>
#include <QWidget>


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    RenderArea(QWidget * parent = nullptr);
};

#endif // RENDERAREA

