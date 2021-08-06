#ifndef MONGRAPHE_H
#define MONGRAPHE_H

#include <QWidget>
#include "qcustomplot.h"

class MonGraphe
{
public:
    MonGraphe(QCustomPlot *customPlot, bool darkmode, int nbgraphs, QString sfirst, QString ssecond, QString sthird, int ifirst, int isecond, int ithird);
};

#endif // MONGRAPHE_H
