#include "func_for_server.h"
#include <QtMath>
QByteArray parsing(QString str)
{
    QStringList params;
    params.clear();
    params = str.split('@');
    QString func_name;
    func_name.clear();
    func_name = params.front();

    params.pop_front();

    if(func_name=="perimetr")
        return perimetr(params);
    else if (func_name == "square")
        return square(params);
    else
        return "Error";
}



QByteArray perimetr(const QStringList& vertices) {
    double perimeter = 0.0;
    QString perimetertxt;

    // Проверяем, что есть хотя бы 3 вершины
    if (vertices.size() < 3) {
        perimetertxt = QString::number(perimeter);
        return perimetertxt.toUtf8();
    }

    QList<QPointF> points;

    // Преобразуем QStringList в список QPointF с координатами вершин
    for (const QString& vertex : vertices) {
        QStringList coordinates = vertex.split(",");
        if (coordinates.size() == 2) {
            bool xOk, yOk;
            double x = coordinates[0].toDouble(&xOk);
            double y = coordinates[1].toDouble(&yOk);
            if (xOk && yOk) {
                points.append(QPointF(x, y));
            }
        }
    }

    // Вычисляем расстояние между каждой парой вершин
    for (int i = 0; i < points.size(); i++) {
        const QPointF& p1 = points[i];
        const QPointF& p2 = points[(i + 1) % points.size()]; // Обрабатываем последнюю вершину, соединяя её с первой

        // Используем формулу расстояния между двумя точками в 2D пространстве
        double distance = qSqrt(qPow(p2.x() - p1.x(), 2) + qPow(p2.y() - p1.y(), 2));
        perimeter += distance;
    }
    perimetertxt = QString::number(perimeter);
    return perimetertxt.toUtf8();
}


QByteArray square(const QStringList& vertices)
{

    // Проверяем, что количество вершин не меньше трёх
    if (vertices.size() < 3) {
        qWarning() << "Недостаточно вершин для вычисления площади";
        return QString("0.0").toUtf8();
    }

    // Создаем массив точек на основе списка вершин
    QVector<QPointF> points;
    for (const QString& vertex : vertices) {
        QStringList coords = vertex.split(",");
        if (coords.size() != 2) {
            qWarning() << "Некорректный формат координат вершины" << vertex;
            return QString("0.0").toUtf8();
        }
        bool xOk, yOk;
        qreal x = coords[0].toDouble(&xOk);
        qreal y = coords[1].toDouble(&yOk);
        if (!xOk || !yOk) {
            qWarning() << "Некорректные значения координат вершины" << vertex;
            return QString("0.0").toUtf8();
        }
        points.append(QPointF(x, y));
    }

    // Вычисляем площадь с использованием формулы Гаусса
    double area = 0.0;
    int numPoints = points.size();
    for (int i = 0; i < numPoints; ++i) {
        const QPointF& p1 = points[i];
        const QPointF& p2 = points[(i + 1) % numPoints];
        area += (p1.x() * p2.y() - p2.x() * p1.y());
    }
    area *= 0.5;
    QString aretxt = QString::number(qAbs(area));
    return aretxt.toUtf8();


}

