#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPen>
#include <QWidget>
#include <QtWidgets>


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    RenderArea(QWidget * parent = nullptr);
private:
    QGraphicsScene *scene;
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

};

#endif // RENDERAREA

