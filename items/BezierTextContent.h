#ifndef __BezierTextContent__
#define __BezierTextContent__

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QFontMetricsF>
#include <QDialog>
#include "AbstractContent.h"


class BezierTextContent : public AbstractContent
{
    private:
        QString m_text;
        QFont m_font;
        QPainterPath m_path;
        QList<QPointF> m_controlPoints;

    public:
        BezierTextContent(QGraphicsScene *scene, QGraphicsItem *parent = 0);
        void setText(const QString &text);
        QString text() const;
        void setFont(const QFont &font);
        QFont font() const;
        void setFontSize(const int size);
        void setPath(const QPainterPath &path);
        void setControlPoints(const QList<QPointF> controlPts);
        QList<QPointF> controlPoints() const;

        void resizeContents(const QRect & rect, bool keepRatio = true);

        // ::AbstractContent
        bool fromXml(QDomElement & parentElement);
        void toXml(QDomElement & parentElement) const;
        //QPixmap renderAsBackground(const QSize & size, bool keepAspect) const;
        // ::QGraphicsItem
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
};

#endif